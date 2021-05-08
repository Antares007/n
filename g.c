#include "args.h"
#define IMP
#include "pith.h"

static nargo(c3_2) { C0(o[3], o[2]); }
static nargo(c21_2) { C0(((nt **)o)[2][1], o[2]); }
static nargo(c20_2) { C0(((nt **)o)[2][0], o[2]); }
static nargo(ma) {
  parg(nt, a);
  parg(nt, m);
  void *oa[] = {c3_2, c21_2, o, a};
  C0(m, oa);
}
static nargo(mb) {
  parg(nt, b);
  parg(nt, m);
  void *ob[] = {c20_2, c3_2, o, b};
  C0(m, ob);
}
static nargo(nar) {
  parg(nt, nar);
  C0(nar, o);
}

#define V(n, ...)                                                              \
  nargo(n) { C(nar, o, args(nt, __VA_ARGS__)); }

#define Vrange(n, f, t)                                                        \
  nargo(n) {                                                                   \
    parg(char *, in);                                                          \
    parg(int, pos);                                                            \
    if (in[pos] < f || t < in[pos]) {                                          \
      C(o[1], o, arg(int, pos), arg(char *, in));                              \
    } else {                                                                   \
      C(o[0], o, arg(char, in[pos]), arg(int, pos + 1), arg(char *, in));      \
    }                                                                          \
  }

#define Vcp(n, c)                                                              \
  nargo(n) {                                                                   \
    parg(char *, in);                                                          \
    parg(int, pos);                                                            \
    if (in[pos] == c) {                                                        \
      C(o[0], o, arg(char, in[pos]), arg(int, pos + 1), arg(char *, in));      \
    } else {                                                                   \
      C(o[1], o, arg(int, pos), arg(char *, in));                              \
    }                                                                          \
  }

nargo(ε) { C0(o[0], o); }
nargo(_add) {
  parg(char *, in);
  parg(int, pos);
  parg(int, r);
  parg(char, op);
  parg(int, l);
  C(o[0], o, arg(int, l + r), arg(int, pos), arg(char *, in));
}
nargo(_mul) {
  parg(char *, in);
  parg(int, pos);
  parg(int, r);
  parg(char, op);
  parg(int, l);
  C(o[0], o, arg(int, (l * r)), arg(int, pos), arg(char *, in));
}
nargo(_ds) {
  parg(char *, in);
  parg(int, pos);
  parg(char, c);
  C(o[0], o, arg(int, c - 0x30), arg(int, pos), arg(char *, in));
}
nargo(_31) {
  parg(char *, in);
  parg(int, pos);
  parg(char, r);
  parg(int, v);
  parg(char, l);
  C(o[0], o, arg(int, v), arg(int, pos), arg(char *, in));
}

Vrange(decsym, '0', '9');
Vcp(openParen, '(');
Vcp(closeParen, ')');
Vcp(star, '*');
Vcp(plus, '+');

nargo(E);
V(ds, decsym, _ds, ma);
V(F, openParen, E, ma, closeParen, ma, _31, ma, ds, mb);

nargo(T);
V(T1, star, T, ma, _mul, ma, ε, mb);
V(T, F, T1, ma);

V(E1, plus, E, ma, _add, ma, ε, mb);
V(E, T, E1, ma);

Vcp(b, 'b');
Vcp(a, 'a');
V(as, a, as, ma);
V(S, b, as, ma);
nargo(example) {
  C(S, o, arg(int, 0), arg(char *, "baaaaaa"));
  C(E, o, arg(int, 0), arg(char *, "(3+6)*9"));
}
int main() {
  Ma(1 << 12, {
    void *o[] = {hexdump, hexdump};
    C(example, o);
  });
}
