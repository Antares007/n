#include "aradani.h"
S(dddu) { O(, ρ += 3, ο[α++] = ο[ρ++], ); }
S(dddd0) { O(, ρ += 4, ο[α++] = ο[ρ + 0], ); }
N(da) {
  n_t ararkhi = ο[ρ + 2];
  O(, ο[--ρ] = ο[--α], ο[--ρ] = ararkhi, ο[--ρ] = dddu, ο[--ρ] = dddd0, );
}
S(dddd1) { O(, ρ += 4, ο[α++] = ο[ρ + 1], ); }
N(an) {
  n_t ararkhi = ο[ρ + 2];
  O(, ο[--ρ] = ο[--α], ο[--ρ] = ararkhi, ο[--ρ] = dddd1, ο[--ρ] = dddu, );
}
S(dddddd0) { O(, ρ += 6, ο[α++] = ο[ρ + 0], ); }
S(ddduuu) { O(, ρ += 3, ο[α++] = ο[ρ++], ο[α++] = ο[ρ++], ο[α++] = ο[ρ++], ); }
N(da3) {
  n_t araarkhi = ο[ρ + 2];
  O(, ο[--ρ] = ο[--α], ο[--ρ] = ο[--α], ο[--ρ] = ο[--α], ο[--ρ] = araarkhi,
    ο[--ρ] = ddduuu, ο[--ρ] = dddddd0, );
}
