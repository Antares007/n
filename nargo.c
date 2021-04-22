#include "nargo.h"

pith(lr, void (*r)(struct lr *, void *); void (*l)(struct lr *, void *));

padd(lr, nar, lr_nar nar);

nargo(ray, lronar) { o->nar(o->o, advance); }

nargo(mb, lr) {
  param(lr_nar, narb);
  param(lr_nar, nara);
  lronar_pith no;
  no.lr.r = (void *)ray;
  no.lr.l = o->l;
  no.o = o;
  no.nar = narb;
  nara((lr_pith *)&no, advance);
}

int printf(const char *, ...);
void *malloc(unsigned long);
void free(void *);

nargo(nar, lr) {
  param(int, a);
  apply(o->r, o, a + 3);
}
nargo(logaray, lr) {
  param(int, a);
  printf("r:%d\n", a);
}
nargo(gof, lr) {
  apply(mb, o, 1, nar, nar, mb, nar, mb, nar);
}

int main(void) {
  struct lr o;
  o.r = (void *)logaray;
  void *advance = malloc(1024);
  gof(&o, advance);
  free(advance);
  return 0;
}
