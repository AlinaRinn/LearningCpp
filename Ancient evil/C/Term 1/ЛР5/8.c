#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define N 30
#define M 500 
 
int main ( void ) {
	int n=0;
	char *tmp;
	char string[N], filee[M];
	FILE*file;
	file=fopen("text2.txt", "r");
	scanf("%s", &string);
	while (!feof(file)) {
		fscanf(file,"%s", &filee);
   		 if(strstr (filee,string) !=0){
   		 		n++;
			}
	}
    printf("%d", n);
getch();
return EXIT_SUCCESS;
}

