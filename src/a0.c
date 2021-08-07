#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>

N(da_puts) {
  R(int, v);
  printf("da: %d", v);
}
N(an_puts) { puts("an"); }
N(ara_puts) { puts("ara"); }
N(one) { A(int, 1), A(n_t, O(1)), C; }
N(add) {
  R(int, r);
  R(int, l);
  A(int, l + r), A(n_t, O(1)), C;
}
N(two) { AAAAA(n_t, one, one, da, add, da), C; }
N(seven) {
  AAAAAAAAAAAAA(n_t, one, two, da, add, da, two, da, add, da, two, da, add, da),
      C;
}

Main((10 << 12), malloc, free, AAAA(n_t, seven, an_puts, da_puts, ara_puts),
     PPP, C)
