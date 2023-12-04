#include <stdio.h>
#include <ctype.h>

int main() {
  FILE *fptr;
  int result = 0;

  fptr = fopen("input.txt", "r");
  char myString[10000];
  while (fgets(myString, 10000, fptr)){
    int r = 0;
    int g = 0;
    int b = 0;
    int p = 0;
    int c = 0;
    int i = 0;
    int game = 0;
    while (myString[i] != '\n') {
      if (myString[i] == ':') {
        if (isdigit(myString[i - 3])){
          game += (myString[i - 3] - '0') * 100;
        }
        if (isdigit(myString[i - 2])){
          game += (myString[i - 2] - '0') * 10;
        }
        game += myString[i - 1] - '0';
      }

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
        if (myString[i] == 'r') r += p;
        if (myString[i] == 'g') g += p;
        if (myString[i] == 'b') b += p;
        c = 0;
        p = 0;
      }
      if (r > 12 || g > 13 || b > 14) {
        result -= game;
        break;
      }
      i++;
    }
    result += game;
  }
  printf("%d\n", result);
  fclose(fptr);
  return 0;
}
