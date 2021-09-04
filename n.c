#include "a.h"
#include <stdio.h>
#include <stdlib.h>
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

N(c_ara_os) { ο[α++].Q = 'ara', ο[σ - 1].c(ο, α, ρ, σ); }
N(c_da_os) { ο[α++].Q = 'da', ο[σ - 1].c(ο, α, ρ, σ); }
N(c_an_os) { ο[α++].Q = 'an', ο[σ - 1].c(ο, α, ρ, σ); }
N(c_new_os) { ο[α++].Q = 'new', ο[σ - 1].c(ο, α, ρ, σ); }
N(c_quot_os) { ο[α++].Q = 'quot', ο[σ - 1].c(ο, α, ρ, σ); }
N(nargo) {
  ο[α++].Q = 3, ο[α++].Q = 6, ο[α++].c = add;
  ο[α++].c = i0, ο[α++].c = i1, ο[α++].c = i2, ο[α++].c = ο[σ-1].c,
  ο[α++].Q = 128, ο[α++].c = c_new_os;
  ο[α++].Q = 3, ο[α++].c = c_quot_os;
  daa(ο, α, ρ, σ);
}

#include "./src/queue.h"
#define PROCESS_MAX_PID 1024
typedef struct {
  p_t *ο;
  long α, ρ, σ;
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
N(os_ara) {}
N(os_da) {}
N(os_an) {}
N(os_quot) { //
  unsigned long wc = ο[--α].Q;
  unsigned long pid = ο[--α].Q;
  crux_t *c = cruxs[pid];
  for (unsigned long i = 0; i < wc; i++)
    c->ο[c->α++].v = ο[α - wc + i].v;
  if (c->q[0] == 0)
    QUEUE_INSERT_TAIL(&queue, &c->q);
}
N(os_crux) {
  unsigned long ws = ο[--α].Q;
  long oρ = ρ - ws;
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
  printf("osx %lu %lu %s\n", α, ο[α - 2].Q, (char *)&ο[α - 1].Q);
  long m = (long)ο[--α].v;
  switch (m) {
  case 'ara': {
    os_ara(ο, α, ρ, σ);
  } break;
  case 'da': {
    os_da(ο, α, ρ, σ);
  } break;
  case 'an': {
    os_an(ο, α, ρ, σ);
  } break;
  case 'new': {
    os_crux(ο, α, ρ, σ);
  } break;
  case 'quot': {
    os_quot(ο, α, ρ, σ);
  } break;
  case 'dup': {
  } break;
  }
}
N(wnext) {
  crux_t *c = ο[--α].v;
  if (α == 0) {
    QUEUE_REMOVE(&c->q);
    c->q[0] = 0;
  }
}
int main() {
  QUEUE_INIT(&queue);
  p_t *ο = malloc(512 * sizeof(void *));
  long α = 0, ρ, σ = (ρ = 512);
  ο[--ρ].c = os_os1;
  ο[--ρ].c = os_ara;
  ο[--ρ].c = os_da;
  ο[--ρ].c = os_an;
  nargo(ο, α, ρ, σ);

  QUEUE *q;
  while (&queue != (q = QUEUE_NEXT(&queue))) {
    crux_t *c = QUEUE_DATA(q, crux_t, q);
    printf("%s \n", c->ο[c->σ - 1].v == os_os1 ? "true" : "false");
    c->ο[c->α++].v = c;
    c->ο[c->α++].c = wnext;
    daa(c->ο, c->α, c->ρ, c->σ);
  }

  free(ο);
}
