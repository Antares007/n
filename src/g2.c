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
#define და(a, ...)
#define ან(a, ...)
#define პ parg
#define ნ nargo
#define ნატ int
#define ნარ nargo_t
#define ა(T, n)
#define ბ(...)

#define Eval                                                                   \
  {                                                                            \
    parg(nargo_t, nar);                                                        \
    nar(o, begin, advance);                                                    \
  }

ნ(gcd) {
  პ(ნატ, y);
  პ(ნატ, x);
  ან(და(ბ(x, y, lt), ბ(x, y - x, gcd)), //
     და(ბ(y, x, lt), ბ(x - y, y, gcd)), //
     ბ(x, r1)                           //
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
