typedef void (*n_t)(void **β, long α, long ρ, long σ);
#define N(n) void(n)(void **β, long α, long ρ, long σ)
#define S(n) static N(n)
#define Rc(n)                                                                  \
  long n##σ = (long)β[--α];                                                    \
  long n##ρ = (long)β[--α];                                                    \
  long n##α = (long)β[--α];                                                    \
  void **n##β = β[--α]
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_ω = n##β;                                                          \
    long _α = n##α;                                                            \
    long _ρ = n##ρ;                                                            \
    long _σ = n##σ;                                                            \
    void **β = _ω;                                                             \
    long α = _α;                                                               \
    long ρ = _ρ;                                                               \
    long σ = _σ;                                                               \
    __VA_ARGS__((n_t *)β)[α - 1](β, α - 1, ρ, σ);                              \
  } while (0)
S(dddu)  { O(, ρ += 3, β[α++] = β[ρ++], ); }
S(dddd0) { O(, ρ += 4, β[α++] = β[ρ + 0], ); }
N(da) {
  n_t ararkhi = β[ρ + 2];
  O(, β[--ρ] = β[--α]
    , β[--ρ] = ararkhi
    , β[--ρ] = dddu
    , β[--ρ] = dddd0
    ,);
}
S(dddd1) { O(, ρ += 4, β[α++] = β[ρ + 1], ); }
N(an) {
  n_t ararkhi = β[ρ + 2];
  O(, β[--ρ] = β[--α]
    , β[--ρ] = ararkhi
    , β[--ρ] = dddd1
    , β[--ρ] = dddu
    ,);
}
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
N(dalog) {
  void *v = β[--α];
  printf("da %p", v);
}
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
