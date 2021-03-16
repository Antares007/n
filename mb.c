#include "mb.h"
struct cmbpith {
  struct cpith b;
  struct cpith *o;
  N((*narb));
};
static N(errorray) {
  ((struct cmbpith *)ο)->o->error(((struct cmbpith *)ο)->o, σ);
}
static N(valueray) {
  ((struct cmbpith *)ο)->narb(((struct cmbpith *)ο)->o, σ);
}
N(mb) {
  S2(nargo, nargo, narB, narA);
  narA(
      (struct cpith *)&(struct cmbpith){
          .b = {.value = valueray, .error = errorray}, .o = ο, .narb = narB},
      σ);
}

