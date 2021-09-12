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
N(ix) {
  printf("ix ");
  ο[σ - 1].c(T);
}
N(i0) { printf("i0 "); }
N(i1) { printf("i1 "); }
N(i2) { printf("i2 "); }

N(c_new_os) {
  ο[α++].Q = 'new';
  ο[σ - 1].c(T);
}
N(c_quot_os) {
  ο[α++].Q = 'quot';
  ο[σ - 1].c(T);
}

N(nargo) {
  ο[α++].Q = 3, ο[α++].Q = 6, ο[α++].c = add;
  ο[α++].c = i0, ο[α++].c = i1, ο[α++].c = i2, ο[α++].c = ο[σ - 1].c,
  ο[α++].Q = 128, ο[α++].c = c_new_os;
  ο[α++].Q = 3, ο[α++].c = c_quot_os;
  daa(T);
}

#include "./src/queue.h"
#define PROCESS_MAX_PID 1024
typedef struct {
  p_t *ο;
  unsigned long α, ρ, σ;
  void *q[2];
} crux_t;
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
  if (&queue == (q = QUEUE_NEXT(&queue)))
    return;
  QUEUE_REMOVE(q);
  crux_t *c = QUEUE_DATA(q, crux_t, q);
  c->ο[c->α - 1].c(c->ο, c->α - 1, c->ρ, c->σ);
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
    c->ο[c->α++].v = ο[α - wc + i].v;
  if (c->q[0] == 0)
    QUEUE_INSERT_TAIL(&queue, &c->q);
  ο[ρ + 1].c(T);
}
N(os_crux) { // ... n_t n_t n_t n_t Q | .xx ...
  unsigned long ws = ο[--α].Q;
  //crux_t *ξ = (crux_t*)&ο[σ];
  long oρ = ρ - ws;
  int pid;
  if ((ρ - ws) < α || (pid = process_allocate_pid()) == 0)
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
  long nα = 0, nρ, nσ = (nρ = ws - 6);

  nο[--nρ].c = os;
  nο[--nρ].c = r2;
  nο[--nρ].c = r1;
  nο[--nρ].c = r0;
  crux_t *c = (crux_t *)(nο + nσ);
  c->ο = nο;
  c->α = nα;
  c->ρ = nρ;
  c->σ = nσ;
  c->q[0] = 0;
  cruxs[pid] = (crux_t *)c;

  oο[oα++].Q = pid;
  oο[oρ + 1].c(oο, oα, oρ, oσ);
}
N(os_os1) {
  // printf("osx %lu %lu %s\n", α, ο[α - 2].Q, (char *)&ο[α - 1].Q);
  long m = (long)ο[--α].v;
  switch (m) {
  case 'new': {
    os_crux(ο, α, ρ, σ);
  } break;
  case 'quot': {
    os_quot(ο, α, ρ, σ);
  } break;
  }
}
N(wnext) {
  printf("end\n");
}
int main() {
  QUEUE_INIT(&queue);
  C(, malloc(512 * sizeof(void *)), 512);
  ο[--ρ].c = os_os1;
  ο[--ρ].c = os_ara;
  ο[--ρ].c = os_da;
  ο[--ρ].c = os_an;
  nargo(T);

  free(ο);
}
