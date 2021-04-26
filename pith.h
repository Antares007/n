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
    ((void (*)(void *, void *, void *))n)(p, begin, (void *)_advance);         \
  }

#ifdef IMP
////////////////////////////
sargo(r70o7) { C0(((nt **)o)[7][0], (void *)o[7]); }
sargo(r71o7) { C0(((nt **)o)[7][1], (void *)o[7]); }
sargo(r72o7) { C0(((nt **)o)[7][2], (void *)o[7]); }
sargo(r73o7) { C0(((nt **)o)[7][3], (void *)o[7]); }
sargo(r4o7) { C0(o[4], o[7]); }
sargo(r5o7) { C0(o[5], o[7]); }
sargo(r6o7) { C0(o[6], o[7]); }
sargo(mb) {
  parg(uint64_t, conf);
  if (conf < 4) {
    parg(nt, narb);
    parg(nt, nara);
    void *ob[8] = {r70o7, r71o7, r72o7, r73o7, 0, 0, narb, o};
    ob[conf] = r6o7;
    C0(nara, ob);
  } else if (conf < 0x100) {
    parg(nt, narc);
    parg(nt, narb);
    parg(nt, nara);
    void *ob[8] = {r6o7, r6o7, r6o7, r6o7, 0, narb, narc, o};
    ob[conf & 0x3] = r5o7;
    C0(nara, ob);
  } else if (conf < 0x1000) {
    parg(nt, nard);
    parg(nt, narc);
    parg(nt, narb);
    parg(nt, nara);
    void *ob[8] = {r6o7, r6o7, r6o7, r6o7, narb, narc, nard, o};
    ob[conf & 0x3] = r5o7;
    ob[(conf >> 4) & 0x3] = r4o7;
    C0(nara, ob);
  } else
    C(o[1], o, args(int32_t, 'errr'));
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
