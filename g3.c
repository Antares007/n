#include "evalmap.h"
typedef void (*nt)(void **, void *, void *);
typedef void (*nargo_t)(nt *, void *, void *);
#define nargo(n) void n(nt *ო, void *ბ, void *ა)
// param
#define param(T, n) T n = *(T *)(ა = (char *)ა - sizeof(void *))
// argument
#define arg(T, a)                                                              \
  *(T *)ოა = a;                                                                \
  ოა += sizeof(void *)
// colls
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *ოა = (void *)ა;                                                      \
    __VA_ARGS__;                                                               \
    ((void (*)())n)(p, ბ, (void *)ოა);                                         \
  }
#define CR(ray, ...) C(ო[ray], ო, __VA_ARGS__)
#define C0(...) CR(0, __VA_ARGS__)
#define C1(...) CR(1, __VA_ARGS__)
#define C2(...) CR(2, __VA_ARGS__)
// void star args
#define VSA(nexp) arg(void *, (void *)nexp);
#define VS(...) EVAL(MAP(VSA, __VA_ARGS__))
// mbo
#define Mr(ray, nexp)                                                          \
  {                                                                            \
    nexp arg(void *, (void *)(ოა - nb));                                       \
    arg(void *, mb##ray);                                                      \
    nb = ოა;                                                                   \
  }
#define M0(nexp) Mr(0, nexp)
#define M1(nexp) Mr(1, nexp)
#define M2(nexp) Mr(2, nexp)
#define B(ray, nexp, ...)                                                      \
  {                                                                            \
    nexp void *nb = ოა;                                                        \
    EVAL(MAP(CAT(M, ray), __VA_ARGS__))                                        \
  }
#define O(nexp)                                                                \
  {                                                                            \
    void *ოა = ა;                                                              \
    nexp nargo_t nar = *(nargo_t *)(ოა = (char *)ოა - sizeof(void *));         \
    (nar)((void *)ო, ბ, ოა);                                                   \
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
  param(int, r);
  param(int, l);
  CR(l < r);
}
nargo(n18) {
  int a = 18;
  CR(1, VS(&a));
}
nargo(gcd) {
  param(int, y);
  param(int, x);
  O(B(0,                                     //
      B(1, VS(x, y, lt), VS(x, y - x, gcd)), //
      B(1, VS(y, x, lt), VS(x - y, y, gcd)), //
      VS(x, r1)));
}
typedef long int intptr_t;

nargo(hexdump) {
  for (; ბ < ა; ბ++) {
    unsigned char c = *(unsigned char *)ბ & 0xff;
    if ((intptr_t)ბ % 16 == 0)
      printf("\n%03lx: %02x", (intptr_t)ბ & 0xfff, c);
    else if ((intptr_t)ბ % 8 == 0)
      printf(" %02x", c);
    else if ((intptr_t)ბ % 4 == 0)
      printf(".%02x", c);
    else
      printf("%02x", c);
  }
}
void *malloc(unsigned long);
void free(void *);

int main() {
  void *ბ = malloc(1 << 12);
  void *ა = ბ;
  void *ო[] = {hexdump, hexdump, hexdump};

  O(VS(18, 12, gcd));
  free(ბ);
}
