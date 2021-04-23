#include "mblr.h"
int printf(const char *, ...);
void *malloc(unsigned long);
void free(void *);


nargo(nar, lr) {
  param(int, a);
  apply(o->r, o, a + 2);
}
#include <stdint.h>
nargo(hexdump, lr) {
  for (; begin < advance; begin++) {
    unsigned char c = *(unsigned char *)begin & 0xff;
    if ((intptr_t)begin % 16 == 0)
      printf("\n%p: %02x", begin, c);
    else if ((intptr_t)begin % 8 == 0)
      printf(" %02x", c);
    else if ((intptr_t)begin % 4 == 0)
      printf(".%02x", c);
    else
      printf("%02x", c);
  }
}
nargo(lft, lr) { o->l(o, begin, advance); }
nargo(catch, lr) {
  advance = begin;
  apply(o->r, o, (int)0x89abcdef);
}
nargo(one, lr) { apply(o->r, o, 1); }
nargo(add2, lr) {
  param(int, b);
  param(int, a);
  apply(o->r, o, a,b, b + a);
}
nargo(gof, lr) {
  //apply(mbl, o, one, add2, mbr, add2, mbr, add2, mbr, add2, mbr, add2, mbr,add2, mbr, add2, mbr, add2, mbr, add2, mbr, add2, mbr,
  //      catch);
  //apply(mbl, o, lft, add2, mbr, add2, mbr, add2, mbr, catch);
  //apply(mbl, o, one, lft, mbr, add2, mbr, add2, mbr, catch);
  //apply(mbl, o, one, add2, mbr, add2, mbr, lft, mbr, catch);
  apply(o->r, o, (int)'a');
}

int main(void) {
  struct lr o;
  o.r = (void *)hexdump;
  o.l = (void *)hexdump;
  void *advance = malloc(4096);
  gof(&o, advance, advance);
  free(advance);
  return 0;
}
