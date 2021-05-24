#define IMP
#include "pith.h"
#include <stdio.h>
void *malloc(unsigned long);
void free(void *);

typedef void (*nargo_t)(nt *, void *, void *);

#define MB(...)                                                                \
  {                                                                            \
    void *_advance = advance;                                                  \
    __VA_ARGS__;                                                               \
    if (_advance < advance) {                                                  \
    }                                                                          \
  }
nargo(eval) {
  parg(nargo_t, nar);
  nar(o, begin, advance);
}

nargo(r0) { o[0]((void *)o, begin, advance); }
nargo(r1) { o[1]((void *)o, begin, advance); }
nargo(one) { C(o[0], o, arg(int, 1)); }
nargo(two) { C(o[0], o, arg(int, 2)); }
#define nexp(n, ...)

#define narg(T, a) (*(T *)advance = a, advance += sizeof(T))
//  gcd(x, y) = lt(x,y)₁gcd(x,y-x)₀(lt(y, x)₁gcd(x-y,y))₀r1(x)
//  gcd(18, 12)
//  lt(18,  12) ₁ gcd(18, -6) ₀ ( lt(12, 18) ₁ gcd(6,  12) ) ₀ r1(18)
//  lt(6,   12) ₁ gcd(6,   6) ₀ ( lt(12,  6) ₁ gcd(-6, 12) ) ₀ r1( 6)
//  lt(6,    6) ₁ gcd(6,   0) ₀ ( lt(6,   6) ₁ gcd(0,   6) ) ₀ r1( 6)
//  function gcd(o, b, a) {
//    const y = b[--a];
//    const x = b[--a];
//    sexp(o, b, a, [
//      0,
//      [1, [8, x, y, lt], [8, x, y - x, gcd]],
//      [1, [8, y, x, lt], [8, x - y, y, gcd]],
//      [8, x, r1],
//    ]);
//  }
#define Mb2(op, a, b)
#define Mb3(op, a, b, c)
#define Eval                                                                   \
  {                                                                            \
    parg(nargo_t, nar);                                                        \
    nar(o, begin, advance);                                                    \
  }
nargo(gcd) {
  parg(int, y);
  parg(int, x);
  Mb3(0,                                       //
      Mb2(1, B3(x, y, lt), B3(x, y - x, gcd)), //
      Mb2(1, B3(y, x, lt), B3(x - y, y, gcd)), //
      B2(x, r1)                                //
  );
}

nargo(example) {
  narg(nargo_t, two);
  Eval;
}
int main() {
  void *stack = malloc(4096);
  void *begin = stack;
  void *advance = begin;
  void *o[] = {hexdump, hexdump};
  example((void *)o, begin, advance);

  printf("%p\n", (void *)0);
}
/*
erti = 1.
Sekribe2 a b = C("da", a + b)
ori = Sekribe erti, ori, sami an nuli.
*/
