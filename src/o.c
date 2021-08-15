/*             init                           next
   ...........................................................
        a|              |r      .             fXXe
    o* - 0123456789abcdef - s   .             dXXc
         XXXXXXXXXXXXXXXX       .           a|    |r
         rsp - fXXe             .  o* - 0123456789abcdef - s
               dXXc             .       XXXXXXXXXXXXXXXX
               bXXa             .       rsp - bXXa
               9XX8             .             9XX8
               7XX6             .             7XX6
               5XX4             .             5XX4
               3XX2             .             3XX2
               1XX0             .             1XX0
                        0 <= a <= r <= s                    */
typedef void (*n_t)(void **o, long a, long r, long s);
#define N(n) void n(void **o, long a, long r, long s)
#define S(n) static N(n)
N(dot) {
  n_t nar = o[--a];
  nar(o, a, r, s);
}
S(r0) { ((n_t *)o)[r + 0](o, a, r, s); }
S(r1) { ((n_t *)o)[r + 1](o, a, r, s); }
S(r2) { ((n_t *)o)[r + 2](o, a, r, s); }
S(dddu) { r += 4, ((n_t *)o)[r - 1](o, a, r, s); }
S(dddd0) { r += 4, ((n_t *)o)[r](o, a, r, s); }
N(da) {
  n_t narb = o[--a];
  n_t nara = o[--a];
  n_t araarkhi = o[r + 2];
  o[--r] = narb;
  o[--r] = araarkhi;
  o[--r] = dddu;
  o[--r] = dddd0;
  nara(o, a, r, s);
}
S(dddddd0) { r += 6, r0(o, a, r, s); }
S(ddduuu) {
  r += 3, o[a++] = o[r++], o[a++] = o[r++], o[a++] = o[r++], dot(o, a, r, s);
}
N(da3) {
  n_t araarkhi = o[r + 2];
  o[--r] = o[--a];
  o[--r] = o[--a];
  o[--r] = o[--a];
  o[--r] = araarkhi;
  o[--r] = ddduuu;
  o[--r] = dddddd0;
  dot(o, a, r, s);
}
S(dddd1) { r += 4, ((n_t *)o)[r + 1](o, a, r, s); }
N(an) {
  n_t narb = o[--a];
  n_t nara = o[--a];
  n_t araarkhi = o[r + 2];
  o[--r] = narb;
  o[--r] = araarkhi;
  o[--r] = dddd1;
  o[--r] = dddu;
  nara(o, a, r, s);
}
N(one) {
  o[a++] = (void *)1;
  r1(o, a, r, s);
}
N(add) {
  long rhs = (long)o[--a];
  long lhs = (long)o[--a];
  o[a++] = (void *)(rhs + lhs), r1(o, a, r, s);
}
#define _(o, a, v) o[a++] = v
#define A5(o, a, _1, _2, _3, _4, _5)                                           \
  _(o, a, _1), _(o, a, _2), _(o, a, _3), _(o, a, _4), _(o, a, _5)
N(two) { A5(o, a, one, one, da, add, da), dot(o, a, r, s); }
#define A o[a++] =
N(seven) {
  A one, A two, A da, o[a++] = add, A da, A two, A da, A add, A da, A two, A da,
                      A add, A da, dot(o, a, r, s);
}
N(talloc) {
  unsigned long ws = (unsigned long)o[--a];
  if (r < a + ws) {
    r2(o, a, r, s);
  } else {
    unsigned long n = a;
    while (n--)
      o[ws + n] = o[n];
    o[ws + a++] = (void *)ws;
    r1(o + ws, a, r - ws, s - ws);
  }
}
#include <stdio.h>
S(start) {
  long dS = (long)o[--a];
  long dR = (long)o[--a];
  long dA = (long)o[--a];
  void **dO = o[--a];
  char *mode = o[--a];
  char *fname = o[--a];
  FILE *fd = fopen(fname, mode);
  if (fd)
    0;

  printf("start\n");
}
S(next) {}
S(end) {}
S(open1) {
  unsigned long rn, sn = rn = (unsigned long)o[--a];
  void **on = o - sn;
  long an = 0;
  on[an++] = o[--a];
  on[an++] = o[--a];
  on[--rn] = end;
  on[--rn] = next;
  on[--rn] = start;
  o[a++] = on, o[a++] = (void *)an, o[a++] = (void *)rn, o[a++] = (void *)sn;
  r1(o, a, r, s);
}
N(open) {
  o[a++] = (void *)128;
  o[a++] = talloc;
  o[a++] = open1;
  o[a++] = da;
  dot(o, a, r, s);
}

N(pipe3_1) {
  long dS = (long)o[--a];
  long dR = (long)o[--a];
  long dA = (long)o[--a];
  void **dO = o[--a];

  long sS = (long)o[--a];
  long sR = (long)o[--a];
  long sA = (long)o[--a];
  void **sO = o[--a];

  sO[sA++] = dO;
  sO[sA++] = (void *)dA;
  sO[sA++] = (void *)dR;
  sO[sA++] = (void *)dS;
  ((n_t *)sO)[sR](sO, sA, sR, sS);
  r1(o, r, s, a);
}
N(pipe3) { A da3, A pipe3_1, A da, dot(o, a, r, s); }
#include <stdlib.h>
N(aralog) { printf("ara"); }
N(dalog) {
  void *v = o[--a];
  printf("da %p", v);
}
N(anlog) { printf("an"); }

// main
// "src/file1.c" "r" open "src/file2.c" "a" open pipe3.
int main() {
  long a = 0, r, s = r = 512;
  void **o = malloc(s * sizeof(void *));
  o[--r] = aralog, o[--r] = dalog, o[--r] = anlog;
  A "src/o.c", A "r", A open, A "src/o.u", A "a", A open, A pipe3,
      dot(o, a, r, s);
  free(o);
  return 0;
}
