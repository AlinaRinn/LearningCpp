#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) {
	char cash;
	FILE*file;
	FILE*file1;
	file=fopen("Code.txt", "r");
	file1=fopen("Decod.txt", "w");
	while (!feof(file)) {
		fscanf(file, "%c", &cash);
		cash = cash*(-1);
		cash = ~cash;
		fprintf(file1, "%c", cash);
	}
	fclose(file);
	fclose(file1);
getch();
return EXIT_SUCCESS;
}

