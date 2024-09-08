#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(void) {
	char c, s[100];
	int k = 0;
	char cons[] = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	FILE*file;
	file = fopen("text_file.txt","r");
	if ((file = fopen("text_file.txt","r")) == 0){
		printf("error");
	}
	file = fopen("text_file.txt","r");
	while (!feof(file)){
		c = getc(file);
		printf("%c",c);
	}
	fclose(file);
	file = fopen("text_file.txt","r");
	while (!feof(file)){
		c = getc(file);
		fscanf(file,"%s",s);
		if (strlen(s) < 3) {
			k++;
		}
	}
	printf("\n\nCлов < 5 символов: %d\n",k);
	fclose(file);
	file = fopen("text_file.txt","r");
	k = 0;
	while (!feof(file)){
		fgets(s,100,file);
		c = s[0];
		if (strchr(cons, c)){
			k++;
		}
	}
	printf("Строк на согласную: %d\n",k);
getch();
return EXIT_SUCCESS;
}

