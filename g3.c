typedef void (*nt)(void **, void *, void *);
typedef void (*nargo_t)(nt *, void *, void *);
#define nargo(n) void n(nt *ο, void *β, void *α)
#define param(T, n) T n = *(T *)(α -= sizeof(T))
#define arg(T, a) (*(T *)οα = a, οα += sizeof(T))
// colls
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *οα = (void *)α;                                                      \
    __VA_ARGS__;                                                               \
    ((void (*)())n)(p, β, (void *)οα);                                         \
  }
#define CR(ray, ...) C(ο[ray], ο, __VA_ARGS__)
// void stars
#define V(v) arg(void *, v)
#define V2(v1, v2)                                                             \
  V(v1);                                                                       \
  V(v2)
#define V3(v1, v2, v3)                                                         \
  V2(v1, v2);                                                                  \
  V(v3)
// mbo
#define Bn(ray, nexp)                                                          \
  {                                                                            \
    void *nb = οα;                                                             \
    nexp;                                                                      \
    arg(int, (οα - nb));                                                       \
  }                                                                            \
  arg(int, ray);                                                               \
  arg(void *, mbo)
#define B2(ray, nexp1, nexp2)                                                  \
  nexp1;                                                                       \
  Bn(ray, nexp2)
#define B3(ray, nexp1, nexp2, nexp3)                                           \
  B2(ray, nexp1, nexp2);                                                       \
  Bn(ray, nexp3)
#define B4(ray, nexp1, nexp2, nexp3, nexp4)                                    \
  B3(ray, nexp1, nexp2, nexp3);                                                \
  Bn(ray, nexp4)
#define O(nexp)                                                                \
  {                                                                            \
    void *οα = α;                                                              \
    nexp;                                                                      \
    οα -= sizeof(void *), (*(nargo_t *)οα)((void *)ο, β, οα);                  \
  }
int printf(const char *, ...);
nargo(mbo);
nargo(r2) { CR(2); }
nargo(r1) { CR(1); }
nargo(r0) { CR(0); }
nargo(lt) {
  param(int *, r);
  param(int *, l);
  CR(*l < *r);
}
nargo(sub) {
  param(int *, r);
  param(int *, l);
  int rez = *l - *r;
  CR(1, V(&rez));
}
nargo(gcd) {
  param(int *, y);
  param(int *, x);
  O(B3(0,                                              //
       B3(1, V3(x, y, lt), V3(y, x, sub), V2(x, gcd)), //
       B3(1, V3(y, x, lt), V3(x, y, sub), V2(y, gcd)), //
       V2(x, r1)));
}
nargo(n18) {
  int a = 18;
  CR(1, V(&a));
}
nargo(n12) {
  int a = 12;
  CR(1, V(&a));
}
typedef long int intptr_t;
typedef unsigned long int size_t;
void *memcpy(void *destination, const void *source, size_t num);
nargo(f0) {
  nt *pith = (void *)ο[3];
  C(pith[0], pith);
}
nargo(f1) {
  nt *pith = (void *)ο[3];
  C(pith[1], pith);
}
nargo(f2) {
  nt *pith = (void *)ο[3];
  C(pith[2], pith);
}
nargo(cb) {
  nt *pith = (void *)ο[3];
  intptr_t size = (intptr_t)ο[4];
  memcpy(α, &ο[5], size);
  α += size;
  param(nargo_t, nar);
  nar(pith, β, α);
}
nargo(mbo) {
  param(int, ray);
  param(int, size);
  void *pith[5 + size / sizeof(void *)];
  pith[0] = f0;
  pith[1] = f1;
  pith[2] = f2;
  pith[ray] = cb;
  pith[3] = ο;
  pith[4] = (void *)(intptr_t)size;
  memcpy(&pith[5], α = α - size, size);
  param(nargo_t, nar);
  nar((void *)pith, β, α);
}

#define Ray(n)                                                                 \
  nargo(hexdump##n) {                                                          \
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
nargo(logint) {
  param(int *, rez);
  printf("%d\n", *rez);
}
int main() {
  void *β = malloc(1 << 12);
  void *α = β;
  void *ο[] = {hexdump0, logint, hexdump2};
  O(B3(1, V(n18), V(n12), V(gcd)));
  free(β);
}
