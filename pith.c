#define IMP
#include "pith.h"
#ifdef IMP
////////////////////////////
#define pith(n, b, ...)                                                        \
  void *n[32] = {__VA_ARGS__};                                                 \
  for (int i = 0; i < 32; i++)                                                 \
    if (n[i] == 0)                                                             \
  n[i] = (void *)b[i]
#define ray(n, i)                                                              \
  static nargo(n) {                                                            \
    ntype *on = (void *)(o[31]);                                               \
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
static void **trio() {
  static void *p[32] = {
      ra, rb, rc, rd, //
      re, rf, rg, rh, //
      ri, rj, rk, rl, //
      rm, rn, ro, rp, //
      rq, rr, rs, rt, //
      ru, rv, rw,     //
      rx, ry, rz,     //
      0,  0,  0,  0,  //
      0,  p           //
  };
  return p;
}
////////////////////////////
static nargo(mb27) { C(o[27], o[31]); }
static nargo(mb28) { C(o[28], o[31]); }
static nargo(mb29) { C(o[29], o[31]); }
static nargo(mb30) { C(o[30], o[31]); }
#include <stdint.h>
static nargo(mb) {
  param(uint64_t, rays);
  pith(op, trio(), [31] = (void *)o);
    
  while (rays) {
    int r = (rays & 0xff) - 'a';
    param(ntype, n);
    
    rays = rays >> 8;
  }
  param(ntype, nara);
  C(nara, op);
}
static nargo(mbr) {
  param(ntype, narb);
  param(ntype, nara);
  pith(op, trio(),                 //
       ['r' - 'a'] = (void *)mb30, //
       [30] = (void *)narb,        //
       [31] = (void *)o            //
  );
  C(nara, op);
}
static nargo(mbl) {
  param(ntype, narb);
  param(ntype, nara);
  pith(op, trio(),
       ['l' - 'a'] = (void *)mb30, [31] = (void *)o, [30] = (void *)narb);
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
  param(int, a);
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
int main() {
  pith(p, trio(), ['l' - 'a'] = hexdump, ['r' - 'a'] = hexdump);

  Ma(1 << 12, {
    uint32_t i = 'abcd';
    uint64_t s = i;
    while (s) {
      C(hexdump, p, arg(int, s & 0xff));
      s = s >> 8;
    }
  });
  // Ma(1 << 12, C(mbl, p,                            //
  //               arg(ntype, one), arg(ntype, add2), //
  //               arg(ntype, mbr), arg(ntype, add2), //
  //               arg(ntype, mbr), arg(ntype, add2), //
  //               arg(ntype, mbr), arg(ntype, catch)))
}
