#include "nargo.h"

typedef struct lr {
  void (*r)(struct lr *, void *);
  void (*l)(struct lr *, void *);
} lr_pith;
typedef void (*lr_nar)(lr_pith *, void *);

typedef struct lronar {
  lr_pith super;
  lr_pith *o;
  lr_nar nar;
} lronar_pith;
typedef void (*lronar_nar)(lronar_pith *, void *);

nargo(aray, lronar) { o->nar(o->o, advance); }

nargo(mb, lr) {
  param(lr_nar, narb);
  param(lr_nar, nara);
  lronar_pith mbpith;
  mbpith.super.r = (void *)aray;
  mbpith.super.l = o->l;
  mbpith.o = o;
  mbpith.nar = narb;
  nara((void *)&mbpith, advance);
}

int printf(const char *, ...);
void *malloc(unsigned long);
void free(void *);

nargo(nar, lr) {
  param(int, a);
  O(r, a + 3);
}
nargo(logaray, lr) {
  param(int, a);
  printf("r:%d\n", a);
}
nargo(gof, lr) { C(mb, o, 1, nar, nar); }
int main(void) {
  struct lr o;
  o.r = (void *)logaray;
  void *advance = malloc(1024);
  gof(&o, advance);
  free(advance);
  return 0;
}
