#include "mbo.h"
struct bao_pith_s;
typedef void (*abo_nar_t)(struct bao_pith_s *, void *, void *);
struct bao_pith_s {
  struct ba_pith_s ba;
  struct ba_pith_s *o;
  ba_nar_t b;
};

static N(mb_forward_a, bao_pith_s) { o->o->a(o->o, b, a); }
static N(mb_forward_b, bao_pith_s) { o->o->b(o->o, b, a); }
static N(mb_call_b, bao_pith_s) { o->b(o->o, b, a); }
N(mb, ba_pith_s) {
  P(ba_nar_t, narb);
  P(ba_nar_t, nara);
  struct bao_pith_s pith = {.ba =
                                {
                                    .a = (ba_nar_t)mb_forward_a,
                                    .b = (ba_nar_t)mb_call_b,
                                },
                            .o = o,
                            .b = narb};
  nara((struct ba_pith_s *)&pith, b, a);
}
N(ma, ba_pith_s) {
  P(ba_nar_t, narb);
  P(ba_nar_t, nara);
  struct bao_pith_s pith = {.ba =
                                {
                                    .a = (ba_nar_t)mb_call_b,
                                    .b = (ba_nar_t)mb_forward_b,
                                },
                            .o = o,
                            .b = narb};
  nara((struct ba_pith_s *)&pith, b, a);
}
