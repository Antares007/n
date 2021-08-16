#include "aradani.h"
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

