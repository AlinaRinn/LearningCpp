#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(void) {
	char sobaka[100];
	FILE*file;
	FILE*file1;
	file=fopen("text3.txt", "r");
	file1=fopen("text4.txt", "w");
	while (!feof(file)) {
		fgets(sobaka, 100, file);
		if (strlen(sobaka)>=20) {
			fprintf(file1, "%s", sobaka );
		}
	}
	fclose(file);
	fclose(file1);
getch();
return EXIT_SUCCESS;
}	
