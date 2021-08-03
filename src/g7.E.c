#include "ints.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef void (*n_t)(void *, void *, void *, void *);
void f0(void *abo, void *aba, void *obr, void *rbs) {
  obr += sizeof(void *) * 3, (((n_t *)obr)[+0])(abo, aba, obr, rbs);
}
void f1(void *abo, void *aba, void *obr, void *rbs) {
  obr += sizeof(void *) * 3, (((n_t *)obr)[+1])(abo, aba, obr, rbs);
}
void cb(void *abo, void *aba, void *obr, void *rbs) {
  obr += sizeof(void *) * 3, (((n_t *)obr)[-1])(abo, aba, obr, rbs);
}
void mbo(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  n_t narb = (((n_t *)aba)[0]);
  aba -= sizeof(void *);
  n_t nara = (((n_t *)aba)[0]);
  obr -= sizeof(n_t), (((n_t *)obr)[0]) = (narb), obr -= sizeof(n_t),
                             (((n_t *)obr)[0]) = (f1), obr -= sizeof(n_t),
                             (((n_t *)obr)[0]) = (cb), nara(abo, aba, obr, rbs);
}
void mba(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  n_t narb = (((n_t *)aba)[0]);
  aba -= sizeof(void *);
  n_t nara = (((n_t *)aba)[0]);
  obr -= sizeof(n_t), (((n_t *)obr)[0]) = (narb), obr -= sizeof(n_t),
                             (((n_t *)obr)[0]) = (cb), obr -= sizeof(n_t),
                             (((n_t *)obr)[0]) = (f0), nara(abo, aba, obr, rbs);
}
void one(void *abo, void *aba, void *obr, void *rbs) {
  (((int *)aba)[0]) = (1), aba += sizeof(void *),
         (((n_t *)obr)[1])(abo, aba, obr, rbs);
}
void add(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  int r = (((int *)aba)[0]);
  aba -= sizeof(void *);
  int l = (((int *)aba)[0]);
  (((int *)aba)[0]) = (l + r), aba += sizeof(void *),
         (((n_t *)obr)[1])(abo, aba, obr, rbs);
}
void two(void *abo, void *aba, void *obr, void *rbs) {
  (((n_t *)aba)[0]) = (one), aba += sizeof(void *), (((n_t *)aba)[0]) = (one),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (add),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), aba -= sizeof(void *),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void seven(void *abo, void *aba, void *obr, void *rbs) {
  (((n_t *)aba)[0]) = (one), aba += sizeof(void *), (((n_t *)aba)[0]) = (two),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (two),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (two),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (add),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (add),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (add),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mba),
         aba += sizeof(void *), aba -= sizeof(void *),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void logint(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  int v = (((int *)aba)[0]);
  printf("%d\n", v);
}
void logQ_t(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  Q_t v = (((Q_t *)aba)[0]);
  printf("%lu\n", v);
}
void logQ_t2(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  Q_t b = (((Q_t *)aba)[0]);
  aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  printf("%lu %lu\n", a, b);
}
void rotate3(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  Q_t c = (((Q_t *)aba)[0]);
  aba -= sizeof(void *);
  Q_t b = (((Q_t *)aba)[0]);
  aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  (((Q_t *)aba)[0]) = (b), aba += sizeof(void *), (((Q_t *)aba)[0]) = (c),
         aba += sizeof(void *), (((Q_t *)aba)[0]) = (a), aba += sizeof(void *),
         (((n_t *)obr)[0])(abo, aba, obr, rbs);
}
void drop(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  ((void)a);
  (((n_t *)obr)[0])(abo, aba, obr, rbs);
}
void swap(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  aba -= sizeof(void *);
  Q_t b = (((Q_t *)aba)[0]);
  (((Q_t *)aba)[0]) = (a), aba += sizeof(void *), (((Q_t *)aba)[0]) = (b),
         aba += sizeof(void *), (((n_t *)obr)[0])(abo, aba, obr, rbs);
}
void fib_next(void *abo, void *aba, void *obr, void *rbs) {
  aba -= sizeof(void *);
  Q_t c = (((Q_t *)aba)[0]);
  aba -= sizeof(void *);
  Q_t p = (((Q_t *)aba)[0]);
  aba -= sizeof(void *);
  Q_t n = (((Q_t *)aba)[0]);
  (((Q_t *)aba)[0]) = (n - 1), aba += sizeof(void *), (((Q_t *)aba)[0]) = (c),
         aba += sizeof(void *), (((Q_t *)aba)[0]) = (c + p),
         aba += sizeof(void *),
         (n ? fib_next : (((n_t *)obr)[0]))(abo, aba, obr, rbs);
}
void fib(void *abo, void *aba, void *obr, void *rbs) {
  (((Q_t *)aba)[0]) = (0), aba += sizeof(void *), (((Q_t *)aba)[0]) = (1),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (fib_next),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (rotate3),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mbo),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (drop),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (mbo),
         aba += sizeof(void *), (((n_t *)aba)[0]) = (swap),
         aba += sizeof(void *), mbo(abo, aba, obr, rbs);
}
int main() {
  void *abo, *aba, *obr, *rbs;
  abo = aba = malloc((1 << 13));
  rbs = obr = abo + (1 << 13);
  obr -= sizeof(n_t), (((n_t *)obr)[0]) = logint;
  obr -= sizeof(n_t), (((n_t *)obr)[0]) = logint;
  seven(abo, aba, obr, rbs);
  free(abo);
};
