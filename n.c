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
N(wnext);
int main() {
  QUEUE_INIT(&queue);
  p_t *ο = malloc(512 * sizeof(void *));
  long α = 0, ρ, σ = (ρ = 512);

  ο[α++].Q = 3;
  ο[α++].Q = 6;
  ο[α++].c = add;

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

  QUEUE *q;
  while (&queue != (q = QUEUE_NEXT(&queue))) {
    crux_t *c = QUEUE_DATA(q, crux_t, q);
    printf("%s ", c->ο[c->σ - 1].v == os1 ? "true" : "false");
    c->ο[c->α++].v = c;
    c->ο[c->α++].c = wnext;
    daa(c->ο, c->α, c->ρ, c->σ);
  }

  free(ο);
}
N(wnext) {
  crux_t *c = ο[--α].v;
  if (α == 0) {
    QUEUE_REMOVE(&c->q);
    c->q[0] = 0;
  }
}
N(quot) { //
  unsigned long wc = ο[--α].Q;
  unsigned long pid = ο[--α].Q;
  crux_t *c = cruxs[pid];
  // printf("%s ", c->ο[c->σ - 1].v == os1 ? "true" : "false");
  // printf("ai wc: %lu pid: %lu\n", wc, pid);
  for (unsigned long i = 0; i < wc; i++)
    c->ο[c->α++].v = ο[α - wc + i].v;
  if (c->q[0] == 0)
    QUEUE_INSERT_TAIL(&queue, &c->q);

  // c->ο[c->ρ + 0].c(ο, α, ρ, σ);
  // c->ο[c->ρ + 1].c(ο, α, ρ, σ);
  // c->ο[c->ρ + 2].c(ο, α, ρ, σ);
}
N(crux) {
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
  crux_t *c = (crux_t *)nο + nσ;
  c->ο = nο;
  c->α = nα;
  c->ρ = nρ;
  c->σ = nσ;
  c->q[0] = 0;
  c->q[1] = 0;
  cruxs[pid] = c;

  oο[oα++].Q = pid;
  oο[oρ + 1].c(oο, oα, oρ, oσ);
}
