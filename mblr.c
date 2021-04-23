#include "mblr.h"

padd(lr, narray, lr_nar narr);

static nargo(narray, lronarray) { o->narr(o->o, begin, advance); }
static nargo(rray, lronarray) { o->o->r(o->o, begin, advance); }
static nargo(lray, lronarray) { o->o->l(o->o, begin, advance); }

nargo(mbr, lr) {
  param(lr_nar, narr);
  param(lr_nar, narl);
  narl(
      (lr_pith *)&(lronarray_pith){
          .lr.r = (void *)narray,
          .lr.l = (void *)lray,
          .o = o,
          .narr = narr,
      },
      begin, advance);
}
nargo(mbl, lr) {
  param(lr_nar, narr);
  param(lr_nar, narl);
  narl(
      (lr_pith *)&(lronarray_pith){
          .lr.r = (void *)rray,
          .lr.l = (void *)narray,
          .o = o,
          .narr = narr,
      },
      begin, advance);
}
