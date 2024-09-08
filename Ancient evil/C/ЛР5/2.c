#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>


int main(void) {
	char data[1000];
	int i;
	FILE*file;
	file=fopen("text.txt", "r");
	for (i=0; !feof(file); i++) {
		fscanf(file, "%c", &data[i]);
		if (i%2==1) {
			printf("%c", data[i]);
		}
	}

getch();
return EXIT_SUCCESS;
}

