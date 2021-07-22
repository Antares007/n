void vs(int);
int abi(long int a, long int b, int c, int d);
void callsite() { vs(abi(-1, -2, -3, -4)); }
int f(int x) { return x + 1; }
int g(int x) { return x + 2; }
int gof(int x) { return g(f(x)); }
