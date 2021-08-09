#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
N(logptr) {
  R(void *, v);
  printf("ptr:%p", v);
}
N(logint) {
  R(int, v);
  printf("A%d", v);
}
N(logerr) {
  R(int, v);
  printf("E%d", v);
}
N(talloc) {
  R(Q_t, size);
  void *aba_ = aba + size;
  if (obr < aba_)
    return O(2)(T);
  for (int i = 1; i < (unsigned long)(aba - abo) / sizeof(void *) + 1; i++)
    *(void **)(aba_ - i * sizeof(void *)) =
        *(void **)(aba - i * sizeof(void *));
  aba = aba_, A(void *, abo) abo += size, O(1)(T);
}
int main() {
  void *abo, *aba, *obr, *rbs;
  abo = aba = malloc(1 << 12);
  obr = rbs = aba + (1 << 12);
  An(n_t, logerr, logptr, logint) PPP An(Q_t, 9, 16) An(n_t, talloc) C;
  free(abo);
}
