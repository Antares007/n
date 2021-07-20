#pragma once
//   abo, aba - 0123456789abcdef - obr
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
