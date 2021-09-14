#include "a.h"
#include <stdio.h>
#include <stdlib.h>
N(one) { ο[α++].q = 1, ο[ρ + 1].c(T); }
N(add) {
  long rhs = ο[--α].q;
  long lhs = ο[--α].q;
  ο[α++].q = rhs + lhs;
  ο[ρ + 1].c(T);
}
N(c_new_os) { ο[α++].Q = 'new', ο[σ - 1].c(T); }
N(c_quot_os) { ο[α++].Q = 'quot', ο[σ - 1].c(T); }
N(ix) { printf("ix\n"), ο[σ - 1].c(T); }
N(c_next_os) { ο[α++].Q = 'next', ο[σ - 1].c(T); }
N(i0) { printf("i0\n"), c_next_os(T); }
N(i1) { printf("i1\n"), c_next_os(T); }
N(i2) { printf("i2\n"), c_next_os(T); }
N(myo) {
  crux_t *c = (crux_t *)&ο[σ];
  c->p[-1].c(ο, α, ρ, σ);
}
N(aaa) {
  ο[α++].Q = 3, ο[α++].Q = 6, ο[α++].c = add;
  ο[α++].c = i0, ο[α++].c = i1, ο[α++].c = i2, ο[α++].c = myo, ο[α++].Q = 128,
  ο[α++].c = c_new_os;
  ο[α++].Q = 3, ο[α++].c = c_quot_os;
  daa(T);
}
N(nargo) {
  // aaa(T);
  ο[α++].c = aaa;
  ο[α++].c = aaa;
  da(T);
}

#include "./src/queue.h"
#define PROCESS_MAX_PID 1024
static crux_t *cruxs[PROCESS_MAX_PID] = {0};
static QUEUE queue;
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
N(os_next) {
  QUEUE *q;
  if (&queue != (q = QUEUE_NEXT(&queue))) {
    QUEUE_REMOVE(q);
    crux_t *c = QUEUE_DATA(q, crux_t, q);
    ((p_t *)c - c->σ)[c->α - 1].c(((p_t *)c - c->σ), c->α - 1, c->σ - 4, c->σ);
  }
}
N(os_ara) {
  printf("os_ara\n");
  os_next(T);
}
N(os_da) {
  printf("os_da\n");
  os_next(T);
}
N(os_an) {
  printf("os_an\n");
  os_next(T);
}
N(os_quot) { //
  unsigned long wc = ο[--α].Q;
  unsigned long pid = ο[--α].Q;
  crux_t *c = cruxs[pid];
  for (unsigned long i = 0; i < wc; i++)
    ((p_t *)c - c->σ)[c->α++].v = ο[α - wc + i].v;
  if (c->q[0] == 0)
    QUEUE_INSERT_TAIL(&queue, &c->q);
  ο[ρ + 1].c(T);
}
// |     |                   |₀₁₂sσαqq|
// |       |₀₁₂sσαqq|     |  |₀₁₂sσαqq|
//
N(os_crux) { // ο...NNNNQα ρ.12₀₁₂Sσσαqq
  unsigned long ws = ο[--α].Q + 5;

  long oρ = ρ - ws;
  int pid;

  if (oρ < α || (pid = process_allocate_pid()) == 0)
    return ο[ρ + 2].c(ο, α + 1, ρ, σ);

  n_t os = ο[--α].c;
  n_t r2 = ο[--α].c;
  n_t r1 = ο[--α].c;
  n_t r0 = ο[--α].c;

  p_t *oο = ο + ws;
  long oα = α, oσ = σ - ws;
  crux_t *oc = (crux_t *)&ο[σ];
  oc->σ = oσ;
  oc->α = oα;

  while (α--)
    oο[α].v = ο[α].v;

  p_t *nο = ο;
  long nα = 0, nρ, nσ = (nρ = ws - 5);

  nο[--nρ].c = os;
  nο[--nρ].c = r2;
  nο[--nρ].c = r1;
  nο[--nρ].c = r0;

  cruxs[pid] = (crux_t *)&nο[nσ];
  nο[nσ + 0].Q = nσ;
  nο[nσ + 1].Q = nα;
  nο[nσ + 2].v = &ο[σ];
  nο[nσ + 3].Q = 0;

  oο[oα++].Q = pid;
  oο[oρ + 1].c(oο, oα, oρ, oσ);
}
N(os_os1) {
  // printf("osx %lu %lu %s\n", α, ο[α - 2].Q, (char *)&ο[α - 1].Q);
  long m = (long)ο[--α].v;
  switch (m) {
  case 'next': {
    os_next(ο, α, ρ, σ);
  } break;
  case 'new': {
    os_crux(ο, α, ρ, σ);
  } break;
  case 'quot': {
    os_quot(ο, α, ρ, σ);
  } break;
  }
}
int main() {
  QUEUE_INIT(&queue);
  C(, malloc(512 * sizeof(void *)), 512, 0);
  ο[--ρ].c = os_os1;
  ο[--ρ].c = os_ara;
  ο[--ρ].c = os_da;
  ο[--ρ].c = os_an;
  nargo(T);
  free(ο);
}
