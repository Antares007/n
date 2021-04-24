#pragma once
////////////////////////////
#define nargo(n) static void n(void **o, void *begin, void *advance)
#define arg(T, a) (*(T *)_advance = a, _advance += sizeof(T))
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
// 'a', 't', 'g', 'c', 0, 0, 0, o
nargo(r0) { (((nt *)o[7])[0])(o[7], begin, advance); }
nargo(r1) { (((nt *)o[7])[1])(o[7], begin, advance); }
nargo(r2) { (((nt *)o[7])[2])(o[7], begin, advance); }
nargo(r3) { (((nt *)o[7])[3])(o[7], begin, advance); }
nargo(c47) { C(o[4], o[7]); }
nargo(c57) { C(o[5], o[7]); }
nargo(c67) { C(o[6], o[7]); }

#define MAKEmb(i)                                                              \
  nargo(mb##i) {                                                               \
    parg(nt, narb);                                                            \
    parg(nt, nara);                                                            \
    nt p[8] = {r0, r1, r2, r3, 0, 0, narb, (void *)o};                         \
    p[i] = c67;                                                                \
    C(nara, p);                                                                \
  }
MAKEmb(0) MAKEmb(1) MAKEmb(2) MAKEmb(3);
nargo(mb) { mb0(o, begin, advance); }

////////////////////////////
typedef long int intptr_t;
int printf(const char *, ...);
nargo(hexdump) {
  for (; begin < advance; begin++) {
    unsigned char c = *(unsigned char *)begin & 0xff;
    if ((intptr_t)begin % 16 == 0)
      printf("\n%p: %02x", begin, c);
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
#define Co(n, ...) C(o[n], o, __VA_ARGS__)
#define C0(...) Co(0, __VA_ARGS__)
#define C1(...) Co(1, __VA_ARGS__)
#define C2(...) Co(2, __VA_ARGS__)
#define C3(...) Co(3, __VA_ARGS__)

////////////////////////////
#endif
