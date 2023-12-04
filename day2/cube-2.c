#include <stdio.h>
#include <ctype.h>

int main() {
  FILE *fptr;
  int result = 0;

  fptr = fopen("input.txt", "r");
  char myString[10000];
  while (fgets(myString, 10000, fptr)){
    //fgets(myString, 10000, fptr);
    int r = 0;
    int g = 0;
    int b = 0;
    int p = 0;
    int c = 0;
    int i = 0;
    int rm = 0;
    int gm = 0;
    int bm = 0;
    while (myString[i] != '\n') {
      if (myString[i] == ';'){
        r = 0;
        g = 0; 
        b = 0;
      }
      if (isdigit(myString[i])){
        if (isdigit(myString[i + 1])){
          p += (myString[i] - '0') * 10;
          c = 1;
        }
        else {
          p += myString[i] - '0';
          c = 1;
        }
      }

      else if (c == 1 && myString[i] != ' ') {
        if (myString[i] == 'r') {
          r += p;
          if (r > rm) {
            rm = r;
          }
        }
        if (myString[i] == 'g') {
          g += p;
          if (g > gm) {
            gm = g;
          }
        }
        if (myString[i] == 'b') {
          b += p;
          if (b > bm) {
            bm = b;
          }
        }
        c = 0;
        p = 0;
      }
      i++;
    }
    result += (rm * gm * bm);
  }
  printf("%d\n", result);
  fclose(fptr);
  return 0;
}
