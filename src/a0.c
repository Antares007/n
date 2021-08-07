#include "aradani.h"
#include <stdio.h>

N(da_puts) {
  R(int, v);
  printf("da: %d", v);
}
N(an_puts) { puts("an"); }
N(ara_puts) { puts("ara"); }

N(an_bma) { Obr(n_t, 0)(T); }
N(da_bma) { Obr(n_t, 1)(T); }
N(ara_bma) { Obr(n_t, 2)(T); }
#include <stdlib.h>

N(one) { A(int, 1), Obr(n_t, 1)(T); }
N(add) {
  R(int, r);
  R(int, l);
  A(int, l + r), Obr(n_t, 1)(T);
}
N(two) { AAAAA(n_t, one, one, da, add, da), C; }

Main((10 << 12), malloc, free,             //
     OOO(n_t, an_puts, da_puts, ara_puts), //
     AAA(n_t, one, two, da),               //
     AA(n_t, add, da),                     //
     AA(n_t, two, da),                     //
     AA(n_t, add, da),                     //
     AA(n_t, two, da),                     //
     AA(n_t, add, da),                     //
     C)
