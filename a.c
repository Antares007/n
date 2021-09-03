#include "a.h"
static N(dddd0) {
  ρ += 4;
  ο[ρ].c(ο, α, ρ, σ);
}
static N(dddu) {
  ρ += 3;
  ο[ρ].c(ο, α, ρ + 1, σ);
}
N(da) {
  n_t araarkhi = ο[ρ + 2].c;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].c = araarkhi;
  ο[--ρ].c = dddu;
  ο[--ρ].c = dddd0;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
static N(dddddd0) {
  ρ += 6;
  ο[ρ].c(ο, α, ρ, σ);
}
static N(ddduuu) {
  ρ += 3;
  ο[α++].v = ο[ρ++].v;
  ο[α++].v = ο[ρ++].v;
  ο[ρ].c(ο, α, ρ + 1, σ);
}
N(daaa) {
  n_t araarkhi = ο[ρ + 2].c;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].c = araarkhi;
  ο[--ρ].c = ddduuu;
  ο[--ρ].c = dddddd0;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
static N(ddddd0) {
  ρ += 5;
  ο[ρ].c(ο, α, ρ, σ);
}
static N(ddduu) {
  ρ += 3;
  ο[α++].v = ο[ρ++].v;
  ο[ρ].c(ο, α, ρ + 1, σ);
}
N(daa) {
  n_t araarkhi = ο[ρ + 2].c;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].v = ο[--α].v;
  ο[--ρ].c = araarkhi;
  ο[--ρ].c = ddduu;
  ο[--ρ].c = ddddd0;
  ο[α - 1].c(ο, α - 1, ρ, σ);
}
