#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char * numToStr[] = { 
	[0] = "0",
	[1] = "o1e", 
	[2] = "t2o", 
	[3] = "t3e", 
	[4] = "f4r", 
	[5] = "f5e", 
	[6] = "s6x", 
	[7] = "s7n", 
	[8] = "e8t", 
	[9] = "n9e" 
};

char * nums[] = { 
	[0] = "zero",
	[1] = "one", 
	[2] = "two", 
	[3] = "three", 
	[4] = "four", 
	[5] = "five", 
	[6] = "six", 
	[7] = "seven", 
	[8] = "eight", 
	[9] = "nine" 
};


void replaceWord(char* str, char* oldWord, char* newWord)
{
    char *pos, temp[1000];
    int index = 0;
    int owlen;
    owlen = strlen(oldWord);
    while ((pos = strstr(str, oldWord)) != NULL) {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}

void replaceWordWithNumber(char* str){
	for (int i = 1; i < 10; i++){
		replaceWord(str, nums[i], numToStr[i]);
	}
}

int addDigits(int n1, int n2){
 return ((n1 - '0') * 10) + (n2 - '0');
}

int main() {
  FILE *fptr;

  fptr = fopen("input.txt", "r");
  char myString[10000];
  int r = 0;
  
  while(fgets(myString, 10000, fptr)) {
  int i = 0;
  int f = 0;
  int fn = 0;
  int ln = 0;
  
  replaceWordWithNumber(myString);
 
  while (myString[i] != '\n'){
    if(isdigit(myString[i]) && f == 0){
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
