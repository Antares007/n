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
#define STATIC
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
N(o0) {
  Rpith(i);
  A(σ) C(i, 0);
}
N(o1) {
  Rpith(i);
  R(unsigned long, opcode);
  printf("opcode: %lu\n", opcode);
  A(σ) C(i, 1);
}
N(o2) {}
N(dadeσ) { A(σ) C(, 1); }
N(i0) {
  Rpith(o);
  A2(3, σ) C(o, 1);
}
N(i1) {
  Rpith(o);
  R(long, n);
  if (n != 0) {
    printf("i1\n");
    A3(n - 1, 6, σ) C(o, 1);
  }
}
N(i2) {}

N(one) { A(1) C(, 1); }
N(os0) {
  R(unsigned long, wc);
  printf("os0\n");
  p_t *nσ = malloc(0x1000) + 0x1000;
  long nρ = 0;
  nσ--;
  while (wc--)
    nσ[--nρ].v = ο[--α].v;
  nσ[0].q = nρ;
  A(nσ) C(, 1);
}
N(os1) {
  printf("os1\n");
  C(,1);
}
n_t opcodes[] = {os0,os1};
N(os) {
  R(unsigned long, opcode);
  opcodes[opcode](T());
}
N(an_gadasvla){C(,0);}
N(next) { A2(1, σ[-1].c) O; }
N(cs) { A2(0, σ[-1].c) O; }
N(source) { A9(i0, i1, i2, 3, 6, 9, σ[-1].c, 7, cs) O; }
N(sink) { A9(i0, i1, i2, 3, 6, 9, σ[-1].c, 7, cs) O; }
int main() {
  p_t *ο = malloc(1024 * sizeof(void *)), *σ = ο + 1024;
  long α = 0, ρ = 0;
  σ--;
  σ[--ρ].c = os;
  σ[--ρ].c = o2;
  σ[--ρ].c = o1;
  σ[--ρ].c = o0;
  σ[0].q = ρ;
  A7(sink, an_gadasvla, source, daa, 2, next, daa) O;
  free(ο);
}
