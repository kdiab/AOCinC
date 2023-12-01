#include <stdio.h>
#include <ctype.h>

// helper function to combine first and last numbers
int addDigits(int n1, int n2){
 return ((n1 - '0') * 10) + (n2 - '0');
}

int main() {
  FILE *fptr;

  fptr = fopen("input.txt", "r");
  char myString[1000];
int r = 0;
 while(fgets(myString, 1000, fptr)) {
  int i = 0;
  int f = 0;
  int fn = 0;
  int ln = 0;

//using f as a boolean flag because I don't want to import stdbool
  while (myString[i] != '\n'){
    if(isdigit(myString[i]) && f == 0){

//if the string only has 1 number both first and last get the same number
      fn = myString[i];
      ln = myString[i];
      f = 1;
    }
    else if (isdigit(myString[i]) && f == 1){
      ln = myString[i];
    }
    i++;
    }
  r += addDigits(fn, ln);
  }
  printf("%d\n", r);
  fclose(fptr);
  return 0;
}
