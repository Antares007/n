#include "ints.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef void (*n_t)(void *, void *, void *, void *);
void f0(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), obr += sizeof(void *) * 3,
      (((n_t *)obr)[+0])(abo, aba, obr, rbs);
}
void f1(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), obr += sizeof(void *) * 3,
      (((n_t *)obr)[+1])(abo, aba, obr, rbs);
}
void cb(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), obr += sizeof(void *) * 3,
      (((n_t *)obr)[-1])(abo, aba, obr, rbs);
}
void mbo(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  n_t narb = (((n_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  n_t nara = (((n_t *)aba)[0]);
  ((void)(0)), obr -= sizeof(n_t),
      (((n_t *)obr)[0]) = (narb), ((void)(0)), obr -= sizeof(n_t),
             (((n_t *)obr)[0]) = (f1), ((void)(0)), obr -= sizeof(n_t),
             (((n_t *)obr)[0]) = (cb), nara(abo, aba, obr, rbs);
}
void mba(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  n_t narb = (((n_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  n_t nara = (((n_t *)aba)[0]);
  ((void)(0)), obr -= sizeof(n_t),
      (((n_t *)obr)[0]) = (narb), ((void)(0)), obr -= sizeof(n_t),
             (((n_t *)obr)[0]) = (cb), ((void)(0)), obr -= sizeof(n_t),
             (((n_t *)obr)[0]) = (f0), nara(abo, aba, obr, rbs);
}
void one(void *abo, void *aba, void *obr, void *rbs) {
  (((int *)aba)[0]) = (1), ((void)(0)), aba += sizeof(void *),
         (((n_t *)obr)[1])(abo, aba, obr, rbs);
}
void add(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  int r = (((int *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  int l = (((int *)aba)[0]);
  (((int *)aba)[0]) = (l + r), ((void)(0)), aba += sizeof(void *),
         (((n_t *)obr)[1])(abo, aba, obr, rbs);
}
void two(void *abo, void *aba, void *obr, void *rbs) {
  (((n_t *)aba)[0]) = (one), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (one), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (add), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         ((void)(0)), aba -= sizeof(void *),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void seven(void *abo, void *aba, void *obr, void *rbs) {
  (((n_t *)aba)[0]) = (one), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (two), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (two), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (two), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (add), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (add), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (add), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mba), ((void)(0)), aba += sizeof(void *),
         ((void)(0)), aba -= sizeof(void *),
         (((n_t *)aba)[0])(abo, aba, obr, rbs);
}
void logint(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  int v = (((int *)aba)[0]);
  printf("%d\n", v);
}
void logQ_t(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  Q_t v = (((Q_t *)aba)[0]);
  printf("%lu\n", v);
}
void logQ_t2(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  Q_t b = (((Q_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  printf("%lu %lu\n", a, b);
}
void rotate3(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  Q_t c = (((Q_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  Q_t b = (((Q_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  (((Q_t *)aba)[0]) = (b), ((void)(0)), aba += sizeof(void *),
         (((Q_t *)aba)[0]) = (c), ((void)(0)), aba += sizeof(void *),
         (((Q_t *)aba)[0]) = (a), ((void)(0)), aba += sizeof(void *),
         (((n_t *)obr)[0])(abo, aba, obr, rbs);
}
void drop(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  ((void)a);
  (((n_t *)obr)[0])(abo, aba, obr, rbs);
}
void swap(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  Q_t a = (((Q_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  Q_t b = (((Q_t *)aba)[0]);
  (((Q_t *)aba)[0]) = (a), ((void)(0)), aba += sizeof(void *),
         (((Q_t *)aba)[0]) = (b), ((void)(0)), aba += sizeof(void *),
         (((n_t *)obr)[0])(abo, aba, obr, rbs);
}
void fib_next(void *abo, void *aba, void *obr, void *rbs) {
  ((void)(0)), aba -= sizeof(void *);
  Q_t c = (((Q_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  Q_t p = (((Q_t *)aba)[0]);
  ((void)(0)), aba -= sizeof(void *);
  Q_t n = (((Q_t *)aba)[0]);
  (((Q_t *)aba)[0]) = (n - 1), ((void)(0)), aba += sizeof(void *),
         (((Q_t *)aba)[0]) = (c), ((void)(0)), aba += sizeof(void *),
         (((Q_t *)aba)[0]) = (c + p), ((void)(0)), aba += sizeof(void *),
         (n ? fib_next : (((n_t *)obr)[0]))(abo, aba, obr, rbs);
}
void fib(void *abo, void *aba, void *obr, void *rbs) {
  (((Q_t *)aba)[0]) = (0), ((void)(0)), aba += sizeof(void *),
         (((Q_t *)aba)[0]) = (1), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (fib_next), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (rotate3), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mbo), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (drop), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (mbo), ((void)(0)), aba += sizeof(void *),
         (((n_t *)aba)[0]) = (swap), ((void)(0)), aba += sizeof(void *),
         mbo(abo, aba, obr, rbs);
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
