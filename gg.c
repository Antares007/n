#include "m.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Nba(logint) {
  R(int, v);
  printf("A%d", v);
}
Nba(logfloat) { printf("B"); }
Nba(Hello) {
  SubAba(sizeof(void *));
  n_t nara = Aba(n_t, 0);
  // R(n_t, nara);
  Aba(n_t, 0)(T);
  A(int, 9), Obr(n_t, 0)(T);

  printf("%lu %d %d %lu\n", obr - aba, nara == logfloat, Obr(n_t, 0) == logint,
         aba - abo);
}
Nba(ckaro) {
  void *aba_ = aba + (16);
  unsigned long n = ((unsigned long)(aba - abo)) / sizeof(void *);
  int i = 0;
  while (n--) {
    i++;
    *(void **)(aba_ - i * sizeof(void *)) =
        *(void **)(aba - i * sizeof(void *));
  }
  aba = aba_;
}

int main() {
  void *abo, *aba, *obr, *rbs;
  abo = aba = malloc(10 << 12);
  obr = rbs = aba + (10 << 12);
  A(n_t, logfloat), O(n_t, logint), O(n_t, logint), O(n_t, logint), ckaro(T);
  free(abo);
}
