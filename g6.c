#include "mbo.h"
#include <stdio.h>
#include <stdlib.h>
N(exam, ba_pith_s) { A(int, 7), o->b(o, b, a); }
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
