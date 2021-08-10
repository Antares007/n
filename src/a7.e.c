#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>
void ერთი(void *abo, void *aba, void *obr, void *rbs) {
  (((int *)aba)[0]) = (1), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = ((((n_t *)obr)[1])),
         (aba = (char *)aba + sizeof(void *)),
         (aba = (char *)aba - sizeof(void *)),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void შეკრიბე(void *abo, void *aba, void *obr, void *rbs) {
  (aba = (char *)aba - sizeof(void *));
  int r = (((int *)aba)[0]);
  (aba = (char *)aba - sizeof(void *));
  int l = (((int *)aba)[0]);
  (((int *)aba)[0]) = (l + r), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = ((((n_t *)obr)[1])),
         (aba = (char *)aba + sizeof(void *)),
         (aba = (char *)aba - sizeof(void *)),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void ორი(void *abo, void *aba, void *obr, void *rbs) {
  (((n_t *)aba)[0]) = (ერთი), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (ერთი), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (შეკრიბე), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (aba = (char *)aba - sizeof(void *)),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void შვიდი(void *abo, void *aba, void *obr, void *rbs) {
  (((n_t *)aba)[0]) = (ერთი), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (ორი), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (ორი), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (ორი), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (შეკრიბე), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (შეკრიბე), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (შეკრიბე), (aba = (char *)aba + sizeof(void *)),
         (((n_t *)aba)[0]) = (da), (aba = (char *)aba + sizeof(void *)),
         (aba = (char *)aba - sizeof(void *)),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}

void logint(void *abo, void *aba, void *obr, void *rbs) {
  (aba = (char *)aba - sizeof(void *));
  int v = (((int *)aba)[0]);
  printf("%d\n", v);
}
int main() {
  void *abo, *aba, *obr, *rbs;
  abo = aba = malloc(4096), rbs = obr = (char *)abo + 4096,
  (((n_t *)aba)[0]) = (logint), (aba = (char *)aba + sizeof(void *)),
  (((n_t *)aba)[0]) = (logint), (aba = (char *)aba + sizeof(void *)),
  (((n_t *)aba)[0]) = (logint), (aba = (char *)aba + sizeof(void *)),
  (aba = (char *)aba - sizeof(void *)), (obr = (char *)obr - sizeof(void *)),
  (((void **)obr)[0]) = (((void **)aba)[0]),
  (aba = (char *)aba - sizeof(void *)), (obr = (char *)obr - sizeof(void *)),
  (((void **)obr)[0]) = (((void **)aba)[0]),
  (aba = (char *)aba - sizeof(void *)), (obr = (char *)obr - sizeof(void *)),
  (((void **)obr)[0]) = (((void **)aba)[0]), (((n_t *)aba)[0]) = (შვიდი),
  (aba = (char *)aba + sizeof(void *)), (aba = (char *)aba - sizeof(void *)),
  (((n_t *)aba)[0])(abo, aba, obr, rbs), free(abo);
}
