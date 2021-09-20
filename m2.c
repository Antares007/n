#include "a3.h"
#include <stdio.h>
#include <stdlib.h>

N(test) {
  // ra gvinda? risi gaketeba gvinda? rogoris
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
N(us_an) {
  printf("us an\n");
  p_t *osσ = &ο[--α];
  long osρ = ο[--α].Q;
  σ[-1].v = osσ;
  σ[-2].Q = osρ;
  //ο[α++]
}
N(us_da) { printf("us da\n");
}
N(us_ara) { printf("us ara\n");
}
N(os_an) {
  printf("os an\n");
  p_t *nσ = (malloc(0x1000) + 0x1000 - sizeof(void*));
  long nρ = -ο[--α].Q;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;
  nσ[--nρ].c = ο[--α].c;

  ο[α++].Q = ρ;
  ο[α++].v = σ;
  nσ[nρ + 0].c(ο, α, nρ, nσ);
}
N(os_da  ) { printf("os da\n");  }
N(os_ara ) { printf("os ara\n"); }
int main() {
  p_t *ο = malloc(1 << 13), *σ = &ο[(1 << 13) / sizeof(p_t) - 1];
  long α = 0, ρ = 0;
  σ[--ρ].c = os_ara;
  σ[--ρ].c = os_da;
  σ[--ρ].c = os_an;
  σ[0].q = ρ;

  ο[α++].c = us_an;
  ο[α++].c = us_da;
  ο[α++].c = us_ara;
  ο[α++].Q = 2;
  σ[ρ + 0].c(T());

  free(ο);
}
