#include <stdio.h>
#include <stdlib.h>
#define N(n, T) void n(struct T *o, void *b, void *a)
#define A(T, v) *(T *)a = v, a += sizeof(void *);
#define P(T, n) T n = *(T *)(a -= sizeof(void *))
struct ab_pith_s;
typedef void (*ab_nar_t)(struct ab_pith_s *, void *, void *);
struct ab_pith_s {
  ab_nar_t a;
  ab_nar_t b;
};
struct abo_pith_s;
typedef void (*abo_nar_t)(struct abo_pith_s *, void *, void *);
struct abo_pith_s {
  struct ab_pith_s ab;
  struct ab_pith_s *o;
  ab_nar_t b;
};
N(mb_forward_b, abo_pith_s) { o->o->b(o->o, b, a); }
N(mb_call_b, abo_pith_s) { o->b(o->o, b, a); }
N(mb, ab_pith_s) {
  P(ab_nar_t, narb);
  P(ab_nar_t, nara);
  struct abo_pith_s pith = {.ab =
                                {
                                    .a = (ab_nar_t)mb_call_b,
                                    .b = (ab_nar_t)mb_forward_b,
                                },
                            .o = o,
                            .b = narb};
  nara((struct ab_pith_s *)&pith, b, a);
}
N(one, ab_pith_s) {
  A(int, 1);
  o->b(o, b, a);
}
N(add, ab_pith_s) {
  P(int, r);
  P(int, l);
  A(int, l + r);
  o->a(o, b, a);
}
N(two, ab_pith_s) {
  A(ab_nar_t, one)
  A(ab_nar_t, one)
  A(ab_nar_t, mb)
  A(ab_nar_t, add)
  mb(o, b, a);
}
N(exam, ab_pith_s) {
  A(ab_nar_t, one)
  A(ab_nar_t, two)
  A(ab_nar_t, mb)
  A(ab_nar_t, two)
  A(ab_nar_t, mb)
  A(ab_nar_t, two)
  A(ab_nar_t, mb)
  A(ab_nar_t, add)
  A(ab_nar_t, mb)
  A(ab_nar_t, add)
  A(ab_nar_t, mb)
  A(ab_nar_t, add)
  mb(o, b, a);
}
N(logint, ab_pith_s) {
  P(int, v);
  printf("%d\n", v);
}
int main() {
  void *b = malloc(1 << 12);
  struct ab_pith_s o = {logint, logint};
  exam(&o, b, b);
  free(b);
  return 0;
}
