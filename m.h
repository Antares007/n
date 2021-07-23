#pragma once
//             init                           next
// ...........................................................
//    aba|              |obr    .             fXXe
// abo - 0123456789abcdef - rbs .             dXXc
//       XXXXXXXXXXXXXXXX       .        aba|     |obr
//       rbp - fXXe             . abo - 0123456789abcdef - rbs
//             dXXc             .       XXXXXXXXXXXXXXXX
//             bXXa             .       rbp - bXXa
//             9XX8             .             9XX8
//             7XX6             .             7XX6
//             5XX4             .             5XX4
//             3XX2             .             3XX2
//             1XX0             .             1XX0
typedef void (*n_t)(void *, void *, void *, void *);
#define Nba(n) void n(void *abo, void *aba, void *obr, void *rbs)
#define T abo, aba, obr, rbs
#define A(T, v) Aba(T, 0) = (v), Aalloc(sizeof(void *))
#define Aba(T, i) (((T *)aba)[i])
#define Abo(T, i) (((T *)abo)[i])
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
#include <assert.h>
