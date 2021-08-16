#include "aradani.h"                               //
N(one) {                                           //  dalog @ seven.c:43
  O(, β[α++] = (void*)1                            //  add   @ seven.c:10
    , β[α++] = β[ρ + 1]                            //  dddu  @ aradani.c:2
    ,);                                            //  add   @ seven.c:10
}                                                  //  dddu  @ aradani.c:2
N(add) {                                           //  one   @ seven.c:3
  long rhs = (long)β[--α];                         //  dddu  @ aradani.c:2
  long lhs = (long)β[--α];                         //  one   @ seven.c:3
  O(, β[α++] = (void *)(rhs + lhs)                 //  da    @ aradani.c:6
    , β[α++] = β[ρ + 1]                            //  da    @ aradani.c:6
    ,);                                            //  two   @ seven.c:15
}                                                  //  dddu  @ aradani.c:2
N(two) {                                           //  add   @ seven.c:10
  O(, β[α++] = one                                 //  dddu  @ aradani.c:2
    , β[α++] = one                                 //  add   @ seven.c:10
    , β[α++] = da                                  //  dddu  @ aradani.c:2
    , β[α++] = add                                 //  one   @ seven.c:3
    , β[α++] = da                                  //  dddu  @ aradani.c:2
    ,);                                            //  one   @ seven.c:3
}                                                  //  da    @ aradani.c:6
N(seven) {                                         //  da    @ aradani.c:6
  O(, β[α++] = one                                 //  two   @ seven.c:15
    , β[α++] = two                                 //  dddu  @ aradani.c:2
    , β[α++] = da                                  //  add   @ seven.c:10
    , β[α++] = add                                 //  dddu  @ aradani.c:2
    , β[α++] = da                                  //  add   @ seven.c:10
    , β[α++] = two                                 //  dddu  @ aradani.c:2
    , β[α++] = da                                  //  one   @ seven.c:3
    , β[α++] = add                                 //  dddu  @ aradani.c:2
    , β[α++] = da                                  //  one   @ seven.c:3
    , β[α++] = two                                 //  da    @ aradani.c:6
    , β[α++] = da                                  //  da    @ aradani.c:6
    , β[α++] = add                                 //  two   @ seven.c:15
    , β[α++] = da                                  //  dddu  @ aradani.c:2
    ,);                                            //  one   @ seven.c:3
}                                                  //  da    @ aradani.c:6
                                                   //  da    @ aradani.c:6
#include <stdio.h>                                 //  da    @ aradani.c:6
#include <stdlib.h>                                //  da    @ aradani.c:6
                                                   //  da    @ aradani.c:6
N(aralog) { printf("ara"); }                       //  da    @ aradani.c:6
N(dalog) { void *v = β[--α]; printf("da %p", v); } //  seven @ seven.c:23
N(anlog) { printf("an"); }                         //  main  @ seven.c:51
int main() {                                       //
  long α = 0;long ρ = 512;long σ = ρ;              //
  void **β = malloc(σ * sizeof(void *));           //
  O(, β[--ρ] = aralog, β[--ρ] = dalog              //
    , β[--ρ] = anlog, β[α++] = seven,);            //
  free(β);                                         //
  return 0;                                        //
}
