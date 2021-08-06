#pragma once
/*
               init                           next
   ...........................................................
      aba|              |obr    .             fXXe
   abo - 0123456789abcdef - rbs .             dXXc
         XXXXXXXXXXXXXXXX       .         aba|    |obr
         rsp - fXXe             . abo - 0123456789abcdef - rbs
               dXXc             .       XXXXXXXXXXXXXXXX
               bXXa             .       rsp - bXXa
               9XX8             .             9XX8
               7XX6             .             7XX6
               5XX4             .             5XX4
               3XX2             .             3XX2
               1XX0             .             1XX0
                    abo <= aba <= obr <= rbs
*/
typedef void (*n_t)(void *, void *, void *, void *);
#define N(n) void n(void *abo, void *aba, void *obr, void *rbs)
#define T abo, aba, obr, rbs
#define A(T, v) Aba(T, 0) = (v), AddAba(sizeof(void *))
#define Aba(T, i) (((T *)aba)[i])
#define Abo(T, i) (((T *)abo)[i])
#define AddAba(bts) assert(aba + bts <= obr), aba += bts
#define SubAba(bts) assert(abo <= aba - bts), aba -= bts
#define C SubAba(sizeof(void *)), Aba(n_t, 0)(T)
#define R(T, n)                                                                \
  SubAba(sizeof(void *));                                                      \
  T n = Aba(T, 0)
#define O(T, v) SubObr(sizeof(T)), Obr(T, 0) = (v)
#define Obr(T, i) (((T *)obr)[i])
#define SubObr(bts) assert(aba <= obr - bts), obr -= bts
#define AddObr(bts) assert(obr + bts <= rbs), obr += bts
#define Main(size, malloc, free, ...)                                          \
  int main() {                                                                 \
    void *abo, *aba, *obr, *rbs;                                               \
    abo = aba = malloc(size), rbs = obr = abo + size, __VA_ARGS__, free(abo);  \
  }
#define AA(T, a, b) A(T, a), A(T, b)
#define AAA(T, a, b, c) A(T, a), A(T, b), A(T, c)
#define AAAA(T, a, b, c, d) A(T, a), A(T, b), A(T, c), A(T, d)
#define AAAAA(T, a, b, c, d, e) A(T, a), A(T, b), A(T, c), A(T, d), A(T, e)
#define OO(T, a, b) O(T, b), O(T, a)
#define OOO(T, a, b, c) O(T, c), O(T, b), O(T, a)
#define OOOO(T, a, b, c, d) O(T, d), O(T, c), O(T, b), O(T, a)
#define OOOOO(T, a, b, c, d, e) O(T, e), O(T, d), O(T, c), O(T, b), O(T, a)
#include <assert.h>
