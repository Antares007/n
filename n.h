#pragma once
#define CC_(a, b) a##b
#define CC(a, b) CC_(a, b)
#define CCC(a, b, c) CC(CC(a, b), c)
#define CCCC(a, b, c, d) CCC(CC(a, b), c, d)
#define N(n) static void n(void o(void *, void *), void *b)
#define Nand(n, nara, narb) Nandps(n, nara) narb(o, b); }
#define Nor(n, nara, narb) Norps(n, nara) narb(o, b); }
#define Nandps(n, nara)                                                        \
  N(CC(n, _pith));                                                             \
  N(n) { nara((void *)CC(n, _pith), (void *[]){o, b}); }                       \
  N(CC(n, _pith)) {                                                            \
    o = ((void **)b)[0];                                                       \
    b = ((void **)b)[1];
#define Norps(n, nara)                                                         \
  N(CC(n, _pith)) {                                                            \
    *((int **)b)[2] = 0;                                                       \
    o = ((void **)b)[0];                                                       \
    b = ((void **)b)[1];                                                       \
    o(o, b);                                                                   \
  }                                                                            \
  N(n) {                                                                       \
    int r = 1;                                                                 \
    nara((void *)CC(n, _pith), (void *[]){o, b, &r});                          \
    if (r == 0)                                                                \
      return;
