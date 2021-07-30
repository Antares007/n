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
#include "ints.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef void (*n_t)(void *, void *, void *, void *);
#define Nba(n) void n(void *abo, void *aba, void *obr, void *rbs)
#define T abo, aba, obr, rbs
#define A(T, v) Aba(T, 0) = (v), Aalloc(sizeof(void *))
#define Aba(T, i) (((T *)aba)[i])
#define Aalloc(bts) assert(aba + bts <= obr), aba += bts
#define Afree(bts) assert(abo <= aba - bts), aba -= bts
#define C Afree(sizeof(void *)), Aba(n_t, 0)(T)
#define R(T, n)                                                                \
  Afree(sizeof(void *));                                                       \
  T n = Aba(T, 0)
#define O(T, v) Oalloc(sizeof(T)), Obr(T, 0) = (v)
#define Obr(T, i) (((T *)obr)[i])
#define Oalloc(bts) assert(aba <= obr - bts), obr -= bts
#define Ofree(bts) assert(obr + bts <= rbs), obr += bts
#define Main(size, malloc, free, ...)                                          \
  int main() {                                                                 \
    void *abo, *aba, *obr, *rbs;                                               \
    abo = aba = malloc(size), rbs = obr = abo + size, __VA_ARGS__, free(abo);  \
  }
// f0 = :n_t[3] .[0].
Nba(f0) { Ofree(sizeof(void *) * 3), Obr(n_t, +0)(T); }
// f1 = :n_t[3] .[1].
Nba(f1) { Ofree(sizeof(void *) * 3), Obr(n_t, +1)(T); }
// cb = r:n_t[3] r[2].
Nba(cb) { Ofree(sizeof(void *) * 3), Obr(n_t, -1)(T); }
// mbo nara:n_t narb:n_t = .narb, f1, cb nara.
Nba(mbo) {
  R(n_t, narb);
  R(n_t, nara);
  O(n_t, narb), O(n_t, f1), O(n_t, cb), nara(T);
}
// mba nara:n_t narb:n_t =
//  .  narb
//  .  cb
//  .  f0
//  nara.
Nba(mba) {
  R(n_t, narb);
  R(n_t, nara);
  O(n_t, narb), O(n_t, cb), O(n_t, f0), nara(T);
}
// one = 1 T[1].
Nba(one) { A(int, 1), Obr(n_t, 1)(T); }
// add r:int l:int = l + r obr[1].
Nba(add) {
  R(int, r);
  R(int, l);
  A(int, l + r), Obr(n_t, 1)(T);
}
// two = one one mba add mba.
Nba(two) { A(n_t, one), A(n_t, one), A(n_t, mba), A(n_t, add), A(n_t, mba), C; }
// seven = one two mba two mba two mba add mba add mba add mba.
Nba(seven) {
  A(n_t, one), A(n_t, two), A(n_t, mba), A(n_t, two), A(n_t, mba), A(n_t, two),
      A(n_t, mba), A(n_t, add), A(n_t, mba), A(n_t, add), A(n_t, mba),
      A(n_t, add), A(n_t, mba), C;
}
// logint v:int =  printf("%d\n", v);
Nba(logint) {
  R(int, v);
  printf("%d\n", v);
}
// logQ_t v:Q_t = printf("%lu\n", v);
Nba(logQ_t) {
  R(Q_t, v);
  printf("%lu\n", v);
}
// logQ_t2 v:Q_t = printf("%lu\n", v);
Nba(logQ_t2) {
  R(Q_t, b);
  R(Q_t, a);
  printf("%lu %lu\n", a, b);
}
// rotate3 a:Q_t b:Q_t c:Q_t = b, c, a, .[0].
Nba(rotate3) {
  R(Q_t, c);
  R(Q_t, b);
  R(Q_t, a);
  A(Q_t, b), A(Q_t, c), A(Q_t, a), Obr(n_t, 0)(T);
}
// drop :Q_t = .[0].
Nba(drop) {
  R(Q_t, a);
  ((void)a);
  Obr(n_t, 0)(T);
}
// swap a:Q_t b:Q_t = b a .[0].
Nba(swap) {
  R(Q_t, a);
  R(Q_t, b);
  A(Q_t, a), A(Q_t, b), Obr(n_t, 0)(T);
}
// fib_next h:Q_t p:Q_t c:Q_t =
//      n - 1 c c + p (n ? fib_next : .[0]).
Nba(fib_next) {
  R(Q_t, c);
  R(Q_t, p);
  R(Q_t, n);
  A(Q_t, n - 1), A(Q_t, c), A(Q_t, c + p), (n ? fib_next : Obr(n_t, 0))(T);
}
// fib = 0 1 fib_next rotate3 mbo drop mbo swap mbo.
Nba(fib) {
  A(Q_t, 0), A(Q_t, 1), A(n_t, fib_next), A(n_t, rotate3), A(n_t, mbo),
      A(n_t, drop), A(n_t, mbo), A(n_t, swap), mbo(T);
}
// Main = .logQ_t2 5, fib.
Main((1 << 13), malloc, free, O(n_t, logQ_t2), A(Q_t, 50), A(n_t, fib), C);

// Main = logint; logint; seven .
// Main(4096, malloc, free, O(n_t, logint), O(n_t, logint), A(n_t, seven), C);
