typedef void (*ntype)(void **, void *, void *);
#define nargo(n) void n(void **o, void *begin, void *advance)
#define arg(T, a) (*(T *)_advance = a, _advance += sizeof(T))
#define param(T, n) T n = *(T *)(advance -= sizeof(T))
#define C(n, p, ...)                                                           \
  {                                                                            \
    void *_advance = advance;                                                  \
    __VA_ARGS__;                                                               \
    ((void (*)(void *, void *, void *))n)(p, begin, _advance);                 \
  }
#define Co(n, ...) C(o[n - 'a'], o, __VA_ARGS__)
#define ray(n, i)                                                              \
  nargo(n) {                                                                   \
    ntype *on = (void *)o[31];                                                 \
    on[i]((void *)on, begin, advance);                                         \
  }
#define pith(n, o, ...)                                                        \
  void *n[32] = {__VA_ARGS__};                                                 \
  for (int i = 0; i < 32; i++)                                                 \
    if (n[i] == 0)                                                             \
  n[i] = (void *)o[i]
ray(ra, 'a' - 'a') ray(rb, 'b' - 'a') ray(rc, 'c' - 'a') ray(rd, 'd' - 'a')
    ray(re, 'e' - 'a') ray(rf, 'f' - 'a') ray(rg, 'g' - 'a') ray(rh, 'h' - 'a')
        ray(ri, 'i' - 'a') ray(rj, 'j' - 'a') ray(rk, 'k' - 'a')
            ray(rl, 'l' - 'a') ray(rm, 'm' - 'a') ray(rn, 'n' - 'a')
                ray(ro, 'o' - 'a') ray(rp, 'p' - 'a') ray(rq, 'q' - 'a')
                    ray(rr, 'r' - 'a') ray(rs, 's' - 'a') ray(rt, 't' - 'a')
                        ray(ru, 'u' - 'a') ray(rv, 'v' - 'a') ray(rw, 'w' - 'a')
                            ray(rx, 'x' - 'a') ray(ry, 'y' - 'a')
                                ray(rz, 'z' - 'a');
static void *o[32] = {ra, rb, rc, rd, re, rf, rg, rh, ri, rj, rk,
                      rl, rm, rn, ro, rp, rq, rr, rs, rt, ru, rv,
                      rw, rx, ry, rz, 0,  0,  0,  0,  0,  o};
nargo(mbrray) { C(o[30], o[31]); }
nargo(mbr) {
  param(ntype, narb);
  param(ntype, nara);
  pith(op, o, ['r' - 'a'] = (void *)mbrray, [31] = (void *)o, [30] = narb);
  C(nara, op);
}
typedef long int intptr_t;
int printf(const char *, ...);
void *malloc(unsigned long);
void free(void *);
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
nargo(one) { Co('r', arg(int, 1)); }
nargo(add2) {
  param(int, a);
  Co('r', arg(int, a + 2));
}
int main() {
  pith(p, o, ['l' - 'a'] = hexdump, ['r' - 'a'] = hexdump);
  void *begin = malloc(4096);
  void *advance = begin;
  C(mbr, p,                            //
    arg(ntype, one), arg(ntype, add2), //
    arg(ntype, mbr), arg(ntype, add2), //
    arg(ntype, mbr), arg(ntype, add2)  //
  );
  free(begin);
}
