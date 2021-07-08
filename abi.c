void vs(int);
int abi(long int a, long int b, int c, int d);
void callsite() { vs(abi(-1, -2, -3, -4)); }
