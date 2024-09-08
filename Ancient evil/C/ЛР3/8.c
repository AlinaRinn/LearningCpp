#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <malloc.h>

/*Для двумерного массива из N элементов, которые содержат случайные дробные значения от A до B, 
с помощью функций найти индексы максимального отрицательного элемента главной диагонали, количество положительных элементов с 
четными индексами столбца и нечетными строки, сумму элементов, целая часть которых заканчиваются на 1. 
Использовать только локальные переменные.*/

void minerh(double** arr, int N) {
    int i;
    int index = -1;
        for (i=0; i<N; i++) {
                if (arr[i][i] < 0 && index == -1)
                        index = i;
                else
                    if (arr[i][i] < 0 && arr[i][i] > arr[index][index])
                        index = i;
        }
    printf("Наибольший отрицательный элемент на диагонали: %d-й",index+1);
}
    

void kpechins(double** arr, int N) {
    int ff = 0;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((arr[i][j] > 0) && (i % 2 == 0) && (j % 2 == 1)) {
                ff++;
            }
        }
    }
    printf("\nКоличество положительных эл-ов нечет строка чет столбец: %d", ff);
}
 
void chas(double** arr, int N) {
    int i, j, t, sc, tm;
    double fif = 0.0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            t = (int)arr[i][j];
            if ((t % 10 == 1) || (t % 10 == -1)) {
                fif += arr[i][j];
            }
        }
    }
    if (fif==0) {
    	printf("\nЭлементов, целая часть которых заканчиваются на 1, нет");
	}
	else {
		printf("\nСумма эл-ов с концом целой части '1': %lf", fif);
	}
}
 
int main(void) {
    const int N = 5;
    double** arr = (double **)malloc(N * sizeof(double *));
    double A, B;
    int i, j;
    printf(" A :");
    scanf("%lf", &A);
    printf(" B :");
    scanf("%lf", &B);
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        arr[i] = (double *)malloc(N * sizeof(double));
        for (j = 0; j < N; j++) {
            arr[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
            printf("%12lf", arr[i][j]);
        }
        printf("\n");
 
    }
    minerh(arr, N);
    kpechins(arr, N);
    chas(arr, N);
 
 
    for (i = 0; i < N; i++)
        free(arr[i]);
    free(arr);
    return EXIT_SUCCESS;
}

