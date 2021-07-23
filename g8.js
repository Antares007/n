test([]);
test([9]);
test([9, 7]);
test([7, 9, 8]);
test([7, 6, 9, 8]);
function test(ar) {
  const ex = ar.slice(0).sort((a, b) => (a < b ? -1 : b < a ? 1 : 0));
  sort(ar);
  for (let i = 0; i < ex.length; i++) if (ex[i] !== ar[i]) throw Error();
  console.log(ar);
}
function sort(A) {
  if (A.length < 2) return;
  const U = [[0, A.length - 1]];
  do {
    const b = U[0][0];
    const t = U[0][1];
    if (b != t) {
      const p = Partitions(A, b, b, t);
      U.splice(0, 1);
      U.push([b, Math.max(b, p - 1)]);
      U.push([Math.min(p + 1, t), t]);
    } else U.splice(0, 1);
  } while (U.length);
}
function swap(A, b, t) {
  const ab = A[b];
  A[b] = A[t];
  A[t] = ab;
}
function Partitions(A, p, b, t) {
  for (let i = b; i < t; i++) if (A[i] < A[t]) swap(A, p, i), p++;
  swap(A, p, t);
  return p;
}
