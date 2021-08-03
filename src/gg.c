#include "m.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Nba(logptr) {
  R(void *, v);
  printf("ptr:%p", v);
}
Nba(logint) {
  R(int, v);
  printf("A%d", v);
}
Nba(logerr) {
  R(int, v);
  printf("E%d", v);
}
Nba(talloc) {
  R(unsigned long, size);
  void *aba_ = aba + size;
  if (obr < aba_)
    return Obr(n_t, 2)(T);
  for (int i = 1; i < (unsigned long)(aba - abo) / sizeof(void *) + 1; i++)
    *(void **)(aba_ - i * sizeof(void *)) =
        *(void **)(aba - i * sizeof(void *));
  aba = aba_, A(void *, abo), abo += size, Obr(n_t, 1)(T);
}

int main() {
  void *abo, *aba, *obr, *rbs;
  abo = aba = malloc(1 << 12);
  obr = rbs = aba + (1 << 12);
  O(n_t, logerr), O(n_t, logptr), O(n_t, logint);
  A(unsigned long, 9), A(unsigned long, 16), talloc(T);
  free(abo);
}
