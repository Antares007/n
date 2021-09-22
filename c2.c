/*
function onclick(o, event, delta, depth) {
  C(o.setState, { n: o.state.n + delta });
  i += delta;
  C(o.parent, depth, counter);
}
function button(o, label, depth) {
  //  console.log(depth);
  C(o.text, label);
  C(o.on, label === "+" ? 1 : -1, depth, "click", onclick);
  if (depth) C(o.skelement, depth - 1, "div", counter, label, initstate);
}
let i = 0;
function counter(o, depth) {
  C(o.selement, "+", depth, "button", button);
  C(o.selement, "-", depth, "button", button);
  C(o.text, o.state.n + "");
}*/
#include "a3.h"
#include <stdio.h>
#include <stdlib.h>
N(button) {}
N(counter) {
  R(unsigned long, depth);
  Rpith(o);
  A5("+", depth, "button", button, 'sele') C(o, 1);
  A5("-", depth, "button", button, 'sele') C(o, 1);
  A2("o.state.n+''", 'text') C(o, 1);
}
N(i0) {}
N(i1) {}
N(i2) {}

N(os_akhali_purtseli) {
  p_t *nο = malloc(0x1000);
  nο++;
  nο[-1].q = 0;
  A(nο) C(, 1);
}
N(os_akhali_gulguli) {
  R(unsigned long, wc);
  p_t *nσ = malloc(0x1000) + 0x1000;
  long nρ = 0;
  nσ--;
  wc -= 3;
  while (wc--)
    nσ[--nρ].v = ο[--α].v;
  nσ[--nρ].v = σ[σ[0].q + 2].v;
  nσ[--nρ].v = σ[σ[0].q + 1].v;
  nσ[--nρ].v = σ[σ[0].q + 0].v;
  nσ[--nρ].v = ο[--α].v;
  nσ[--nρ].v = ο[--α].v;
  nσ[--nρ].v = ο[--α].v;
  nσ[0].q = nρ;
  A(nσ) C(, 1);
}
N(os_amotsere) {
  R(unsigned long, wc);
  R(p_t *, pο);
  long pα = (pο[-1].q = pο[-1].q + wc);
  for (long i = 1; i <= wc; i++)
    pο[pα - i].v = ο[--α].v;
  A(pο) C(, 1);
}
/*

PPPPPPPPPPPPPPPPPP
*/
#include "page.h"
#include "src/queue.h"
QUEUE queue;
typedef struct {
  QUEUE q;
  p_t *ο;
  p_t *σ;
} rigis_elementi_t;
rigis_elementi_t rigis_elementebi[67] = {0};
page_t rigis_o;
N(os_tsertili) {
  rigis_elementi_t *e = page_alloc(&rigis_o, 0);
  R(p_t *, nσ);
  R(p_t *, nο);
  e->ο = nο;
  e->σ = nσ;
  QUEUE_INSERT_TAIL(&queue, &e->q);
  C(, 1);
}
N(os_shemdegi) {
  QUEUE *q;
  if (&queue != (q = QUEUE_NEXT(&queue))) {
    QUEUE_REMOVE(q);
    p_t *qο = (p_t *)q, *qσ = qο[-1].v;
    long qα = qο[-2].q, qρ = qσ[0].q;
    qο = qο - qα - 1;
  }
}
N(akhali_purtseli) { A(0) σ[-1].c(T()); }
N(akhali_gulguli) { A(1) σ[-1].c(T()); }
N(amotsere) { A(2) σ[-1].c(T()); }
N(tsertili) { A(3) σ[-1].c(T()); }
N(shemdegi) { A(4) σ[-1].c(T()); }
n_t opcodes[] = {os_akhali_purtseli, os_akhali_gulguli, os_amotsere,
                 os_tsertili, os_shemdegi};
N(os) {
  R(unsigned long, opcode);
  opcodes[opcode](T());
}
N(an_gadasvla) { C(, 0); }

N(tskaros_gulguli) { A9(i0, i1, i2, 3, 6, 9, σ[-1].c, 7, akhali_gulguli) O; }
N(kalapotis_gulguli) { A9(i0, i1, i2, 3, 6, 9, σ[-1].c, 7, akhali_gulguli) O; }
N(o0) {
  printf("o0\n");
  os_shemdegi(T());
}
N(o1) {
  printf("o1\n");
  os_shemdegi(T());
}
N(o2) {
  printf("o2\n");
  os_shemdegi(T());
}
N(test) { C(, 1); }
int main() {
  QUEUE_INIT(&queue);
  printf("%ld %d %x\n", sizeof(rigis_elementebi), (64 + 5) % 64,
         ((1 << 5) - 1));
  page_init(&rigis_o, &rigis_elementebi, sizeof(rigis_elementebi), 5);
  printf("%lx %lx\n", rigis_o.freemap[0], rigis_o.freemap[1]);
  p_t *ο = malloc(1024 * sizeof(void *)), *σ = ο + 1024;
  long α = 0, ρ = 0;
  σ--;
  σ[--ρ].c = os;
  σ[--ρ].c = o2;
  σ[--ρ].c = o1;
  σ[--ρ].c = o0;
  σ[0].q = ρ;
  A11(kalapotis_gulguli, an_gadasvla, akhali_purtseli, daa, 2, amotsere, daa,
      tskaros_gulguli, da, tsertili, da)
  O;
  free(ο);
}
