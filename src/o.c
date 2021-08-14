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
S(dot) {
  n_t nar = o[--a];
  nar(o, a, r, s);
}
S(r1) { ((n_t *)o)[r + 1](o, a, r, s); }
S(r2) { ((n_t *)o)[r + 2](o, a, r, s); }
N(one) {
  o[a++] = (void *)1;
  r1(o, a, r, s);
}
N(add) {
  long rhs = (long)o[--a];
  long lhs = (long)o[--a];
  o[a++] = (void *)(rhs + lhs), r1(o, a, r, s);
}
N(two) {
  o[a++] = one, o[a++] = one, o[a++] = da, o[a++] = add, o[a++] = da,
  dot(o, a, r, s);
}
N(seven) {
  o[a++] = one, o[a++] = two, o[a++] = da, o[a++] = add, o[a++] = da,
  o[a++] = two, o[a++] = da, o[a++] = add, o[a++] = da, o[a++] = two,
  o[a++] = da, o[a++] = add, o[a++] = da, dot(o, a, r, s);
}
// N(vvv);
// N(ttt){
//  void *oo = o;
//  o+=2;
//  o[a++] = oo;
//  vvv(o,a,r,s);
//}
N(talloc) {
  unsigned long ws = (unsigned long)o[--a];
  if (r < a + ws) {
    r2(o, a, r, s);
  } else {
    unsigned long n = a;
    while (n--)
      o[ws + n] = o[n];
    o[ws + a++] = (void*)ws;
    r1(o + ws, a, r - ws, s - ws);
  }
}

#include <stdio.h>
#include <stdlib.h>
N(aralog) { printf("ara"); }
N(dalog) {
  void *v = o[--a];
  printf("da %p", v);
}
N(anlog) { printf("an"); }
int main() {
  long a = 0, r, s = r = 512;
  void **o = malloc(s * sizeof(void *));
  o[--r] = aralog, o[--r] = dalog, o[--r] = anlog;
  o[a++] = (void *)9;
  o[a++] = (void *)2;
  o[a++] = talloc;
  dot(o, a, r, s);
  free(o);
  return 0;
}
