#pragma once
////////////////////////////
#define nargo(n) void n(nt *o, void *begin, void *advance)
#define sargo(n) static nargo(n)
#define arg(T, a) (*(T *)_advance = a, _advance += sizeof(T))
#define ARG_int(a) arg(int, a);
#define ARG_nt(a) arg(void *, a);
#include "evalmap.h"
#define args(T, ...) EVAL(MAP(CAT(ARG_, T), __VA_ARGS__))
#define parg(T, n) T n = *(T *)(advance = (char *)advance - sizeof(T))
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *_advance = (void *)advance;                                          \
    __VA_ARGS__;                                                               \
    ((void (*)(void *, void *, void *))n)(p, begin, (void *)_advance);         \
  }
typedef void (*nt)(void **, void *, void *);

#ifdef IMP

////////////////////////////
typedef long int intptr_t;
int printf(const char *, ...);
nargo(hexdump) {
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
