#pragma once
#include "pith.h"
static nargo(mbrray) { C(o[30], o[31]); }
static nargo(mbr) {
  param(ntype, narb);
  param(ntype, nara);
  pith(op, trio(), ['r' - 'a'] = mbrray, [31] = o, [30] = narb);
  C(nara, op);
}
