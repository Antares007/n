typedef void (*nt)(void **, void *, void *);
typedef void (*nargo_t)(nt *, void *, void *);
#define N(n) void n(nt *ο, void *β, void *α)
#define P(T, n) T n = *(T *)(α -= sizeof(T))
#define V(T, a) (*(T *)οα = a, οα += sizeof(T))
// colls
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *οα = (void *)α;                                                      \
    __VA_ARGS__;                                                               \
    ((void (*)())n)(p, β, (void *)οα);                                         \
  }
#define CR(ray, ...) C(ο[ray], ο, __VA_ARGS__)
// mbo
#define Mn(ray, nexp)                                                          \
  {                                                                            \
    void *nb = οα;                                                             \
    nexp;                                                                      \
    V(int, (οα - nb));                                                         \
  }                                                                            \
  V(int, ray);                                                                 \
  V(void *, mbo)
#define B2(ray, nexp1, nexp2)                                                  \
  nexp1;                                                                       \
  Mn(ray, nexp2)
#define B3(ray, nexp1, nexp2, nexp3)                                           \
  B2(ray, nexp1, nexp2);                                                       \
  Mn(ray, nexp3)
#define B4(ray, nexp1, nexp2, nexp3, nexp4)                                    \
  B3(ray, nexp1, nexp2, nexp3);                                                \
  Mn(ray, nexp4)
#define B5(ray, nexp1, nexp2, nexp3, nexp4, nexp5)                             \
  B4(ray, nexp1, nexp2, nexp3, nexp4);                                         \
  Mn(ray, nexp5)
#define B6(ray, nexp1, nexp2, nexp3, nexp4, nexp5, nexp6)                      \
  B5(ray, nexp1, nexp2, nexp3, nexp4, nexp5);                                  \
  Mn(ray, nexp6)
#define O(nexp)                                                                \
  {                                                                            \
    void *οα = α;                                                              \
    nexp;                                                                      \
    οα -= sizeof(void *), (*(nargo_t *)οα)((void *)ο, β, οα);                  \
  }
int printf(const char *, ...);
N(mbo);
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
  CR(1, V(int, l - r));
}
N(gcd) {
  P(int, y);
  P(int, x);
  printf("gcd(%d, %d)\n", x, y);
  O(B3(0,
       B3(1, V(int, x); V(int, y); V(void *, lt);, V(int, y); V(int, x);
          V(void *, sub);, V(int, x); V(void *, gcd);),
       B3(1, V(int, y); V(int, x); V(void *, lt);, V(int, x); V(int, y);
          V(void *, sub);, V(int, y); V(void *, gcd);),
       V(int, x);
       V(void *, r1);));
}
typedef long int intptr_t;
typedef unsigned long int size_t;
void *memcpy(void *destination, const void *source, size_t num);
N(f0) {
  nt *pith = (void *)ο[3];
  C(pith[0], pith);
}
N(f1) {
  nt *pith = (void *)ο[3];
  C(pith[1], pith);
}
N(f2) {
  nt *pith = (void *)ο[3];
  C(pith[2], pith);
}
N(cb) {
  nt *pith = (void *)ο[3];
  intptr_t size = (intptr_t)ο[4];
  memcpy(α, &ο[5], size);
  α += size;
  P(nargo_t, nar);
  nar(pith, β, α);
}
N(mbo) {
  P(int, ray);
  P(int, size);
  void *pith[5 + size / sizeof(void *)];
  pith[0] = f0;
  pith[1] = f1;
  pith[2] = f2;
  pith[ray] = cb;
  pith[3] = ο;
  pith[4] = (void *)(intptr_t)size;
  memcpy(&pith[5], α = α - size, size);
  P(nargo_t, nar);
  nar((void *)pith, β, α);
}
// 0xxxxxxx
// 110xxxxx	10xxxxxx
// 1110xxxx	10xxxxxx	10xxxxxx
// 11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
N(la) {
  P(int, pos);
  P(char *, s);
  if ((s[pos + 0] & 0x80) == 0) {
    CR(1, V(int, s[pos + 0]); V(char *, s); V(int, pos));
  } else if ((s[pos + 1] & 0xc0) != 0x80) {
    CR(0, V(char *, s); V(int, pos));
  } else if ((s[pos + 0] & 0xe0) == 0xc0) {
    CR(1, V(int, (0x1f & s[pos + 0]) << 6 | (0x3f & s[pos + 1])); V(char *, s);
       V(int, pos));
  } else if ((s[pos + 2] & 0xc0) != 0x80) {
    CR(0, V(char *, s); V(int, pos));
  } else if ((s[pos + 0] & 0xf0) == 0xe0) {
    CR(1, V(int, (0x0f & s[pos + 0]) << 12 | (0x3f & s[pos + 1]) << 6 |
                     (0x3f & s[pos + 2]));
       V(char *, s); V(int, pos));
  } else if ((s[pos + 3] & 0xc0) != 0x80) {
    CR(0, V(char *, s); V(int, pos));
  } else if ((s[pos + 0] & 0xf8) == 0xf0) {
    CR(1, V(int, (0x07 & s[pos + 0]) << 18 | (0x3f & s[pos + 1]) << 12 |
                     (0x3f & s[pos + 2]) << 6 | (0x3f & s[pos + 3]));
       V(char *, s); V(int, pos));
  } else {
    CR(0, V(char *, s); V(int, pos));
  }
}
N(ppp) {
  P(int, pos);
  CR(1, V(int, pos + 3));
}
#define Ray(n)                                                                 \
  N(hexdump##n) {                                                              \
    printf("\n%d", n);                                                         \
    for (; β < α; β++) {                                                       \
      unsigned char c = *(unsigned char *)β & 0xff;                            \
      if ((intptr_t)β % 16 == 0)                                               \
        printf("\n%03lx: %02x", (intptr_t)β & 0xfff, c);                       \
      else if ((intptr_t)β % 8 == 0)                                           \
        printf(" %02x", c);                                                    \
      else if ((intptr_t)β % 4 == 0)                                           \
        printf(".%02x", c);                                                    \
      else                                                                     \
        printf("%02x", c);                                                     \
    }                                                                          \
  }
Ray(0);
Ray(1);
Ray(2);
void *malloc(unsigned long);
void free(void *);
N(logint) {
  P(int *, rez);
  printf(">%d\n", *rez);
}
int main() {
  void *β = malloc(1 << 12);
  void *α = β;
  void *ο[] = {hexdump0, hexdump1, hexdump2};
  O(V(int, 21); V(int, 14); V(void *, gcd));
  O(B6(1, V(char *, "აბგ"); V(int, 0); V(void *, la), V(void *, ppp),
                                       V(void *, la), V(void *, ppp),
                                       V(void *, la), V(void *, ppp)));
  free(β);
}
