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
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
static N(dddddd0) {
  ρ += 6;
  ο[ρ].c(ο, α, ρ, σ);
}
static N(ddduuu) {
  ρ += 3;
  ο[α++].v = ο[ρ++].v;
  ο[α++].v = ο[ρ++].v;
  ο[ρ].c(ο, α, ρ + 1, σ);
}
N(daaa) {
  n_t araarkhi = ο[ρ + 2].c;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].c = araarkhi;
  ο[--ρ].c = ddduuu;
  ο[--ρ].c = dddddd0;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
static N(ddddd0) {
  ρ += 5;
  ο[ρ].c(ο, α, ρ, σ);
}
static N(ddduu) {
  ρ += 3;
  ο[α++].v = ο[ρ++].v;
  ο[ρ].c(ο, α, ρ + 1, σ);
}
N(daa) {
  n_t araarkhi = ο[ρ + 2].c;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].c = araarkhi;
  ο[--ρ].c = ddduu;
  ο[--ρ].c = ddddd0;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
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
N(quot);
N(os1) {
  printf("osx %lu %lu %s\n", α, ο[α - 2].Q, (char *)&ο[α - 1].Q);
  long m = (long)ο[--α].v;
  switch (m) {
  case 'new': {
    crux(ο, α, ρ, σ);
  } break;
  case 'quot': {
    quot(ο, α, ρ, σ);
  } break;
  case 'dup': {
  } break;
  }
}
static N(next) { //
  printf("next os1");
}
int main() {
  p_t *ο = malloc(512 * sizeof(void *));
  long α = 0, ρ, σ = (ρ = 512);

  ο[α++].Q = 3;
  ο[α++].Q = 6;
  ο[α++].Q = 9;

  ο[α++].c = i0;
  ο[α++].c = i1;
  ο[α++].c = i2;
  ο[α++].c = os1;
  ο[α++].Q = 128;
  ο[α++].Q = 'new';
  ο[α++].c = os1;

  ο[α++].Q = 3;
  ο[α++].Q = 'quot';
  ο[α++].c = os1;

  daaa(ο, α, ρ, σ);

  free(ο);
}
#include "./src/queue.h"
#define PROCESS_MAX_PID 1024
typedef struct {
  p_t *ο;
  long α, ρ, σ;
  void *q[2];
} crux_t;
static crux_t *cruxs[PROCESS_MAX_PID] = {0};
static int process_allocate_pid() {
  static int last = 0;
  int i;
  for (i = last + 1; i < PROCESS_MAX_PID; i++)
    if (!cruxs[i])
      return last = i, i;
  for (i = 1; i < last; i++)
    if (!cruxs[i])
      return last = i, i;
  return 0;
}
N(quot) { //
  unsigned long wc = ο[--α].Q;
  unsigned long pid = ο[--α].Q;
  printf("ai wc:%lu pid:%lu\n", wc,pid);
}
N(crux) {
  unsigned long ws = ο[--α].Q + 6;
  unsigned long oρ = ρ - ws;
  int pid;
  if (oρ < α || (pid = process_allocate_pid()) == 0)
    return ο[α++].Q = ws, ο[ρ + 2].c(ο, α, ρ, σ);
  n_t os = ο[--α].c;
  n_t r2 = ο[--α].c;
  n_t r1 = ο[--α].c;
  n_t r0 = ο[--α].c;

  p_t *oο = ο + ws;
  long oα = α, oσ = σ - ws;
  while (α--)
    oο[α].v = ο[α].v;

  p_t *nο = ο;
  long nα = 0, nρ = ws - 6, nσ = ws - 6;

  nο[--nρ].c = os;
  nο[--nρ].c = r2;
  nο[--nρ].c = r1;
  nο[--nρ].c = r0;
  crux_t *crux = (crux_t *)nο + nσ;
  crux->ο = nο;
  crux->α = nα;
  crux->ρ = nρ;
  crux->σ = nσ;
  crux->q[0] = 0;
  crux->q[1] = 0;
  cruxs[pid] = crux;

  oο[oα++].Q = pid;
  oο[oρ + 1].c(oο, oα, oρ, oσ);
}
