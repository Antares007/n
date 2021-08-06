#include "aradani.h"
#define CB(n, i)                                                               \
  static N(cb##n##i) { AddObr(sizeof(void *) * n), Obr(n_t, -(i + 1))(T); }
#define CA(n, i)                                                               \
  static N(ca##n##i) { AddObr(sizeof(void *) * n), Obr(n_t, i)(T); }
CB(4, 0)
CB(4, 1)
CA(4, 0)
CA(4, 1)
CA(5, 0)
CA(5, 1)
static N(cin) {
  AddObr(sizeof(void *) * 5), A(n_t, Obr(n_t, -2)), Obr(n_t, -1)(T);
}
N(ara) {
  R(n_t, b);
  n_t araarxi = Obr(n_t, 2);
  O(n_t, b), O(n_t, araarxi), //
      O(n_t, cin), O(n_t, ca51), O(n_t, ca50), C;
}
N(da) {
  R(n_t, b);
  n_t araarxi = Obr(n_t, 2);
  O(n_t, b), //
      O(n_t, araarxi), O(n_t, cb40), O(n_t, ca40), C;
}
N(an) {
  R(n_t, b);
  n_t araarxi = Obr(n_t, 2);
  O(n_t, b), //
      O(n_t, araarxi), O(n_t, ca41), O(n_t, cb41), C;
}
CB(5, 0)
CB(5, 1)
N(anda) {
  R(n_t, da);
  R(n_t, an);
  n_t araarxi = Obr(n_t, 2);
  O(n_t, an), O(n_t, da), //
      O(n_t, araarxi), O(n_t, cb51), O(n_t, cb50), C;
}
CB(7, 0)
CB(7, 1)
static N(cin2) {
  AddObr(sizeof(void *) * 7), A(n_t, Obr(n_t, -4)), Obr(n_t, -1)(T);
}
N(aradani) {
  R(n_t, an);
  R(n_t, da);
  R(n_t, ara);
  n_t araarxi = Obr(n_t, 2);
  O(n_t, an), O(n_t, da), O(n_t, ara), O(n_t, araarxi), O(n_t, cin2),
      O(n_t, cb71), O(n_t, cb70), C;
}

#if 1
#include <stdio.h>
static N(one) { Obr(n_t, 1)(T); }
static N(daarxi) { puts("da"); }
static N(anarxi) { puts("an"); }
static N(araarxi) { puts("ara"); }

#include <stdlib.h>
Main((10 << 12), malloc, free, O(n_t, araarxi), O(n_t, daarxi), O(n_t, anarxi),
     A(n_t, one), A(n_t, one), A(n_t, da), C);
#endif
