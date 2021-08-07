/*                 abo* <= aba* <= obr* <= rbs*
               init                           next
    aba* |              | obr*   .              fXXe
  abo* - 0123456789abcdef - rbs* .              dXXc
         XXXXXXXXXXXXXXXX        .        aba* |    | obr*
       rsp*  - 4XX3              . abo* - 0123456789abcdef - rbs*
               2XX1              .        XXXXXXXXXXXXXXXX
               xXXa              .       rsp* - bXXa
               9XX8              .              9XX8
               7XX6              .              7XX6
               5XX4              .              5XX4
               3XX2              .              3XX2
               1XX0              .              1XX0 */
#include "aradani.h"
#include "ints.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// ერთი = 1 oda.
N(ერთი) { A(int, 1), A(n_t,O(1)), C; }
// შეკრიბე r:int l:int = l + r obr[1].
N(შეკრიბე) {
  R(int, r);
  R(int, l);
  A(int, l + r), A(n_t, O(1)), C;
}
// ორი = ერთი ერთი და შეკრიბე და.
N(ორი) { AAAAA(n_t, ერთი, ერთი, და, შეკრიბე, და), C; }
// შვიდი = ერთი ორი და ორი და ორი და შეკრიბე და შეკრიბე და შეკრიბე და.
N(შვიდი) {
  AAA(n_t, ერთი, ორი, და), AA(n_t, ორი, და), AA(n_t, ორი, და),
      AA(n_t, შეკრიბე, და), AA(n_t, შეკრიბე, და), AA(n_t, შეკრიბე, და), C;
}
// logint v:int =  printf("%d\n", v);
N(logint) {
  R(int, v);
  printf("%d\n", v);
}
// logQ_t v:Q_t = printf("%lu\n", v);
N(logQ_t) {
  R(Q_t, v);
  printf("%lu\n", v);
}
// logQ_t2 v:Q_t = printf("%lu\n", v);
N(logQ_t2) {
  R(Q_t, b);
  R(Q_t, a);
  printf("%lu %lu\n", a, b);
}
// rotate3 a:Q_t b:Q_t c:Q_t = b, c, a, .[0].
N(rotate3) {
  R(Q_t, c);
  R(Q_t, b);
  R(Q_t, a);
  A(Q_t, b), A(Q_t, c), A(Q_t, a), O(0)(T);
}
// drop :Q_t = .[0].
N(drop) {
  R(Q_t, a);
  ((void)a);
  O(0)(T);
}
// swap a:Q_t b:Q_t = b a .[0].
N(swap) {
  R(Q_t, a);
  R(Q_t, b);
  A(Q_t, a), A(Q_t, b), O(0)(T);
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
