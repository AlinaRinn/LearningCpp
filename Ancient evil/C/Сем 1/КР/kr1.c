#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <malloc.h>
#define M 3
#define N 3


void zapolnenie(int array[N][M]) {
	int i,j, A=100, B=900;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			array[i][j] = rand()%(B - A+1)+A;
		}
	}
}

void vivod(int array[N][M]) {
	int i,j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			printf("%7d", array[i][j]);
		}
	printf("\n");
	}
}

double srznach(int array[N][M], double temp) {
	int i,j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			temp+=array[i][j];
		}
	}
	temp=temp/(M*N);
	printf("\n\nсрзнач %.3lf", temp);
return temp;
}

double maxim(int array[N][M], double max) {
    max = -999999;
    int i, j;
    for (i = 1; i < N; i++) {
        if (array[i][i] > max) {
            max = array[i][i];
        }
    }
return max;
}

int main(void) {
	double temp=0, max=0;
	srand(time(NULL));
	int array[N][M];
    zapolnenie(array);
	vivod(array);
	temp=srznach(array, temp);
	printf("\nПроизв ср знач эл на макс эл глав диагон: %.3lf ", temp*maxim(array, max));
getch();
return EXIT_SUCCESS;
}

