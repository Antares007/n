#include "aradani.h"
#include "orgs.h"
#include <stdio.h>
#include <stdlib.h>
S(printfQQ);
S(rotate3);
S(drop);
S(swap);
Sar(fibonacci_next, R(Q_t, c); R(Q_t, p); R(Q_t, n);
    _n(Q_t, n - 1, c, c + p) _(n_t, n ? fibonacci_next : O(0)));
Nar(fibonacci,
    _n(Q_t, 0, 1) _n(n_t, fibonacci_next, rotate3, an, drop, an, swap, an));
Main((1 << 13), malloc, free,
     _n(n_t, printfQQ) P _(Q_t, 50) _(n_t, fibonacci) C);
Sar(rotate3, R(Q_t, c); R(Q_t, b); R(Q_t, a); _n(Q_t, b, c, a) _(n_t, O(0)));
Sar(drop, R(Q_t, a); ((void)a); _(n_t, O(0)));
Sar(swap, R(void *, a); R(void *, b); _n(vs, a, b) _(n_t, O(0)));
S(printfQQ) {
  R(Q_t, b);
  R(Q_t, a);
  printf("%lu %lu\n", a, b);
}
