#pragma once

#include "nargo.h"

pith(lr,                                     //
     void (*r)(struct lr *, void *, void *); //
     void (*l)(struct lr *, void *, void *); //
);

nargo(mbr, lr);

nargo(mbl, lr);
