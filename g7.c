//           aba|              |obr
//        abo - 0123456789abcdef - rbs
//              XXXXXXXXXXXXXXXX
//              rbp - fXXe
//                    dXXc
//                    bXXa
//                    9XX8
//                    7XX6
//                    5XX4
//                    3XX2
//                    1XX0
typedef void (*n_t)(void *, void *, void *);
#define Nba(n) void n(void *obr, void *abo, void *aba)
#define T obr, abo, aba
#define A(T, v) Aba(T, 0) = (v), Alloc(sizeof(void *))
#define Aba(T, i) (((T *)aba)[i])
#define Alloc(bts) assert(aba + bts <= obr), aba += bts
#define Free(bts) assert(abo <= aba - bts), aba -= bts
#define C Free(sizeof(void *)), Aba(n_t, 0)(T)
#define R(T, n)                                                                \
  Free(sizeof(void *));                                                        \
  T n = Aba(T, 0)
#define O(T, v) Olloc(sizeof(T)), Obr(T, 0) = (v)
#define Obr(T, i) (((T *)obr)[i])
#define Olloc(bts) assert(aba <= obr - bts), obr -= bts
#define Oree(bts) obr += bts
#define Main(size, malloc, free, ...)                                          \
  int main() {                                                                 \
    void *obr, *abo, *aba;                                                     \
    abo = aba = malloc(size), obr = abo + size, __VA_ARGS__, free(abo);        \
  }
#include <assert.h>
// f0 = rays:n_t[3] .[0].
Nba(f0) { Oree(sizeof(void *) * 3), Obr(n_t, +0)(T); }
// f1 = rays:n_t[3] .[1].
Nba(f1) { Oree(sizeof(void *) * 3), Obr(n_t, +1)(T); }
// cb = rays:n_t[3] rays[2].
Nba(cb) { Oree(sizeof(void *) * 3), Obr(n_t, -1)(T); }
// mbo = narb=n_t narb; f1; cb; nara=n_t nara.
Nba(mbo) {
  R(n_t, narb);
  O(n_t, narb), O(n_t, f1), O(n_t, cb), C;
}
// mba = narb=n_t narb; cb; f0; nara=n_t nara.
Nba(mba) {
  R(n_t, narb);
  O(n_t, narb), O(n_t, cb), O(n_t, f0), C;
}
// one = 1, .[1].
Nba(one) { A(int, 1), Obr(n_t, 1)(T); }
// add = r=int l=int l + r, .[1].
Nba(add) {
  R(int, r);
  R(int, l);
  A(int, l + r), Obr(n_t, 1)(T);
}
// two = one, one, mba, add, mba.
Nba(two) { A(n_t, one), A(n_t, one), A(n_t, mba), A(n_t, add), A(n_t, mba), C; }
// seven = one, two, mba, two, mba, two, mba, add, mba, add, mba, add, mba.
Nba(seven) {
  A(n_t, one), A(n_t, two), A(n_t, mba), A(n_t, two), A(n_t, mba), A(n_t, two),
      A(n_t, mba), A(n_t, add), A(n_t, mba), A(n_t, add), A(n_t, mba),
      A(n_t, add), A(n_t, mba), C;
}
#include <stdio.h>
// logint = v:int ..c printf("%d\n", v);
Nba(logint) {
  R(int, v);
  printf("%d\n", v);
}
#include <stdlib.h>
// Main = logint; logint; seven .
Main(4096, malloc, free, O(n_t, logint), O(n_t, logint), A(n_t, seven), C);
