#include "n.h"
#include <stdio.h>
void *σπ;
#define O o(o, b)
#define A(T, v)                                                                \
  *(T *)σπ = v;                                                                  \
  σπ += sizeof(T)
#define S(T, n)                                                                \
  σπ -= sizeof(T);                                                               \
  T n = *(T *)σπ
typedef int d;
typedef struct dd {
  int x;
  int y;
} dd;
N(narA) {
  printf("Anar\n");
  A(d, 1);
  O;
  A(d, 2);
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
  σπ = mem;
  printf("Main\n");
  narAandnarB(p, &ret);
  printf("maiN\n");
  return 0;
}
