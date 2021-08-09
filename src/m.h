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
#define S(n) static N(n)
#define Nar(n, ...)                                                            \
  N(n) { __VA_ARGS__ C; }
#define Sar(n, ...)                                                            \
  S(n) { __VA_ARGS__ C; }
#define T abo, aba, obr, rbs
#define A(T, v) Aba(T, 0) = (v), AddAba(sizeof(void *)),
#define Aba(T, i) (((T *)aba)[i])
#define Abo(T, i) (((T *)abo)[i])
#define AddAba(bts) assert(aba + bts <= obr), aba += bts
#define SubAba(bts) assert(abo <= aba - bts), aba -= bts
#define C SubAba(sizeof(void *)), Aba(n_t, 0)(T)
#define R(T, n)                                                                \
  SubAba(sizeof(void *));                                                      \
  T n = Aba(T, 0)
#define Obr(T, i) (((T *)obr)[i])
#define O(i) Obr(n_t, i)
#define SubObr(bts) assert(aba <= obr - bts), obr -= bts
#define AddObr(bts) assert(obr + bts <= rbs), obr += bts
#define Main(size, malloc, free, ...)                                          \
  int main() {                                                                 \
    void *abo, *aba, *obr, *rbs;                                               \
    abo = aba = malloc(size), rbs = obr = abo + size, __VA_ARGS__, free(abo);  \
  }
#define P                                                                      \
  SubAba(sizeof(void *)), SubObr(sizeof(void *)),                              \
      Obr(void *, 0) = Aba(void *, 0),
#define PP P P
#define PPP P PP
#define PPPP P PPP
#define U                                                                      \
  Aba(void *, 0) = Obr(void *, 0), AddAba(sizeof(void *)),                     \
              AddObr(sizeof(void *)),
#define UU U U
#define UUU U UU
#define UUUU U UUU

#define D AddObr(sizeof(void *)),
#define DD D D
#define DDD D DD
#define DDDD D DDD
#define DDDDD D DDDD

#define A2(T, a, b) A(T, a) A(T, b)
#define A3(T, a, b, c) A(T, a) A(T, b) A(T, c)
#define A4(T, a, b, c, d) A(T, a) A(T, b) A(T, c) A(T, d)
#define A5(T, a, b, c, d, e) A(T, a) A(T, b) A(T, c) A(T, d) A(T, e)
#define A6(T, a, b, c, d, e, f) A(T, a) A(T, b) A(T, c) A(T, d) A(T, e) A(T, f)
#define A7(T, a, b, c, d, e, f, g)                                             \
  A(T, a) A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g)
#define A8(T, a, b, c, d, e, f, g, h)                                          \
  A(T, a) A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h)
#define A9(T, a, b, c, d, e, f, g, h, i)                                       \
  A(T, a) A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i)
#define A10(T, a, b, c, d, e, f, g, h, i, j)                                   \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)
#define A11(T, a, b, c, d, e, f, g, h, i, j, k)                                \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k)
#define A12(T, a, b, c, d, e, f, g, h, i, j, k, l)                             \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l)
#define A13(T, a, b, c, d, e, f, g, h, i, j, k, l, m)                          \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m)
#define A14(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n)                       \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n)
#define A15(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)                    \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n) A(T, o)
#define A16(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)                 \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n) A(T, o) A(T, p)
#define A17(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)              \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n) A(T, o) A(T, p) A(T, q)
#define A18(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)           \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n) A(T, o) A(T, p) A(T, q) A(T, r)
#define A19(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)        \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n) A(T, o) A(T, p) A(T, q) A(T, r) A(T, s)
#define A20(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)     \
  A(T, a)                                                                      \
  A(T, b) A(T, c) A(T, d) A(T, e) A(T, f) A(T, g) A(T, h) A(T, i) A(T, j)      \
      A(T, k) A(T, l) A(T, m) A(T, n) A(T, o) A(T, p) A(T, q) A(T, r) A(T, s)  \
          A(T, t)
#include <assert.h>
