#include "args.h"
#define IMP
#include "pith.h"

nargo(nar) {
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
  ((void)op);
  C(o[0], o, arg(int, l + r), arg(int, pos), arg(char *, in));
}
nargo(_mul) {
  parg(char *, in);
  parg(int, pos);
  parg(int, r);
  parg(char, op);
  parg(int, l);
  ((void)op);
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
  ((void)r, (void)l);
  C(o[0], o, arg(int, v), arg(int, pos), arg(char *, in));
}

Vrange(decsym, '0', '9');
Vcp(openParen, '(');
Vcp(closeParen, ')');
Vcp(star, '*');
Vcp(plus, '+');

nargo(E);
V(ds, decsym, _ds, mb0);
V(F, openParen, E, mb0, closeParen, mb0, _31, ds, mb01);

nargo(T);
V(T1, star, T, mb0, _mul, ε, mb01);
V(T, F, T1, mb0);

V(E1, plus, E, mb0, _add, ε, mb01);
V(E, T, E1, mb0);

Vcp(b, 'b');
Vcp(a, 'a');
V(as, a, as, ε, mb01);
V(S, b, as, mb0);
nargo(rm) {
  parg(char *, in);
  parg(int, pos);
  ((void)in, (void)pos);
  C0(o[0], o);
}
nargo(example) {
  C(nar, o, arg(int, 0), arg(char *, "baaaaaa"), args(nt, S, rm, mb0));
  C(nar, o, arg(int, 0), arg(char *, "(3+6)*9"), args(nt, E, rm, mb0));
}
int main() {
  Ma(1 << 12, {
    void *o[] = {hexdump, hexdump};
    C(example, o);
  });
}
