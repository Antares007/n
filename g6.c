#include "mbo.h"
#include <stdio.h>
#include <stdlib.h>
N(exam, ba_pith_s) { A(int, 7), o->b(o, b, a); }
N(logint, ba_pith_s) {
  P(int, v);
  printf("%d\n", v);
}
#define Pith(n)                                                                \
  struct n##_pith_s;                                                           \
  typedef struct n##_pith_s n##_pith_t;                                        \
  typedef void (*n##_nar_t)(n##_pith_t *, void *, void *);                     \
  struct n##_pith_s

Pith(oba) {
  oba_nar_t next;
  oba_nar_t start;
  oba_nar_t stop;
};
N(os_start1, oba_pith_s) {}
N(os_start, oba_pith_s) {
  P(oba_pith_t *, op);
  printf("os:%p op:%p\n", o, op);
  o->start = os_start1;
  os_start1(o, b, a);
  for (;;) {
    //
  }
}
N(os_stop, oba_pith_s) {}
N(os_next, oba_pith_s) {}
N(op_start, oba_pith_s) {}
N(op_stop, oba_pith_s) {}
N(op_next, oba_pith_s) {}
int main() {
  oba_pith_t os = {.start = os_start, .next = os_next, .stop = os_stop};
  oba_pith_t op = {.start = op_start, .next = op_next, .stop = op_stop};
  printf("os:%p op:%p\n", &os, &op);
  void *b = malloc(1 << 12);
  {
    void *a = b;
    A(oba_pith_t *, &op), os.start(&os, b, a);
  }
  free(b);
}
