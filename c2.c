#include "a3.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

N(აფურცელი) { A(0) σ[-1].c(T()); }
N(აგულგული) { A(1) σ[-1].c(T()); }
N(ამოწერე) { A(2) σ[-1].c(T()); }
N(წერტილი) { A(3) σ[-1].c(T()); }
N(შემდეგი) { A(4) σ[-1].c(T()); }

N(ან_გადასვლა) { C(, 0); }
N(და_გადასვლა) { C(, 1); }
N(sss) {
  R(n_t, nar);
  R(unsigned long, c);
  R(p_t *, sσ);
  A12(σ, c + 1, nar, აფურცელი, 4, ამოწერე, დაა, sσ, წერტილი, დაა, შემდეგი,
      და)
  O;
}
N(წყაროს_ან) { A2(ან_გადასვლა, sss) O; }
N(წყაროს_და) {
  if (ο[α - 1].Q % 1000000 == 0)
    printf("%s, c: %ld\n", (char *)ο[α - 3].v, ο[α - 1].q);
  A2(და_გადასვლა, sss) O;
}
N(წყაროს_არა) {}
N(კალაპოტის_ან) { A2(და_გადასვლა, sss) O; }
N(კალაპოტის_და) {
  if (ο[α - 1].Q % 1000000 == 0)
    printf("c: %ld\n", ο[α - 1].q);
  A2(და_გადასვლა, sss) O;
}
N(კალაპოტის_არა) {}
N(აწყაროსგულგული) {
  A9(წყაროს_ან, წყაროს_და, წყაროს_არა, 3, 6, 9, σ[-1].c, 7, აგულგული) O;
}
N(აკალაპოტი) {
  A9(კალაპოტის_ან, კალაპოტის_და, კალაპოტის_არა, 3, 9, 6, σ[-1].c, 7, აგულგული)
  O;
}
N(წყარო_კალაპოტის_ციკლის_მაგალითი) {
  A12(აკალაპოტი, -2, ან_გადასვლა, აფურცელი, დააა, 4, ამოწერე, დაა,
      აწყაროსგულგული, და, წერტილი, და)
  O;
}
N(მთავარი) {
  n_t exam = წყარო_კალაპოტის_ციკლის_მაგალითი;
  A8("პირველი", exam, "მეორე", exam, დაა, "მესამე", exam, დაა) O;
  // A5("პირველი", exam, "მეორე", exam, დაა) O;
  // A2("პირველი", exam) O;
}

#include "page.h"
#define ISPAGE(lx)                                                             \
  ((unsigned long)lx & (unsigned long)0xFFF) == 3 * sizeof(void *)
#define PS(p) (void *)((unsigned long)p & ~((unsigned long)0xFFF))
#define PN(p) (PS(p) + 0x1000)
N(os_აფურცელი) {
  // printf("%s %ld\n", __FUNCTION__, (((unsigned long)σ) >> 12) - (((unsigned
  // long)σ[1].v) >> 12));
  p_t *lx = σ[1].v;
  p_t *nο = PN(lx);
  nο += 3;
  if (σ < nο)
    return C(, 2);
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[-2].v = nο;
  σ[1].v = nο;
  A(nο) C(, 1);
}
N(os_აგულგული) {
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[ISPAGE(lx) ? 506 : 512];
  long pages = (((unsigned long)σ >> 12) - ((unsigned long)nσ >> 12)) / 3;
  // printf("%ld\n", pages);
  nσ = &nσ[pages * 512];
  long nρ = 0;
  R(unsigned long, wc);
  while (wc--)
    nσ[--nρ].v = ο[--α].v;
  nσ[0].q = nρ, nσ[1].v = lx, nσ[2].v = σ;
  lx[-2].v = nσ;
  σ[1].v = nσ;
  A(nσ) C(, 1);
}
N(os_ამოწერე) {
  R(unsigned long, wc);
  R(p_t *, pο);
  long pα = (pο[-1].q = pο[-1].q + wc);
  for (long i = 1; i <= wc; i++)
    pο[pα - i].v = ο[--α].v;
  A(pο) C(, 1);
}
#include "src/queue.h"
typedef struct {
  QUEUE q;
  p_t *ο;
  p_t *σ;
} rigis_elementi_t;
#define MAX_RIGIS_ELEMENTI 1024
rigis_elementi_t rigis_elementebi[MAX_RIGIS_ELEMENTI];
QUEUE rigis_tavi;
static void init_rigi() {
  for (int i = 0; i < MAX_RIGIS_ELEMENTI; i++)
    rigis_elementebi[i].q[0] = 0;
  QUEUE_INIT(&rigis_tavi);
}
static int shemdegi_rigis_nomeri() {
  static int last = 0;
  int i;
  for (i = last + 1; i < MAX_RIGIS_ELEMENTI; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(os_წერტილი) {
  int nomeri = shemdegi_rigis_nomeri();
  if (nomeri == 0)
    return C(, 2);
  R(p_t *, nσ);
  R(p_t *, nο);
  rigis_elementebi[nomeri].ο = nο;
  rigis_elementebi[nomeri].σ = nσ;
  QUEUE_INSERT_TAIL(&rigis_tavi, &rigis_elementebi[nomeri].q);
  C(, 1);
}
N(os_შემდეგი) {
  ο[-1].Q = α;
  if (α == 0 && ο[-3].v != 0) {
    p_t *l = ο[-3].v, *r = ο[-2].v;
    l[ISPAGE(l) ? -2 : 2].v = r;
    r[ISPAGE(r) ? -3 : 1].v = l;
  }
  QUEUE *q;
  if (&rigis_tavi != (q = QUEUE_NEXT(&rigis_tavi))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0] = 0;
    p_t *eο = e->ο, *eσ = e->σ;
    long eα = eο[-1].q, eρ = eσ[0].q;
    eο[eα - 1].c(eο, eα - 1, eρ, eσ);
  }
}
n_t opcode_map[] = {os_აფურცელი, os_აგულგული, os_ამოწერე, os_წერტილი,
                    os_შემდეგი};
N(os_ოპკოდით_გადამრთველი) {
  R(unsigned long, opcode);
  opcode_map[opcode](T());
}
int main() {
  init_rigi();
  // |.b..........|............|.e..........|............
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((unsigned long)b | ((unsigned long)0xFFF)) + 1,
      *σ = (void *)((unsigned long)e & ~((unsigned long)0xFFF));
  printf("mem   %p %p\n", b, e);
  printf("grid  %p %p\n", ο, σ);
  printf("pages %ld\n", ((unsigned long)σ >> 12) - ((unsigned long)ο >> 12));
  ο += 3, σ -= 3;
  printf("tree  %p %p\n", ο, σ);

  long α = 0, ρ = 0;

  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os_ოპკოდით_გადამრთველი;
  σ[--ρ].c = os_შემდეგი;
  σ[--ρ].c = os_შემდეგი;
  σ[--ρ].c = os_შემდეგი;
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  მთავარი(ο, α, ρ, σ);

  free(b);
}
