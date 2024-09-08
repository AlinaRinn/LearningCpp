#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 5

int main(void) {
	int A,B, array[N], i,a,b;
	a=0;
	b=0;
	srand(time(0));
	printf("Введите интервал [A,B]\n");
	scanf("%d%d", &A,&B);
	FILE*file;
	file = fopen("files.txt","w");
	printf("\n");
	for (i = 0; i <= N; i++){
		array[i] = A +rand()*(B - A+1)/RAND_MAX;
		fprintf(file, "%d  ", array[i]);
		if (array[i]%2==0 && array[i]>0) {
			a+=array[i];
		}
		if (array[i]%2==-1 && array[i]<0) {
			b+=array[i];
		}
	}
	fprintf(file, "\n%d  ", a);
	fprintf(file, "\n%d  ", b);
	printf("Выполнено");
getch();
return EXIT_SUCCESS;
}

