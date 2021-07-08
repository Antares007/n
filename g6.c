#include "mbo.h"
#include <stdio.h>
#include <stdlib.h>
N(one, ba_pith_s) {
  A(int, 1);
  o->b(o, b, a);
}
N(add, ba_pith_s) {
  P(int, r);
  P(int, l);
  A(int, l + r);
  o->b(o, b, a);
}
N(two, ba_pith_s) {
  A(ba_nar_t, one);
  A(ba_nar_t, one);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  mb(o, b, a);
}
N(exam, ba_pith_s) {
  A(ba_nar_t, one);
  A(ba_nar_t, two);
  A(ba_nar_t, mb);
  A(ba_nar_t, two);
  A(ba_nar_t, mb);
  A(ba_nar_t, two);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  mb(o, b, a);
}
N(logint, ba_pith_s) {
  P(int, v);
  printf("%d\n", v);
}
int main() {
  void *b = malloc(1 << 12);
  struct ba_pith_s o = {logint, logint};
  {
    void *a = b;
    exam(&o, b, a);
  }
  free(b);
}
