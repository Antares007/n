#define IMP
#include "pith.h"
////////////////////////////
#define nargo(n) void n(void **o, void *begin, void *advance)
#define arg(T, a) (*(T *)_advance = a, _advance += sizeof(T))
#define parg(T, n) T n = *(T *)(advance = (char *)advance - sizeof(T))
#define C(n, p, ...)                                                           \
  {                                                                            \
    char *_advance = (void *)advance;                                          \
    __VA_ARGS__;                                                               \
    ((void (*)(void *, void *, void *))n)(p, begin, (void *)_advance);         \
  }
#define Co(n, ...) C(o[n - 'a'], o, __VA_ARGS__)
typedef void (*nt)(void **, void *, void *);

#ifdef IMP
////////////////////////////
// 'a', 't', 'g', 'c', 0, 0, 0, o
static nargo(r0) { (((nt *)o[7])[0])(o[7], begin, advance); }
static nargo(r1) { (((nt *)o[7])[1])(o[7], begin, advance); }
static nargo(r2) { (((nt *)o[7])[2])(o[7], begin, advance); }
static nargo(r3) { (((nt *)o[7])[3])(o[7], begin, advance); }

#define pith(n)                                                                \
  void *n[32] = {                                                              \
      ra, rb, rc, rd, re, rf, rg, rh, ri, rj, rk, rl, rm, rn, ro, rp,          \
      rq, rr, rs, rt, ru, rv, rw, rx, ry, rz, 0,  0,  0,  0,  0,  n};
#define ray(n, i)                                                              \
  static nargo(n) {                                                            \
    nt *on = (void *)o[31];                                                    \
    on[i]((void *)on, begin, advance);                                         \
  }
ray(ra, 'a' - 'a') ray(rb, 'b' - 'a') ray(rc, 'c' - 'a') ray(rd, 'd' - 'a')
    ray(re, 'e' - 'a') ray(rf, 'f' - 'a') ray(rg, 'g' - 'a') ray(rh, 'h' - 'a')
        ray(ri, 'i' - 'a') ray(rj, 'j' - 'a') ray(rk, 'k' - 'a')
            ray(rl, 'l' - 'a') ray(rm, 'm' - 'a') ray(rn, 'n' - 'a')
                ray(ro, 'o' - 'a') ray(rp, 'p' - 'a') ray(rq, 'q' - 'a')
                    ray(rr, 'r' - 'a') ray(rs, 's' - 'a') ray(rt, 't' - 'a')
                        ray(ru, 'u' - 'a') ray(rv, 'v' - 'a') ray(rw, 'w' - 'a')
                            ray(rx, 'x' - 'a') ray(ry, 'y' - 'a')
                                ray(rz, 'z' - 'a');
////////////////////////////
static nargo(mb26) { C(o[26], o[31]); }
static nargo(mb27) { C(o[27], o[31]); }
static nargo(mb28) { C(o[28], o[31]); }
static nargo(mb29) { C(o[29], o[31]); }
static nargo(mb30) { C(o[30], o[31]); }
#include <stdint.h>
// .... ....  .... ....
// .... ....  .... ....
// 0x1100
// 0x0100
// 0x1112
// 0x0120
// 0x1123
//
// C(mb, o, arg(nt, one), arg(nt, add2), 0)
// C(mb, o, arg(nt, one), arg(nt, add2), 1) <--------
// C(mb, o, arg(nt, one), arg(nt, add2), 1)
// C(mb, o, arg(nt, one), arg(nt, add2), arg(nt, add2), 0x0200)
// C(mb, o, arg(nt, one), arg(nt, add2), arg(nt, add2), arg(nt, add2), 0x1200)
//
static nargo(mb) {
  parg(uint64_t, cases);
  parg(nt, alter);
  pith(on);
  on[31] = (void *)o;
  if (cases) {
    parg(nt, narb);
    on[(cases & 0xff) - 'a'] = mb26, on[26] = narb;
    if ((cases = cases >> 8)) {
      parg(nt, narb);
      on[(cases & 0xff) - 'a'] = mb27, on[27] = narb;
      if ((cases = cases >> 8)) {
        parg(nt, narb);
        on[(cases & 0xff) - 'a'] = mb28, on[28] = narb;
        if ((cases = cases >> 8)) {
          parg(nt, narb);
          on[(cases & 0xff) - 'a'] = mb29, on[29] = narb;
        } else {
        }
      } else {
      }
    } else {
    }
  } else {
  }
  parg(nt, nara);
  C(nara, on);
}
static nargo(mbr) {
  parg(nt, narb);
  parg(nt, nara);
  pith(op);
  op['r' - 'a'] = (void *)mb30;
  op[30] = (void *)narb;
  op[31] = (void *)o;
  C(nara, op);
}
static nargo(mbl) {
  parg(nt, narb);
  parg(nt, nara);
  pith(op);
  op['l' - 'a'] = (void *)mb30;
  op[31] = (void *)o;
  op[30] = (void *)narb;
  C(nara, op);
}
////////////////////////////
typedef long int intptr_t;
int printf(const char *, ...);
static nargo(hexdump) {
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
#endif
static nargo(one) { Co('r', arg(int, 1)); }
static nargo(add2) {
  parg(int, a);
  Co('r', arg(int, a + 2));
}
static nargo(left) { Co('l'); }
static nargo(catch) {
  Co('r', {
    _advance = begin;
    arg(int, 9);
  });
}
#include <stdint.h>

nargo(nar1) {
  uint64_t ui = 0x2736;
  C(o[0], o, arg(int, ui >> 2 * 4 & 0xf));
}

int main() {
  nt np[8] = {hexdump, hexdump};
  pith(p);
  p['l' - 'a'] = hexdump;
  p['r' - 'a'] = hexdump;
  Ma(1 << 12, {
    C(nar1, np);
    uint32_t i = 'ijkl';
    uint64_t s = i;
    while (s) {
      C(hexdump, p, arg(int, s & 0xff));
      s = s >> 8;
    }
  });
  // Ma(1 << 12, C(mbl, p,                            //
  //               arg(nt, one), arg(nt, add2), //
  //               arg(nt, mbr), arg(nt, add2), //
  //               arg(nt, mbr), arg(nt, add2), //
  //               arg(nt, mbr), arg(nt, catch)))
}
