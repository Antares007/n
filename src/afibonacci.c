#include "aradani.h"
#include "ints.h"
#include <stdio.h>
#include <stdlib.h>
Sar(fibonacci_next, R(Q_t, c); R(Q_t, p); R(Q_t, n);
                    A3(Q_t, n - 1, c, c + p) A(n_t, n ? fibonacci_next : O(0)))
S(rotate3);
S(drop);
S(swap);
Nar(fibonacci,      A2(Q_t, 0, 1) A7(n_t, fibonacci_next, rotate3, an, drop, an, swap, an))
S(printfQQ);
Main(               (1 << 12), malloc, free,
                    A(n_t, printfQQ) P A(Q_t, 50) A(n_t, fibonacci) C)
Sar(rotate3,        R(Q_t, c); R(Q_t, b); R(Q_t, a);
                    A3(Q_t, b, c, a) A(n_t, O(0)))
Sar(drop,           R(Q_t, a); ((void)a);
                    A(n_t, O(0)))
Sar(swap,           R(void *, a); R(void *, b);
                    A2(void*, a, b) A(n_t, O(0)))
S(printfQQ)         { R(Q_t, b); R(Q_t, a); printf("%lu %lu\n", a, b); }
