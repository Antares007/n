#include <stdio.h>
#include <stdlib.h>
int main() {
  //FILE *s = stdin;
  FILE *s = fopen("src/file.c","r");
  char buf[BUFSIZ];
  int nreaditem;
  while ((nreaditem = fread(buf, 8, 1, s)) > 0) {
    int n = nreaditem;
    while (n--) {
      char *i = buf + n * 8;
      char t = *i;
      *i = *(i + 7);
      *(i + 7) = t;
    }
    fwrite(buf, 8, nreaditem, stdout);
  }
  fclose(s);
  return 0;
}
