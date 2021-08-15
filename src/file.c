#include <stdio.h>
#include <stdlib.h>
int main() {
  //FILE *s = stdin;
  FILE *si = fopen("src/file.c","r");
  FILE *so = fopen("src/file2.c","a");
  char buf[BUFSIZ];
  int nreaditem;
  while ((nreaditem = fread(buf, 8, 1, si)) > 0) {
    fwrite(buf, 8, nreaditem, so);
  }
  fflush(so);
  fclose(so);
  fclose(si);
  return 0;
}
