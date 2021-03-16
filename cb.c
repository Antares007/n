#include "an.h"
#include "mb.h"

extern int printf(const char *, ...);
N(logvalue) { printf("end\n"); }
N(logerror) { printf("error\n"); }
struct cpith o = (struct cpith){
    .value = logvalue,
    .error = logerror,
};

static N(n1) {
  printf("n1");
  // A(char *, "nice error message"), o->error(o);
  C(value);
}
static N(n2) {
  printf("n2");
  C(value);
}
static N(n3) {
  printf("n3");
  C(value);
}
static N(n4) {
  printf("n4");
  C(value);
}
static N(n5) {
  printf("n5");
  C(value);
}
static N(ne) { C(error); }

N(sum) {
  N2(n1, n2), mb(ο, σ);
  N3(n1, n2, n3), mb(ο, σ);
  N4(n1, n2, n3, n4), mb(ο, σ);
  N4(n1, n2, ne, n5), mb(ο, σ);
}

N(imul) {
  S2(int, int, a, b);
  A(int, (a / b));
  C(value);
}
N(printd) {
  S(int, d);
  printf("%d", d);
  C(value);
}

typedef unsigned long size_t;
extern void *malloc(size_t __size);
extern void free(void *__ptr);

N(ret) { C(value); }
extern int sprintf(char *, const char *, ...);
N(f) {
  S(int, a);
  A(int, a + a), C(value);
}
N(M) { A(int, 6), C(value); }
N(g) {
  S(int, a);
  A(int, a / 2), C(value);
}
N(logd) {
  S(int, d);
  printf("%d\n", d);
}
N(Mβf) { N2(M, f), MBO; }
N(fβg) { N2(f, g), MBO; }

int main() {
  void *mem = malloc(1 << 12);
  void **σ = &mem;

  struct cpith o2 = (struct cpith){
      .value = logd,
      .error = logerror,
  };
  printf("left identity\n");
  A(int, 3), N2(f, ret), MB(&o2);
  A(int, 3), f(&o2, σ);

  printf("right identity\n");
  N2(M, ret), mb(&o2, σ);
  M(&o2, σ);

  printf("associativity\n");
  N2(Mβf, g), mb(&o2, σ);
  N2(M, fβg), mb(&o2, σ);
  printf("\n");

  sum(&o, σ);
  printf("\n");
  A2(int, int, 6, 2), N2(imul, printd), MB(&o);
  printf("\n");
  free(mem);
  return 0;
}
