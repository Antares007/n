#include "aradani.h"
#include <stdio.h>

N(da_puts) {
  R(int, v);
  printf("da: %d", v);
}
N(an_puts) { puts("an"); }
N(ara_puts) { puts("ara"); }

N(an_bma) { O(0)(T); }
N(da_bma) { O(1)(T); }
N(ara_bma) { O(2)(T); }
#include <stdlib.h>

N(one) { A(int, 1), O(1)(T); }
N(add) {
  R(int, r);
  R(int, l);
  A(int, l + r), O(1)(T);
}
N(two) { AAAAA(n_t, one, one, da, add, da), C; }

Main((10 << 12), malloc, free,                  //
     AAA(n_t, an_puts, da_puts, ara_puts), PPP, //
     AAA(n_t, one, two, da),                    //
     AA(n_t, add, da),                          //
     AA(n_t, two, da),                          //
     AA(n_t, add, da),                          //
     AA(n_t, two, da),                          //
     AA(n_t, add, da),                          //
     C)
