#include <stdio.h>
#include <stdlib.h>
#pragma clang diagnostic ignored "-Wmultichar"
typedef struct p_s {
  union {
    void (*c)(struct p_s *, long, long, struct p_s *);
    void *v;
    char b;
    short w;
    int d;
    long q;
    unsigned char B;
    unsigned short W;
    unsigned int D;
    unsigned long Q;
  };
} p_t;
typedef void (*n_t)(p_t *, long, long, p_t *);
#define N(n) void n(p_t *ο, long α, long ρ, p_t *σ)
#define T(n) n##ο, n##α, n##ρ, n##σ

N(one) {
  ο[α++].Q = 1;
  σ[ρ + 1].c(T());
}
N(add) {
  long r = ο[--α].q;
  long l = ο[--α].q;
  ο[α++].q = l + r;
  σ[ρ + 1].c(T());
}
static N(da_an) {
  ρ += 4;
  σ[ρ].c(T());
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
  ο[α - 1].c(ο, α - 1, ρ, σ);
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
N(an_gadasvla) { printf("an\n"), σ[ρ + 0].c(T()); }
N(da_gadasvla) { printf("da\n"), σ[ρ + 1].c(T()); }
N(ara_gadasvla) { printf("ara\n"), σ[ρ + 2].c(T()); }
N(test_aradani) {
  ο[α++].c = an_gadasvla;
  ο[α++].c = da_gadasvla;
  ο[α++].c = an_gadasvla;
  ο[α++].c = ara_gadasvla;
  ο[α++].c = aradani;
  ο[α++].c = da_gadasvla;
  ο[α++].c = an_gadasvla;
  ο[α++].c = ara_gadasvla;
  ο[α++].c = aradani;
  ο[α++].c = da_gadasvla;
  ο[α++].c = an_gadasvla;
  ο[α++].c = ara_gadasvla;
  aradani(T());
}
//
N(two) {
  ο[α++].c = one;
  ο[α++].c = one;
  ο[α++].c = da;
  ο[α++].c = add;
  da(T());
}
N(seven) {
  ο[α++].c = one;
  ο[α++].c = two;
  ο[α++].c = da;
  ο[α++].c = two;
  ο[α++].c = da;
  ο[α++].c = two;
  ο[α++].c = da;
  ο[α++].c = add;
  ο[α++].c = da;
  ο[α++].c = add;
  ο[α++].c = da;
  ο[α++].c = add;
  da(T());
}
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
