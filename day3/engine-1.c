#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	FILE *fptr;
	int result = 0;

	fptr = fopen("input.txt", "r");
	char myString[10000] = "";
	char fl[1000] = "";
	char sl[1000] = "";
	char tl[1000] = "";
	int i = 0;
	while (i < 3){
		fgets(myString, 10000, fptr);
		if (i == 0) {
			strcpy(fl, myString);
		}
		else if (i == 1) {
			strcpy(sl, myString);
		}
		else if (i == 2) {
			strcpy(tl, myString);
		}
		i++;
	}
	int j = 0;
	while (fl[j] != '\n') {
		if (fl[j] == '*'){
			printf("fl: %d\n", j);
		}
		if (sl[j] == '*'){
			printf("sl: %d\n", j);
		}
		if (tl[j] == '*'){
			printf("tl: %d\n", j);
		}
		j++;
	}

	printf("%s\n%s\n%s\n", fl, sl, tl);
	fclose(fptr);
}
