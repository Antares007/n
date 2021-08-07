#include "m.h"
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
  R(unsigned long, size);
  void *aba_ = aba + size;
  if (obr < aba_)
    return O(2)(T);
  for (int i = 1; i < (unsigned long)(aba - abo) / sizeof(void *) + 1; i++)
    *(void **)(aba_ - i * sizeof(void *)) =
        *(void **)(aba - i * sizeof(void *));
  aba = aba_, A(void *, abo), abo += size, O(1)(T);
}
// daN, anN, araN, andaN
// cin1 cin2 da
// cin1 cin2 an
// cin1 ancin2 dacin3 anda
// cin1
//    'p1' 'p2' ancin2
//    'p1' 'p2' 'p3' dacin3
// 023 andaN
//    gamoascoreshecdoma
// ara.
// cin1 cin2 ara
// cin1 'par1' cin2 1 araN
// cin1 'par1' 'par2' cin2 2 araN

int main() {
  void *abo, *aba, *obr, *rbs;
  abo = aba = malloc(1 << 12);
  obr = rbs = aba + (1 << 12);
  AAA(n_t, logerr, logptr, logint), PPP, AA(unsigned long, 9, 16), talloc(T);
  free(abo);
}
