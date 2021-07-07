#include <stdio.h>
#include <stdlib.h>
#define N(n, T) void n(struct T *o, void *b, void *a)
#define A(T, v) *(T *)a = v, a += sizeof(void *)
#define P(T, n) T n = *(T *)(a -= sizeof(void *))
struct ba_pith_s;
typedef void (*ba_nar_t)(struct ba_pith_s *, void *, void *);
struct ba_pith_s {
  ba_nar_t b;
  ba_nar_t a;
};
struct bao_pith_s;
typedef void (*abo_nar_t)(struct bao_pith_s *, void *, void *);
struct bao_pith_s {
  struct ba_pith_s ba;
  struct ba_pith_s *o;
  ba_nar_t b;
};
N(mb_forward_a, bao_pith_s) { o->o->a(o->o, b, a); }
N(mb_forward_b, bao_pith_s) { o->o->b(o->o, b, a); }
N(mb_call_b, bao_pith_s) { o->b(o->o, b, a); }
N(mb, ba_pith_s) {
  P(ba_nar_t, narb);
  P(ba_nar_t, nara);
  struct bao_pith_s pith = {.ba =
                                {
                                    .a = (ba_nar_t)mb_forward_a,
                                    .b = (ba_nar_t)mb_call_b,
                                },
                            .o = o,
                            .b = narb};
  nara((struct ba_pith_s *)&pith, b, a);
}
N(ma, ba_pith_s) {
  P(ba_nar_t, narb);
  P(ba_nar_t, nara);
  struct bao_pith_s pith = {.ba =
                                {
                                    .a = (ba_nar_t)mb_call_b,
                                    .b = (ba_nar_t)mb_forward_b,
                                },
                            .o = o,
                            .b = narb};
  nara((struct ba_pith_s *)&pith, b, a);
}
N(one, ba_pith_s) {
  A(int, 1);
  o->b(o, b, a);
}
N(add, ba_pith_s) {
  P(int, r);
  P(int, l);
  A(int, l + r);
  o->b(o, b, a);
}
N(two, ba_pith_s) {
  A(ba_nar_t, one);
  A(ba_nar_t, one);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  mb(o, b, a);
}
N(exam, ba_pith_s) {
  A(ba_nar_t, one);
  A(ba_nar_t, two);
  A(ba_nar_t, mb);
  A(ba_nar_t, two);
  A(ba_nar_t, mb);
  A(ba_nar_t, two);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  A(ba_nar_t, mb);
  A(ba_nar_t, add);
  mb(o, b, a);
}
N(fibonacci_next, ba_pith_s) {
  P(int, c);
  P(int, p);
  P(int, n);
  if (n)
    A(int, n - 1), A(int, c), A(int, p + c), fibonacci_next(o, b, a);
  else
    A(int, p), o->b(o, b, a);
}
N(fibonacci, ba_pith_s) { A(int, 0), A(int, 1), fibonacci_next(o, b, a); }

N(gcd, ba_pith_s) {
  P(int, y);
  P(int, x);
  x < y   ? (A(int, x), A(int, y - x), gcd(o, b, a))
  : y < x ? (A(int, x - y), A(int, y), gcd(o, b, a))
          : (A(int, x), o->b(o, b, a));
}
int gcd_c(int x, int y) {
  return (x < y) ? gcd_c(x, y - x) : (y < x) ? gcd_c(x - y, y) : x;
}

N(logint, ba_pith_s) {
  P(int, v);
  printf("%d\n", v);
}
int main() {
  void *b = malloc(1 << 12);
  struct ba_pith_s o = {logint, logint};
  exam(&o, b, b);
  int ret = *(int *)b;
  {
    void *a = b;
    A(int, ret), fibonacci(&o, b, a);
  }
  {
    void *a = b;
    A(int, 21), A(int, 14), gcd(&o, b, a);
  }
  free(b);
  return 0;
}
