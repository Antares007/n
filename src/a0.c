#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>
N(da_puts) { R(int, v); printf("da: %d", v); }
N(an_puts) { puts("an"); }
N(ara_puts) { puts("ara"); }
Nar(one, A(int, 1) A(n_t, O(1)))
Nar(add, R(int, r); R(int, l); A(int, l + r) A(n_t, O(1)))
Nar(two, A5(n_t, one, one, da, add, da))
Nar(seven, A13(n_t, one, two, da, add, da, two, da, add, da, two, da, add, da))
Nar(fourteen, A5(n_t, seven, seven, da, add, da))
Main((10 << 12), malloc, free, A4(n_t, fourteen, an_puts, da_puts, ara_puts) PPP C)
