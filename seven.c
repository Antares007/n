#include "aradani.h"
N(one) { A2(, 1, ο[ρ + 1]) Dot(); }
N(add) {
  R(long, rhs);
  R(long, lhs);
  A2(, rhs + lhs, ο[ρ + 1]) Dot();
}
N(two) { A5(, one, one, da, add, da) Dot(); }
N(seven) {
  A13(, one, two, da, add, da, two, da, add, da, two, da, add, da) Dot();
}

#include <stdio.h>
#include <stdlib.h>

N(aralog) { printf("ara"); }
N(dalog) {
  R(void *, v);
  printf("da %p", v);
}
N(anlog) { printf("an"); }

N(mystart) {
  P(, aralog)
  P(, dalog)
  P(, anlog)
  A5(, seven, seven, da, add, da)
  Dot();
}
int main() {
  NT(, malloc(512 * sizeof(void *)), 512);
  A(, mystart) Dot();
  free(ο);
  return 0;
}
