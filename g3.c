#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*nt)(void **, void *, void *);
typedef void (*nargo_t)(nt *, void *, void *);
#define N(n) void n(nt *ο, void *β, void *α)
#define P(T, n) T n = *(T *)(α -= sizeof(void *))
#define AC(T)                                                                  \
  T:                                                                           \
  *(T *)οα
#define A(X)                                                                   \
  *(uintptr_t *)οα = 0xcccccccccccccccc;                                       \
  _Generic((X), AC(int32_t), AC(uint32_t), AC(float), AC(double), AC(char *),  \
           AC(nt), AC(nargo_t), AC(void *)) = (X);                             \
  οα = ((char *)οα) + sizeof(void *)
#define A2(a, b)                                                               \
  A(a);                                                                        \
  A(b)
#define A3(a, b, c)                                                            \
  A2(a, b);                                                                    \
  A(c)
#define A4(a, b, c, d)                                                         \
  A3(a, b, c);                                                                 \
  A(d)
// colls
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *οα = (void *)α;                                                      \
    __VA_ARGS__;                                                               \
    ((void (*)())n)(p, β, (void *)οα);                                         \
  }
#define CR(ray, ...) C(ο[ray], ο, __VA_ARGS__)
// mbo
#define Mn(nexp, ray)                                                          \
  {                                                                            \
    void *nb = οα;                                                             \
    nexp;                                                                      \
    A((uint32_t)(οα - nb));                                                    \
  }                                                                            \
  A((uint32_t)ray);                                                            \
  A(mbo)
#define B2(nexp1, nexp2, ray)                                                  \
  nexp1;                                                                       \
  Mn(nexp2, ray)
#define B3(nexp1, nexp2, nexp3, ray)                                           \
  B2(nexp1, nexp2, ray);                                                       \
  Mn(nexp3, ray)
#define B4(nexp1, nexp2, nexp3, nexp4, ray)                                    \
  B3(nexp1, nexp2, nexp3, ray);                                                \
  Mn(nexp4, ray)
#define B5(nexp1, nexp2, nexp3, nexp4, nexp5, ray)                             \
  B4(nexp1, nexp2, nexp3, nexp4, ray);                                         \
  Mn(nexp5, ray)
#define B6(nexp1, nexp2, nexp3, nexp4, nexp5, nexp6, ray)                      \
  B5(nexp1, nexp2, nexp3, nexp4, nexp5, ray);                                  \
  Mn(nexp6, ray)
#define M2(nexp, nexp0, nexp1)                                                 \
  nexp;                                                                        \
  {                                                                            \
    void *nb0 = οα;                                                            \
    nexp0;                                                                     \
    void *nb1 = οα;                                                            \
    nexp1;                                                                     \
    A((uint32_t)(οα - nb1));                                                   \
    A((uint32_t)(nb1 - nb0));                                                  \
  }                                                                            \
  A(mbm)
#define O(nexp)                                                                \
  {                                                                            \
    void *οα = α;                                                              \
    nexp;                                                                      \
    οα -= sizeof(void *), (*(nargo_t *)οα)((void *)ο, β, οα);                  \
  }
#define Ray(n)                                                                 \
  N(hexdump##n) {                                                              \
    for (; β < α; β++) {                                                       \
      unsigned char c = *(unsigned char *)β & 0xff;                            \
      if ((intptr_t)β % 16 == 0)                                               \
        printf("\n%d)%03lx: %02x", n, (intptr_t)β & 0xfff, c);                 \
      else if ((intptr_t)β % 8 == 0)                                           \
        printf(" %02x", c);                                                    \
      else if ((intptr_t)β % 4 == 0)                                           \
        printf(".%02x", c);                                                    \
      else                                                                     \
        printf("%02x", c);                                                     \
    }                                                                          \
    printf("\n");                                                              \
  }
