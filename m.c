#include "a3.h"
#include <stdio.h>
#include <stdlib.h>

N(an_arkhi) {
  void *source = ο[--α].v;
  printf("an\n");
  ο[--α].Q = 1, σ[-1].c(T());
}
N(da_arkhi) { printf("da\n"); }
N(ara_arkhi) { printf("ara\n"); }



N(test) {
// ra gvinda?
  // risi gaketeba gvinda?
  // rogoris
  //
  // (type: number, payload?: any) => {
  //  let x 
  //  if(type == 0) {
  //    x = true
  //  } else if(type == 1){
  //    if(!x) errorrr
  //  } else {
  //    ara
  //  }
  // }
  //
  // cs = 0 σ[-1]. 
  // O A N S cs. 
  //
  printf("%p\n", σ[-1].v);
  σ[ρ + 1].c(T());

}
N(os_page) { ο[α++].v = malloc(4096), σ[ρ + 1].c(T()); }
N(os_free) { free(ο[--α].v), σ[ρ + 1].c(T()); }
N(os_pith) { 
  unsigned long ws = ο[--α].Q;
  n_t S = ο[--α].c;
  n_t N = ο[--α].c;
  n_t A = ο[--α].c;
  n_t O = ο[--α].c;
}
N(os_next) {}
N(ara_gadasvla);
n_t opcodemap[4] = {os_page, os_free, os_pith, os_next};
N(os) {
  unsigned long opcode = ο[--α].Q;
  opcodemap[opcode](T());
}
int main() {
  p_t *ο = malloc(1 << 13), *σ = &ο[(1 << 13)/sizeof(p_t)];
  long α = 0, ρ = 0;
  σ[--ρ].c = os;
  σ[--ρ].c = ara_arkhi;
  σ[--ρ].c = da_arkhi;
  σ[--ρ].c = an_arkhi;
  test(T());
  free(ο);
}
