#include "m2.h"
N(one) { A(1) Or1(T); }
N(add) {
  R(long, rhs);
  R(long, lhs);
  A(rhs + lhs) Or1(T);
}
// erti erti da shekribe da.
// ο---α------------ρ----------σ
//
// D -> EEDS|012x
// D ->   EE|-S-012x
// E ->     |-E--S-012x
// E ->    1|-S-012x
// S ->   11|012x
// 1 ->    2|012x
//
#include <stdio.h>
#include <stdlib.h>
N(ix) {
  printf("ix ");
  Os1(T);
}
N(i0) {
  printf("i0 ");
  // 'dup' S1 'pid' S1 daa cmp da next1 next2 anda.
  // ο[σ - 1] == ix;
  // ο[ρ + 0] == i0;
  // ο[ρ + 1] == i1;
  // ο[ρ + 2] == i2;
}
N(i1) { printf("i1 "); }
N(i2) { printf("i2 "); }
N(crux);
N(os1) {
  printf("osx ");
  long m = (long)ο[--α];
  switch (m) {
  case 'new': {
    crux(T);
  } break;
  case 'me': {
  } break;
  case 'dup': {
  } break;
  }
}
static N(dot) {
  R(n_t, nara);
  nara(T);
}
static N(dddd0) { D4 Or0(T); }
static N(dddu) { D3 U dot(T); }
N(da) {
  n_t araarkhi = Or2;
  P O3(dddd0, dddu, araarkhi) dot(T);
}
static N(next) {
  printf("next os1");
  // Or1(T);
}
int main() {
  void **ο = malloc(512 * sizeof(void *));
  long α = 0, ρ, σ = (ρ = 512);
  A8(i0, i1, i2, os1, 128, 'new', os1, next) da(T);
  free(ο);
}
N(crux) {
  R(unsigned long, ws);
  R(n_t, os);
  R(n_t, r2);
  R(n_t, r1);
  R(n_t, r0);
  unsigned long oρ = ρ - ws;
  if (oρ < α)
    return A5(r0, r1, r2, os, ws) Or2(T);
  unsigned long oα = α, oσ = σ - ws;
  void **oο = ο + ws;
  while (α--)
    oο[α] = ο[α];
  void **nο = ο;
  long nα = 0, nρ = ws, nσ = ws;
  nο[--nρ] = os, nο[--nρ] = r2, nο[--nρ] = r1, nο[--nρ] = r0;
  ο = oο, α = oα, ρ = oρ, σ = oσ;
  A4(nο, nα, nρ, nσ) Or1(T);
}
