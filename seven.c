#include "aradani.h"
N(one) {
  O(, β[α++] = (void*)1
    , β[α++] = β[ρ + 1]
    ,);
}
N(add) {
  long rhs = (long)β[--α];
  long lhs = (long)β[--α];
  O(, β[α++] = (void *)(rhs + lhs)
    , β[α++] = β[ρ + 1]
    ,);
}
N(two) { 
  O(, β[α++] = one
    , β[α++] = one
    , β[α++] = da
    , β[α++] = add
    , β[α++] = da 
    ,);
}
N(seven) {
  O(, β[α++] = one
    , β[α++] = two
    , β[α++] = da
    , β[α++] = add
    , β[α++] = da 
    , β[α++] = two
    , β[α++] = da
    , β[α++] = add
    , β[α++] = da 
    , β[α++] = two
    , β[α++] = da
    , β[α++] = add
    , β[α++] = da 
    ,);
}

#include <stdio.h>
#include <stdlib.h>

N(aralog) { printf("ara"); }
N(dalog) { void *v = β[--α]; printf("da %p", v); }
N(anlog) { printf("an"); }

int main() {
  long α = 0;
  long ρ = 512;
  long σ = ρ;
  void **β = malloc(σ * sizeof(void *));
  O(, β[--ρ] = aralog
    , β[--ρ] = dalog
    , β[--ρ] = anlog
    , β[α++] = seven
    ,);
  free(β);
  return 0;
}
