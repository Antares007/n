#include "n.h"
extern int printf(const char *__restrict __format, ...);
void *sp;
#define O ο(ο, β)
#define A(T, v)                                                                \
  *(T *)sp = v;                                                                \
  sp += sizeof(T)
#define S(T, n)                                                                \
  sp -= sizeof(T);                                                             \
  T n = *(T *)sp
N(narA) {
  printf("Anar\n");
  A(int, 1);
  O;
  A(int, 2);
  O;
  printf("narA\n");
}
N(narB) {
  S(int, v);
  printf("Bnar %d\n", v);
  A(int, v + 3);
  O;
  printf("narB\n");
}
Nand(narAandnarB, narA, narB);
void p(void *o, void *b) {
  S(int, v);
  printf("P %d\n", v);
}
int main() {
  int ret = 0;
  char mem[4096];
  sp = mem;
  printf("Main\n");
  narAandnarB(p, &ret);
  printf("maiN\n");
  return 0;
}
