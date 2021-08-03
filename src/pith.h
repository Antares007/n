#pragma once
////////////////////////////
typedef void (*nt)(void **, void *, void *);
#define nargo(n) void n(nt *o, void *begin, void *advance)
#define sargo(n) static nargo(n)
#define arg(T, a) (*(T *)_advance = a, _advance += sizeof(T))
#define parg(T, n) T n = *(T *)(advance = (char *)advance - sizeof(T))
#define C0(n, p) ((void (*)(void *, void *, void *))n)(p, begin, advance);
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *_advance = (void *)advance;                                          \
    __VA_ARGS__;                                                               \
    ((void (*)())n)(p, begin, (void *)_advance);                               \
  }

#ifdef IMP
////////////////////////////
sargo(c3_2) { C0(o[3], o[2]); }
sargo(c4_2) { C0(o[4], o[2]); }
sargo(c21_2) { C0(((nt **)o)[2][1], o[2]); }
sargo(c20_2) { C0(((nt **)o)[2][0], o[2]); }
sargo(mb0) {
  parg(nt, a);
  parg(nt, m);
  void *oa[] = {c3_2, c21_2, o, a};
  C0(m, oa);
}
sargo(mb1) {
  parg(nt, b);
  parg(nt, m);
  void *ob[] = {c20_2, c3_2, o, b};
  C0(m, ob);
}
sargo(mb01) {
  parg(nt, b);
  parg(nt, a);
  parg(nt, m);
  void *oba[] = {c3_2, c4_2, o, a, b};
  C0(m, oba);
}
////////////////////////////
typedef long int intptr_t;
int printf(const char *, ...);
sargo(hexdump) {
  for (; begin < advance; begin++) {
    unsigned char c = *(unsigned char *)begin & 0xff;
    if ((intptr_t)begin % 16 == 0)
      printf("\n%03lx: %02x", (intptr_t)begin & 0xfff, c);
    else if ((intptr_t)begin % 8 == 0)
      printf(" %02x", c);
    else if ((intptr_t)begin % 4 == 0)
      printf(".%02x", c);
    else
      printf("%02x", c);
  }
}

////////////////////////////
void *malloc(unsigned long);
void free(void *);
#define Ma(size, ...)                                                          \
  {                                                                            \
    void *begin = malloc(size);                                                \
    void *advance = begin;                                                     \
    __VA_ARGS__;                                                               \
    free(begin);                                                               \
  }

////////////////////////////
#endif
