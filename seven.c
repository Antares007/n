#include "aradani.h"                               //
N(one) {                                           //  dalog    @ seven.c:43
  O(, ο[α++] = (void*)1                            //  add      @ seven.c:10
    , ο[α++] = ο[ρ + 1]                            //     dddu  @ aradani.c:2
    ,);                                            //     add   @ seven.c:10
}                                                  //     dddu  @ aradani.c:2
N(add) {                                           //     one   @ seven.c:3
  long rhs = (long)ο[--α];                         //     dddu  @ aradani.c:2
  long lhs = (long)ο[--α];                         //     one   @ seven.c:3
  O(, ο[α++] = (void *)(rhs + lhs)                 //     da    @ aradani.c:6
    , ο[α++] = ο[ρ + 1]                            //     da    @ aradani.c:6
    ,);                                            //  two      @ seven.c:15
}                                                  //     dddu  @ aradani.c:2
N(two) {                                           //  add      @ seven.c:10
  O(, ο[α++] = one                                 //     dddu  @ aradani.c:2
    , ο[α++] = one                                 //     add   @ seven.c:10
    , ο[α++] = da                                  //     dddu  @ aradani.c:2
    , ο[α++] = add                                 //     one   @ seven.c:3
    , ο[α++] = da                                  //     dddu  @ aradani.c:2
    ,);                                            //     one   @ seven.c:3
}                                                  //     da    @ aradani.c:6
N(seven) {                                         //     da    @ aradani.c:6
  O(, ο[α++] = one                                 //  two      @ seven.c:15
    , ο[α++] = two                                 //     dddu  @ aradani.c:2
    , ο[α++] = da                                  //  add      @ seven.c:10
    , ο[α++] = add                                 //     dddu  @ aradani.c:2
    , ο[α++] = da                                  //     add   @ seven.c:10
    , ο[α++] = two                                 //     dddu  @ aradani.c:2
    , ο[α++] = da                                  //     one   @ seven.c:3
    , ο[α++] = add                                 //     dddu  @ aradani.c:2
    , ο[α++] = da                                  //     one   @ seven.c:3
    , ο[α++] = two                                 //     da    @ aradani.c:6
    , ο[α++] = da                                  //     da    @ aradani.c:6
    , ο[α++] = add                                 //  two      @ seven.c:15
    , ο[α++] = da                                  //     dddu  @ aradani.c:2
    ,);                                            //  one      @ seven.c:3
}                                                  //     da    @ aradani.c:6
                                                   //     da    @ aradani.c:6
#include <stdio.h>                                 //     da    @ aradani.c:6
#include <stdlib.h>                                //     da    @ aradani.c:6
                                                   //     da    @ aradani.c:6
N(aralog) { printf("ara"); }                       //     da    @ aradani.c:6
N(dalog) { void *v = ο[--α]; printf("da %p", v); } //  seven    @ seven.c:23
N(anlog) { printf("an"); }                         //  main     @ seven.c:51
int main() {                                       //
  long α = 0;long ρ = 512;long σ = ρ;              //
  void **ο = malloc(σ * sizeof(void *));           //
  O(, ο[--ρ] = aralog, ο[--ρ] = dalog              //
    , ο[--ρ] = anlog, ο[α++] = seven,);            //
  free(ο);                                         //
  return 0;                                        //
}
