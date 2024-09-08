#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 20
#define F 20

int main(void) {
	int A,B, array_int[N], i, j;
	double C,D, array_double[F];
	srand(time(0));
	printf("Введите интервал [A,B] И [C,D]\n");
	scanf("%d%d%lf%lf", &A,&B,&C,&D);
	FILE*file;
	file = fopen("file.txt","w");
	printf("\n");
	for (i = 1; i <= N; i++){
		array_int[i] = A +rand()*(B - A+1)/RAND_MAX;
		printf("%d  ", array_int[i]);
	}
	printf("\n\n");
	for (j = 1; j <= F; j++){
		array_double[j] = (float) rand() / RAND_MAX * (D - C) + C;
		printf("%lf  ", array_double[j]);
    }
	for (i=1 , j=1; i<=N , j<=F; i++,j++){
		fprintf(file, "array_int[%d] = %d        ", i, array_int[i]);
		fprintf(file, "array_double[%d] = %lf\n", j, array_double[j]);
		
	}	
fclose(file);
getch();
return EXIT_SUCCESS;
}




//if (NULL == (file = fopen("file.txt", "r"))) {
//    puts("Can`t open the file\a");
//    }

