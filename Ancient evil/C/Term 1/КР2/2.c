#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) {
	char c, str[100];
	int s=0, k=0;
	FILE*file;
	FILE*file1;
	file = fopen("text_file.txt","r");
	file1 = fopen("new_file.txt","w");
	if ((file = fopen("text_file.txt","r")) == 0) {
		printf("error");
	}
	while (!feof(file)){
		c = getc(file);
		s++;
		if (s==15) {
			fprintf(file1,"%c",c);
			s=0;
		}
	}
	fclose(file);
	fprintf(file1,"\n\n");
	file = fopen("text_file.txt","r");
	
	while (!feof(file)){
		fgets(str,100,file);
		k = strlen(str);
		for (int i = k/2;i < k;i ++){
			fprintf(file1,"%c",str[i]);
		}
	}	
fclose(file);
fclose(file1);
getch();
return EXIT_SUCCESS;
}

