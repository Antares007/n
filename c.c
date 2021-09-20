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
N(o0) {
  Rpith(i);
  A(σ) C(i, 0);
}
N(o1) {
  Rpith(i);
  A(σ) C(i, 1);
}
N(o2) {}
N(i0) {
  Rpith(o);
  A(σ) C(o, 1);
}
N(i1) {
  Rpith(o);
  R(long, n);
  if(n!=0){
  printf("i1\n");
   A2(n-1, σ) C(o, 1);
  }
}
N(i2) {}
int main() {
  p_t *ο = malloc(0x3000), *oσ = ο + 0x2000, *iσ = ο + 0x3000;
  long α = 0, oρ = 0, iρ = 0;
  oσ--;
  oσ[0].q = -3;
  oσ[--oρ].c = o2;
  oσ[--oρ].c = o1;
  oσ[--oρ].c = o0;

  iσ--;
  iσ[0].q = -3;
  iσ[--iρ].c = i2;
  iσ[--iρ].c = i1;
  iσ[--iρ].c = i0;

  A2(99,iσ) C(o, 0);

  free(ο);
}
