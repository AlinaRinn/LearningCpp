#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 5
#define M 5
#define C 5
#define D 5

int main(void) {
	int A,B, array[N][M], new_array[C][D], i, j, min;
	min=0;
	srand(time(NULL));
	printf("Введите диапазон заполнения [A,B]\n");
	scanf("%d%d", &A,&B);
	FILE*file;
	file = fopen("array.txt","w");
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			array[i][j] = rand()%(B - A+1)+A;
			fprintf(file, "%6d", array[i][j]);
			}
		fprintf(file,"\n");
	}
	fclose(file);
	printf("\n");
	file = fopen("array.txt","r");
	for (i = 0; i < C; i++){
		for (j = 0; j < D; j++){
			fscanf(file, "%d", &new_array[i][j]);
		}
	}
	int temp=0, sumodd=0, kolvo=0;
	for (i = 0; i < C; i++){
		for (j = 0; j < D; j++){
			if (new_array[i][j]<0) {
				temp=new_array[i][j];
				if (temp<min) {
					min=temp;
				}
	    	}
	    	if (i%2==1) {
	    		sumodd+=new_array[i][j];
			}
			if (i+j==C) {
                if (new_array[i][j] % 2 != 0) {
                kolvo++;
                }
            }
		}
	}
if ((N!=M)||(C!=D)) {
	printf("Осторожно, она из матриц не квадратная.\n Подсчет диогонали будет производится неккоректно");
}
fclose(file);
if (min!=0) {
	printf("\nМинимальное отр значение: %d", min);
}
else {
	printf("Отр значений нет");
}
printf("\nCумма элементов в четных строках: %d", sumodd);
printf("\nКоличество нечетных элементов на побочной диагонали массива: %d", kolvo);
getch();
return EXIT_SUCCESS;
}

