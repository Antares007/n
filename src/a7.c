#include "aradani.h"
#include "ints.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
N(ერთი) { A(int, 1), A(n_t,O(1)), C ; }
N(შეკრიბე) {
  R(int, r);
  R(int, l);
  A(int, l + r), A(n_t, O(1)), C;
}
N(ორი) { AAAAA(n_t, ერთი, ერთი, და, შეკრიბე, და), C; }
N(შვიდი) {
  AAAAAAAAAAAAA(n_t, ერთი, ორი, და, ორი, და, ორი, და, შეკრიბე, და, შეკრიბე, და,
                შეკრიბე, და),
      C;
}
N(logint) {
  R(int, v);
  printf("%d\n", v);
}
N(logQ_t) {
  R(Q_t, v);
  printf("%lu\n", v);
}
N(logQ_t2) {
  R(Q_t, b);
  R(Q_t, a);
  printf("%lu %lu\n", a, b);
}
N(rotate3) {
  R(Q_t, c);
  R(Q_t, b);
  R(Q_t, a);
  AAA(Q_t, b, c, a), A(n_t, O(0)), C;
}
N(drop) {
  R(Q_t, a);
  ((void)a);
  A(n_t, O(0)), C;
}
N(swap) {
  R(void *, a);
  R(void *, b);
  AAA(void *, a, b, O(0)), C;
}
// fib_next h:Q_t p:Q_t c:Q_t =
//      n - 1 c c + p (n ? fib_next : .[0]).
N(fib_next) {
  R(Q_t, c);
  R(Q_t, p);
  R(Q_t, n);
  AAA(Q_t, n - 1, c, c + p), A(n_t, n ? fib_next : O(0)), C;
}
// fib = 0 1 fib_next rotate3 an drop an swap an.
N(fib) {
  A(Q_t, 0), A(Q_t, 1), A(n_t, fib_next), A(n_t, rotate3), A(n_t, an),
      A(n_t, drop), A(n_t, an), A(n_t, swap), an(T);
}
// Main = logQ_t2 ჩაახვიე 50Q fib.
Main((1 << 13), malloc, free, A(n_t, logQ_t2), P, A(Q_t, 50), A(n_t, fib), C);

// Main = logint logint logint ჩაააახვიე შვიდი .
// Main(4096, malloc, free, AAA(n_t, logint, logint, logint), PPP, A(n_t,
// შვიდი), C);
