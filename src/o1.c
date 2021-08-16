typedef void (*n_t)(void **ω, long α, long ρ, long σ);
#define N(n) void(n)(void **ω, long α, long ρ, long σ)
#define S(n) static N(n)
#define Rc(n)                                                                  \
  long n##σ = (long)ω[--α];                                                    \
  long n##ρ = (long)ω[--α];                                                    \
  long n##α = (long)ω[--α];                                                    \
  void **n##ω = ω[--α]
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_ω = n##ω;                                                          \
    long _α = n##α;                                                            \
    long _ρ = n##ρ;                                                            \
    long _σ = n##σ;                                                            \
    void **ω = _ω;                                                             \
    long α = _α;                                                               \
    long ρ = _ρ;                                                               \
    long σ = _σ;                                                               \
    __VA_ARGS__((n_t *)ω)[α - 1](ω, α - 1, ρ, σ);                              \
  } while (0)
S(dddu)  { O(, ρ += 3, ω[α++] = ω[ρ++], ); }
S(dddd0) { O(, ρ += 4, ω[α++] = ω[ρ + 0], ); }
N(da) {
  n_t ararkhi = ω[ρ + 2];
  O(, ω[--ρ] = ω[--α]
    , ω[--ρ] = ararkhi
    , ω[--ρ] = dddu
    , ω[--ρ] = dddd0
    ,);
}
S(dddd1) { O(, ρ += 4, ω[α++] = ω[ρ + 1], ); }
N(an) {
  n_t ararkhi = ω[ρ + 2];
  O(, ω[--ρ] = ω[--α]
    , ω[--ρ] = ararkhi
    , ω[--ρ] = dddd1
    , ω[--ρ] = dddu
    ,);
}
N(one) {
  O(, ω[α++] = (void*)1
    , ω[α++] = ω[ρ + 1]
    ,);
}
N(add) {
  long rhs = (long)ω[--α];
  long lhs = (long)ω[--α];
  O(, ω[α++] = (void *)(rhs + lhs)
    , ω[α++] = ω[ρ + 1]
    ,);
}
N(two) { 
  O(, ω[α++] = one
    , ω[α++] = one
    , ω[α++] = da
    , ω[α++] = add
    , ω[α++] = da 
    ,);
}
N(seven) {
  O(, ω[α++] = one
    , ω[α++] = two
    , ω[α++] = da
    , ω[α++] = add
    , ω[α++] = da 
    , ω[α++] = two
    , ω[α++] = da
    , ω[α++] = add
    , ω[α++] = da 
    , ω[α++] = two
    , ω[α++] = da
    , ω[α++] = add
    , ω[α++] = da 
    ,);
}

#include <stdio.h>
#include <stdlib.h>
N(aralog) { printf("ara"); }
N(dalog) {
  void *v = ω[--α];
  printf("da %p", v);
}
N(anlog) { printf("an"); }
int main() {
  long α = 0, ρ, σ = ρ = 512;
  void **ω = malloc(σ * sizeof(void *));
  O(, ω[--ρ] = aralog
    , ω[--ρ] = dalog
    , ω[--ρ] = anlog
    , ω[α++] = seven
  ,);
  free(ω);
  return 0;
}
