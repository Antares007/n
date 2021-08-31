#pragma clang diagnostic ignored "-Wmultichar"
#include <stdio.h>
#include <stdlib.h>
typedef struct p_s {
  union {
    void (*c)(struct p_s *, long, long, long);
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
typedef void (*n_t)(p_t *, long, long, long);
#define N(n) void n(p_t *ο, long α, long ρ, long σ)
N(one) { ο[α++].q = 1, ο[ρ + 1].c(ο, α, ρ, σ); }
N(add) {
  long rhs = ο[--α].q;
  long lhs = ο[--α].q;
  ο[α++].q = rhs + lhs;
  ο[ρ + 1].c(ο, α, ρ, σ);
}
N(ix) {
  printf("ix ");
  ο[σ - 1].c(ο, α, ρ, σ);
}
N(i0) { printf("i0 "); }
N(i1) { printf("i1 "); }
N(i2) { printf("i2 "); }
N(crux);
N(os1) {
  printf("osx ");
  long m = (long)ο[--α].v;
  switch (m) {
  case 'new': {
    crux(ο, α, ρ, σ);
  } break;
  case 'me': {
  } break;
  case 'dup': {
  } break;
  }
}
static N(dddd0) {
  ρ += 4;
  ο[ρ].c(ο, α, ρ, σ);
}
static N(dddu) {
  ρ += 3;
  ο[ρ].c(ο, α, ρ + 1, σ);
}
N(da) {
  n_t araarkhi = ο[ρ + 2].c;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].c = araarkhi;
  ο[--ρ].c = dddu;
  ο[--ρ].c = dddd0;
  ο[α].c(ο, α - 1, ρ, σ);
}
static N(next) { //
  printf("next os1");
}
int main() {
  p_t *ο = malloc(512 * sizeof(void *));
  long α = 0, ρ, σ = (ρ = 512);
  ο[α++].c = i0;
  ο[α++].c = i1;
  ο[α++].c = i2;
  ο[α++].c = os1;
  ο[α++].Q = 128;
  ο[α++].Q = 'new';
  ο[α++].c = os1;
  ο[α++].c = next;
  da(ο, α, ρ, σ);
  free(ο);
}
N(crux) {
  unsigned long ws = ο[--α].Q;
  n_t os = ο[--α].c;
  n_t r2 = ο[--α].c;
  n_t r1 = ο[--α].c;
  n_t r0 = ο[--α].c;
  unsigned long oρ = ρ - ws;
  if (oρ < α)
    return ο[α++].c = r0, ο[α++].c = r1, ο[α++].c = r2, ο[α++].c = os,
           ο[α++].Q = ws, ο[ρ + 2].c(ο, α, ρ, σ);
  unsigned long oα = α, oσ = σ - ws;
  p_t *oο = ο + ws;
  while (α--)
    oο[α].v = ο[α].v;
  p_t *nο = ο;
  long nα = 0, nρ = ws, nσ = ws;
  nο[--nρ].c = os, nο[--nρ].c = r2, nο[--nρ].c = r1, nο[--nρ].c = r0;
  ο = oο, α = oα, ρ = oρ, σ = oσ;
  ο[α++].v = (void *)nο, ο[α++].v = (void *)nα, ο[α++].v = (void *)nρ,
  ο[α++].v = (void *)nσ, ο[ρ + 1].c(ο, α, ρ, σ);
}
