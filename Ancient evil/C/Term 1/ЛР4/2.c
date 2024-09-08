#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 6
#define M 6

/*Для каждой строки двумерного массива найти и записать максимальный элемент кратный 3.
Для каждого столбца двумерного массива найти и записать количество положительных элементов сумма цифр которых кратно 2.
Вывести на экран двумерный массив в прямоугольном виде так,
чтобы справа от него был записан массив максимальных элементов, а снизу – массив с числом положительных элементов сумма цифр которых крат 2*/

int main(void) {
	srand(time(NULL));
	int i,j=0, b[N][M],A=-60, B=100, min=0, minn=0;
	for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            b[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
        }
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		min=b[i][j];
		minn=b[i][j];
		for (j = 0; j < M; j++) {
			printf("%7d", b[i][j]);
			if ((min<b[i][j]) && (b[i][j]%3==0)) {
				min=b[i][j];
			}	
		}
	if ((min==minn) && (min%3!=0)) { printf("             NaN");}
	else { printf("%15d ", min);}
	printf("\n");
	}
	
	printf("\n\n");
	for (j = 0; j < M; j++) {
		min=0;
		for (i = 0; i < N; i++) {
			int s=0, n=b[i][j];
			while (n>0) {s+=n%10; n/=10; }
			if ((b[i][j]>min) && (s%2==0)) {
				min++;
			}	
		}
		if (min==0) { printf("    NaN");}
		else { printf("%7d", min);}
	}
getch();
return EXIT_SUCCESS;
}

