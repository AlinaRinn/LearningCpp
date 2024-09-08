#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <malloc.h>
#define N 4
#define M 4

int main(void) { 
	FILE*file;
	file = fopen("file.txt","w");
	if (file == NULL) {printf ("файла нет\n");}
  	else printf ("файл открыт\n\n");
	srand(time(NULL));
	int i,j=0, b[N][M],A=-100, B=100, min=999999, minn=-999999;
	for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            b[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
            printf("%6d", b[i][j]);
        }
        printf("\n");
	}
	fprintf(file, "Минимальные элементы: \n\n");
	for (i = 0; i < N; i++) {
		min=b[i][j];
		for (j = 0; j < N; j++) {
			if (b[i][j]<min) {
				min=b[i][j];
			}	
		}
		fprintf(file, " %d ", min);
		if (minn<min) {
			minn=min;
		}
	}
	fprintf(file, "\n\nМаксимальный из минимальных: %d\n", minn);
	
getch();
return EXIT_SUCCESS;
}

