#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 20

int main(void) {
    FILE*file;
	file = fopen("input.txt","r");
	int i, massiv[N];
	for (i=0; i<N; i++) {
		fscanf(file,"%d", &massiv[i]);
		printf("%d ", massiv[i]);
	}
	printf("\n\n");
	for (i=0; i<N; i++) {
		if (massiv[i]%2==0) {
			massiv[i]*=3;
			printf("%d ", massiv[i]);
		}
		else {
			massiv[i]*=4;
			printf("%d ", massiv[i]);
		}
	}
fclose(file);
getch();
return EXIT_SUCCESS;
}

