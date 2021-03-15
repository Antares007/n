#include "an.h"
struct cpith {
  N((*value));
  N((*error));
};
extern int printf(const char *, ...);
N(logvalue) { printf("end\n"); }
N(logerror) { printf("error\n"); }

static N(errorray) { ((struct cpith *)op)->error(op, sp, 0, 0); }
static N(valueray) { ((nargo)narb)(op, sp, 0, 0); }

N(mb) {
  S2(nargo, nargo, narB, narA);
  narA(
      &(struct cpith){
          .value = valueray,
          .error = errorray,
      },
      sp, o, narB);
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
  N2(n1, n2), mb(o, sp, 0, 0);
  N3(n1, n2, n3), mb(o, sp, 0, 0);
  N4(n1, n2, n3, n4), mb(o, sp, 0, 0);
}

N(imul) {
  S2(int, int, a, b);
  A(int, (a * b));
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
  void *mem = malloc(1024);
  void **sp = &mem;
  sum(&o, sp, 0, 0);
  A2(int, int, 3, 2), N2(imul, printd), mb(&o, sp, 0, 0);
  free(mem);
  return 0;
}
