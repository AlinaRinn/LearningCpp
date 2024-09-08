#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) {
	char cash;
	FILE*file;
	FILE*file1;
	file=fopen("Boom.txt", "r");
	file1=fopen("Code.txt", "w");
	while (!feof(file)) {
		fscanf(file, "%c", &cash);
		if (cash=='\n') {
			fprintf(file1, "\n");
		}
			cash = ~cash;
			cash = cash*(-1);
			fprintf(file1, "%c", cash);
	}
	fclose(file);
	fclose(file1);
getch();
return EXIT_SUCCESS;
}

