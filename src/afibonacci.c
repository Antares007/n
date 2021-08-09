#include "aradani.h"
#include "orgs.h"
#include <stdio.h>
#include <stdlib.h>
S(printfQQ);
S(rotate3);
S(drop);
S(swap);
Sar(fibonacci_next, R(Q_t, c); R(Q_t, p); R(Q_t, n);
    An(Q_t, n - 1, c, c + p) A(n_t, n ? fibonacci_next : O(0)));
Nar(fibonacci,
    An(Q_t, 0, 1) An(n_t, fibonacci_next, rotate3, an, drop, an, swap, an));
Main((1 << 13), malloc, free,
     An(n_t, printfQQ) P A(Q_t, 50) A(n_t, fibonacci) C);
Sar(rotate3, R(Q_t, c); R(Q_t, b); R(Q_t, a); An(Q_t, b, c, a) A(n_t, O(0)));
Sar(drop, R(Q_t, a); ((void)a); A(n_t, O(0)));
Sar(swap, R(void *, a); R(void *, b); An(vs, a, b) A(n_t, O(0)));
S(printfQQ) {
  R(Q_t, b);
  R(Q_t, a);
  printf("%lu %lu\n", a, b);
}
