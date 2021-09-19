#include "a3.h"
#include <stdio.h>
#include <stdlib.h>

N(an_arkhi) { printf("an\n"); }
N(da_arkhi) { printf("da\n"); }
N(ara_arkhi) { printf("ara\n"); }

N(test) {
  printf("%p\n", σ[-1].v);
  σ[ρ + 1].c(T());
}
N(os_page) { ο[α++].v = malloc(4096), σ[ρ + 1].c(T()); }
N(os_free) { free(ο[--α].v), σ[ρ + 1].c(T()); }
N(os_pith) {
  ο[--α].v;
};
N(os_next);
N(ara_gadasvla);
n_t opcodemap[4] = {os_page, os_free, os_pith, os_next};
N(os) {
  unsigned long opcode = ο[--α].Q;
  opcodemap[opcode](T());
}

int main() {
  p_t *ο = malloc(1 << 13), *σ = &ο[(1 << 13)];
  long α = 0, ρ = 0;
  σ[--ρ].c = os;
  σ[--ρ].c = ara_arkhi;
  σ[--ρ].c = da_arkhi;
  σ[--ρ].c = an_arkhi;
  test(T());
  free(ο);
}
