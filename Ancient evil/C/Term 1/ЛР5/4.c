#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(void) {
	int a,b,i, j=0, j1, k, t=0, y=0, y1, z=0;
	char str[100];
	char vowels[] = "aeiouyAEIOUY";
	char cons[] = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	FILE*file;
	file=fopen("test.txt", "r");
	if (file == NULL) {
		puts("Не удалось прочитать файл");
	}
	while (!feof(file)) {
	fgets(str, 100, file);
	a=(strlen(str))/2;
	b=strlen(str);
	i=0; y1=0; j1=0;
		while (a<b) {
			if (strlen(str)<2) {i=999;}
			printf("%c", str[a]);
			if (strchr(cons, str[a]) != NULL) {
				i++;
			}
			a++;
		}
		if (i<4) {
			j++;
			j1++;
		}
		k=0;
		while (k<a) {
			if (strlen(str)<2) {t=-999;}
			if (strchr(vowels, str[k]) != NULL) {
				t++;
			}
			k++;
		}
		if (t>3) {
			y++;
			y1++;
		}
		if(j1==y1) {
			z++;
		}
	}
	printf("\n\nПервая половина, гласные 3+: %d", y);
	printf("\n\nВторая половина, согласные <4: %d", j);
	printf("\n\nОба условия: %d", z);
	getch();
	return EXIT_SUCCESS;
	}

