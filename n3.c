#include "a3.h"
#include <stdio.h>
#include <stdlib.h>
N(one) { A(1) C(, 1); }
N(add) {
  R(long, r);
  R(long, l);
  A(l + r) C(, 1);
}
static N(da_an) {
  ρ += 4;
  C(, 0);
}
static N(da_da) {
  ρ += 3;
  n_t n = σ[ρ++].c;
  n(T());
}
N(da) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = da_da;
  σ[--ρ].c = da_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(aradani_ara) {
  ρ += 6;
  n_t n = σ[ρ - 3].c;
  n(T());
}
static N(aradani_da) {
  ρ += 6;
  n_t n = σ[ρ - 2].c;
  n(T());
}
static N(aradani_an) {
  ρ += 6;
  n_t n = σ[ρ - 1].c;
  n(T());
}
N(aradani) {
  σ[--ρ].c = ο[--α].c; // an
  σ[--ρ].c = ο[--α].c; // da
  σ[--ρ].c = ο[--α].c; // ara
  σ[--ρ].c = aradani_ara;
  σ[--ρ].c = aradani_da;
  σ[--ρ].c = aradani_an;
  n_t sgadasabmeli = ο[--α].c;
  sgadasabmeli(T());
}
N(an_gadasvla) { printf("an\n"), C(, 0); }
N(da_gadasvla) { printf("da\n"), C(, 1); }
N(ara_gadasvla) { printf("ara\n"), C(, 2); }
N(test_aradani) {
  A12(an_gadasvla, da_gadasvla, an_gadasvla, ara_gadasvla, aradani, da_gadasvla,
      an_gadasvla, ara_gadasvla, aradani, da_gadasvla, an_gadasvla,
      ara_gadasvla)
  aradani(T());
}
//
N(two) { A4(one, one, da, add) da(T()); }
N(seven) { A12(one, two, da, two, da, two, da, add, da, add, da, add) da(T()); }
N(an_arkhi) { printf("an\n"); }
N(da_arkhi) { printf("da\n"); }
N(ara_arkhi) { printf("ara\n"); }
int main() {
  p_t *ο = malloc(1 << 13), *σ = &ο[(1 << 13)];
  long α = 0, ρ = 0;
  σ[--ρ].c = ara_arkhi;
  σ[--ρ].c = da_arkhi;
  σ[--ρ].c = an_arkhi;
  seven(T());
  test_aradani(T());
  free(ο);
}
