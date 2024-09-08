#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(void) {
	char data, str;
	int i, tm=0, scr=0, h=0, d=0;
	FILE*file;
	file=fopen("text1.txt", "r");
	while(!feof(file)) {
		fscanf(file, "%c", &data);
		tm++;
		if (data==' ' || data=='\n' || data=='\0') {
			if (tm%2==0) {
				scr++;
				tm=0;
			}
			else {
				tm=0;
			}
		}
		fscanf(file, "%c", &str);
		if (str!=' ' || str!='\n' || str!='\0') {
			h++;
		}
		if (str=='\n') {
			if (h%2==0) {
				d++;
			}
		h=0;
		}
	}
	
	fclose(file);
	printf("Слов с чет кол-вом букв: %d", scr);
	printf("\nСтрок с чет кол-вом букв: %d", d);
//	file=fopen("text1.txt", "a");
//	fprintf(file, "\nСлов с чет кол-вом букв: %d", scr);
//	fclose(file);
getch();
return EXIT_SUCCESS;
}

