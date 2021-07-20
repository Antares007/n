#pragma once
#include <assert.h>
//   abo, aba - 0123456789abcdef - obr
//              XXXXXXXXXXXXXXXX
//              ebp - fXe
//                    dXc
//                    bXa
//                    9X8
//                    7X6
//                    5X4
//                    3X2
//                    1X0
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
