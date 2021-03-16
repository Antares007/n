#include "an.h"
struct cmbpith {
  struct cpith b;
  struct cpith *o;
  N((*narb));
};
extern int printf(const char *, ...);
N(logvalue) { printf("end\n"); }
N(logerror) { printf("error\n"); }

static N(errorray) {
  ((struct cmbpith *)o)->o->error(((struct cmbpith *)o)->o, sp);
}
static N(valueray) {
  ((struct cmbpith *)o)->narb(((struct cmbpith *)o)->o, sp);
}
N(mb) {
  S2(nargo, nargo, narB, narA);
  narA(
      (struct cpith *)&(struct cmbpith){
          .b = {.value = valueray, .error = errorray}, .o = o, .narb = narB},
      sp);
}

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
  N2(n1, n2), mb(o, sp);
  N3(n1, n2, n3), mb(o, sp);
  N4(n1, n2, n3, n4), mb(o, sp);
  N4(n1, n2, ne, n5), mb(o, sp);
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

int main() {
  void *mem = malloc(1 << 12);
  void **sp = &mem;
  sum(&o, sp);
  A2(int, int, 6, 2), N2(imul, printd), mb(&o, sp);
  free(mem);
  return 0;
}