N(mb_f0) {
  nt *pith = (void *)ο[3];
  C(pith[0], pith);
}
N(mb_f1) {
  nt *pith = (void *)ο[3];
  C(pith[1], pith);
}
N(mb_f2) {
  nt *pith = (void *)ο[3];
  C(pith[2], pith);
}
N(mbo_cb) {
  nt *pith = (void *)ο[3];
  uintptr_t size = (uintptr_t)ο[4];
  memcpy(α, ο[5], size);
  α += size;
  P(nargo_t, nar);
  nar(pith, β, α);
}
N(mbo) {
  P(uint32_t, ray);
  P(uint32_t, size);
  char *nexp[size];
  void *pith[] = {mb_f0, mb_f1, mb_f2, ο, (void *)(uintptr_t)size, nexp};
  pith[ray] = mbo_cb;
  memcpy(nexp, α = α - size, size);
  P(nargo_t, nar);
  nar((void *)pith, β, α);
}
N(mbo0) {}
N(mbm_cb0) {
  nt *pith = (void *)ο[3];
  intptr_t size = (intptr_t)ο[4];
  memcpy(α, ο[5], size);
  α += size;
  P(nargo_t, nar);
  nar(pith, β, α);
}
N(mbm_cb1) {
  nt *pith = (void *)ο[3];
  intptr_t size = (intptr_t)ο[6];
  memcpy(α, ο[7], size);
  α += size;
  P(nargo_t, nar);
  nar(pith, β, α);
}
N(mbm) {
  P(uint32_t, s0);
  P(uint32_t, s1);
  char *nexp0[s0];
  char *nexp1[s1];
  void *pith[] = {mbm_cb0,
                  mbm_cb1,
                  mb_f2,
                  ο,
                  (void *)(uintptr_t)s0,
                  nexp0,
                  (void *)(uintptr_t)s1,
                  nexp1};
  memcpy(nexp1, α = α - s1, s1);
  memcpy(nexp0, α = α - s0, s0);
  P(nargo_t, nar);
  nar((void *)pith, β, α);
}
N(r2) { CR(2); }
N(r1) { CR(1); }
N(r0) { CR(0); }
N(lt) {
  P(int, r);
  P(int, l);
  printf("%d < %d = %d\n", l, r, l < r);
  CR(l < r);
}
N(sub) {
  P(int, r);
  P(int, l);
  printf("%d - %d = %d\n", l, r, l - r);
  CR(1, A(l - r));
}
N(test) {}
N(gcd) {
  P(int, y);
  P(int, x);
  printf("gcd(%d, %d)\n", x, y);
  O(B3(                                               //
      B3(A3(x, y, lt), A3(y, x, sub), A2(x, gcd), 1), //
      B3(A3(y, x, lt), A3(x, y, sub), A2(y, gcd), 1), //
      A2(x, r1), 0));
}
// 0xxxxxxx
// 110xxxxx	10xxxxxx
// 1110xxxx	10xxxxxx	10xxxxxx
// 11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
N(la) {
  P(int, pos);
  P(char *, s);
  if ((s[pos + 0] & 0x80) == 0) {
    CR(1, A3((uint32_t)s[pos + 0], s, pos));
  } else if ((s[pos + 1] & 0xc0) != 0x80) {
    CR(0, A2(s, pos));
  } else if ((s[pos + 0] & 0xe0) == 0xc0) {
    CR(1, A3((uint32_t)(0x1f & s[pos + 0]) << 6 | (0x3f & s[pos + 1]), s, pos));
  } else if ((s[pos + 2] & 0xc0) != 0x80) {
    CR(0, A2(s, pos));
  } else if ((s[pos + 0] & 0xf0) == 0xe0) {
    CR(1, A3((uint32_t)((0x0f & s[pos + 0]) << 12 | (0x3f & s[pos + 1]) << 6 |
                        (0x3f & s[pos + 2])),
             s, pos));
  } else if ((s[pos + 3] & 0xc0) != 0x80) {
    CR(0, A2(s, pos));
  } else if ((s[pos + 0] & 0xf8) == 0xf0) {
    CR(1, A3((uint32_t)(0x07 & s[pos + 0]) << 18 | (0x3f & s[pos + 1]) << 12 |
                 (0x3f & s[pos + 2]) << 6 | (0x3f & s[pos + 3]),
             s, pos));
  } else {
    CR(0, A2(s, pos));
  }
}
N(ppp) {
  P(int, pos);
  CR(1, A(pos + 3));
}
Ray(0);
Ray(1);
Ray(2);
N(inc) {
  P(uint32_t, v);
  CR(1, A(v + 1));
}
N(get) { CR(1, A((uint32_t)99)); }
N(loop) { O(B4(A(ο[2]), A(inc), A2(3, r1), A2(4, r1), 1)); }
int main() {
  void *β = malloc(1 << 12);
  void *α = β;
  void *ο[] = {hexdump0, hexdump1, get};
  O(B3(          //
      A(loop),   //
      A2(5, r1), //
      A2(6, r1), //
      1          //
      )          //
  );             //
  // O(M2(A3(1, 2, r1), A2(4, r1), A3(7, 8, r0)));
  O(A3(21, 14, gcd));
  // O(B6(A3("აბგ", 0, la), A(ppp), A(la), A(ppp), A(la), A(ppp), 1));
  free(β);
}
