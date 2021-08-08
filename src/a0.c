#include "aradani.h"
#include "orgs.h"
#include <stdio.h>
#include <stdlib.h>
N(da_puts) {
  R(int, v);
  printf("da: %d", v);
}
N(an_puts) { puts("an"); }
N(ara_puts) { puts("ara"); }
Nar(one, _(int, 1) _(n_t, O(1)));
Nar(add, R(int, r); R(int, l); _(int, l + r) _(n_t, O(1)));
Nar(two, _n(n_t, one, one, da, add, da));
Nar(seven, _n(n_t, one, two, da, add, da, two, da, add, da, two, da, add, da));
Main((10 << 12), malloc, free, _n(n_t, seven, an_puts, da_puts, ara_puts) PPP C)
