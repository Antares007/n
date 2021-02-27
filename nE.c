extern int printf(const char *__restrict __format, ...);
void *sp;
static void narA(void ο(void *, void *), void *β) {
  printf("Anar\n");
  *(int *)sp = 1;
  sp += sizeof(int);
  ο(ο, β);
  *(int *)sp = 2;
  sp += sizeof(int);
  ο(ο, β);
  printf("narA\n");
}
static void narB(void ο(void *, void *), void *β) {
  sp -= sizeof(int);
  int v = *(int *)sp;
  printf("Bnar %d\n", v);
  *(int *)sp = v + 3;
  sp += sizeof(int);
  ο(ο, β);
  printf("narB\n");
}
static void narAandnarB_pith(void ο(void *, void *), void *β);
static void narAandnarB(void ο(void *, void *), void *β) {
  narA((void *)narAandnarB_pith, (void *[]){ο, β});
}
static void narAandnarB_pith(void ο(void *, void *), void *β) {
  ο = ((void **)β)[0];
  β = ((void **)β)[1];
  narB(ο, β);
};
void p(void *o, void *b) {
  sp -= sizeof(int);
  int v = *(int *)sp;
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
