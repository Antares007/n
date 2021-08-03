#include "mbo.h"
#include <stdio.h>
#include <stdlib.h>
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
N(gcd2, ba_pith_s) {
  P(int, y);
  P(int, x);
  if (x < y)
    (A(int, x), A(int, y - x), gcd(o, b, a));
  else if (y < x)
    (A(int, x - y), A(int, y), gcd(o, b, a));
  else
    (A(int, x), o->b(o, b, a));
}
int gcd_c(int x, int y) {
  return (x < y) ? gcd_c(x, y - x) : (y < x) ? gcd_c(x - y, y) : x;
}
int gcd2_c(int x, int y) {
  if (x < y)
    return gcd_c(x, y - x);
  else if (y < x)
    return gcd_c(x - y, y);
  else
    return x;
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
