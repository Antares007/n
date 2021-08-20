#include "aradani.h"
#include "src/queue.h"
#include <stdio.h>
#include <stdlib.h>
N(talloc);
N(nt3);
N(narS) {
  printf("narS\n");
  RT(, a);
  At(, a) A4(a, ο, α, ρ, σ) C(a, 0);
}
N(narY) { printf("narY\n"); }
N(narN) { printf("narN\n"); }
N(narA) {
  RT(, a);
  RT(a, b);
  At(a, b) At(, a) 0;
  printf("narA %d\n", bο == ο && bα == α - 4 && bρ == ρ && bσ == σ);
}
N(narC) { printf("narC\n"); }
N(narK) { printf("narK\n"); }
N(tik) { A5(, narS, narY, narN, 32, nt3) Dot(); }
N(tak) { A5(, narA, narC, narK, 32, nt3) Dot(); }
N(toe) {
  RT(, b);
  RT(, a);
  // printf("%d\n", aο[aρ] == narS);
  At(a, b) A(a, aο[aρ + 0]) Dos(a);
  // At(a, b) A(a, aο[aρ+0]) Dot(a);
  // C(,1);
}
N(aralog);
N(dalog);
N(anlog);
N(dot) {
  // void * a = ο[σ];
  Dot();
}
int main() {
  QUEUE queue;
  QUEUE_INIT(&queue);
  Nt(o, malloc(512 * sizeof(void *)), 512);
  P3(o, dot, 0, 0) oσ = oρ;
  P3(o, anlog, dalog, aralog) A5(o, tik, tak, da, toe, da) Dos(o);
  QUEUE q1;
  QUEUE_INSERT_TAIL(&queue, &q1);
  QUEUE q2;
  QUEUE_INSERT_TAIL(&queue, &q2);
  QUEUE q3;
  QUEUE_INSERT_TAIL(&queue, &q3);
  QUEUE *q;
  while (&queue != (q = QUEUE_NEXT(&queue))) {
    printf("%p\n", q);
    QUEUE_REMOVE(q);
  }
  free(oο);
  return 0;
}
N(aralog) { printf("ara"); }
N(dalog) { printf("da %p", ο[--α]); }
N(anlog) { printf("an"); }
N(talloc) {
  long ws = (long)ο[--α];
  if (ρ < α + ws) {
    C(, 2);
  } else {
    long n = α;
    while (n--)
      ο[ws + n] = ο[n];
    void **nο = &ο[ws];
    long nα = α, nρ = ρ - ws, nσ = σ - ws;
    A(n, ws) C(n, 1);
  }
}
N(qdot) { Dot(); }
N(nt3_1) {
  R(, unsigned long, ws);
  R(, void *, r2);
  R(, void *, r1);
  R(, void *, r0);
  Nt(n, ο - ws, ws);
  P3(n, qdot, 0, 0) nσ = nρ;
  P3(n, r0, r1, r2)
  At(, n) C(, 1);
}
N(nt3) { A3(, talloc, nt3_1, da) Dot(); }
typedef struct n_s {
  void (*c)(void **o, long a, struct n_s *r, long s);
} n2_t;
void f(void **o, long a, n2_t *r, long s) {}
void t(void **o, long a, n2_t *r, long s) {
  o[a++] = 0;
  o[a++] = (void *)1;
  o[a++] = (void *)2;
  r[s + 1].c(o, a, r, s);
  f(o, a, r, s);
}
