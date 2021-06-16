typedef void (*nt)(void **, void *, void *);
typedef void (*nargo_t)(nt *, void *, void *);
#define nargo(n) void n(nt *ο, void *β, void *α)
#define param(T, n) T n = *(T *)(α -= sizeof(void *))
#define arg(T, a) (*(T *)οα = a, οα += sizeof(void *))
// colls
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *οα = (void *)α;                                                      \
    __VA_ARGS__;                                                               \
    ((void (*)())n)(p, β, (void *)οα);                                         \
  }
#define CR(ray, ...) C(ο[ray], ο, __VA_ARGS__)
#define C0(...) CR(0, __VA_ARGS__)
#define C1(...) CR(1, __VA_ARGS__)
#define C2(...) CR(2, __VA_ARGS__)

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
  nb = οα;                                                                     \
  nexp;                                                                        \
  arg(void *, (void *)(οα - nb));                                              \
  arg(void *, mb##ray)
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
    void *οα = α, *nb;                                                         \
    ((void)nb);                                                                \
    nexp;                                                                      \
    οα -= sizeof(void *), (*(nargo_t *)οα)((void *)ο, β, οα);                  \
  }
#define MBO(ray)                                                               \
  nargo(mb##ray) {                                                             \
    param(void *, size);                                                       \
    printf("hey %p\n", size);                                                  \
  }
int printf(const char *, ...);
MBO(0)
MBO(1)
MBO(2)
nargo(r1) { CR(1); }
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

nargo(hexdump) {
  for (; β < α; β++) {
    unsigned char c = *(unsigned char *)β & 0xff;
    if ((intptr_t)β % 16 == 0)
      printf("\n%03lx: %02x", (intptr_t)β & 0xfff, c);
    else if ((intptr_t)β % 8 == 0)
      printf(" %02x", c);
    else if ((intptr_t)β % 4 == 0)
      printf(".%02x", c);
    else
      printf("%02x", c);
  }
}
void *malloc(unsigned long);
void free(void *);

int main() {
  void *β = malloc(1 << 12);
  void *α = β;
  void *ο[] = {hexdump, hexdump, hexdump};

  O(V3(n18, n12, gcd));
  free(β);
}
