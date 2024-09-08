#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(void) {
	char dat[50], nova[150], nova2[250];
	scanf("%s", dat);
	strcpy(nova, dat);
	strcpy(nova2, dat);
	strcat(nova2, dat);
	printf("%s", nova);
	printf("\n%s", nova2);
getch();
return EXIT_SUCCESS;
}

