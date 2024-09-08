#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <malloc.h>
#define N 5
#define M 5

int main(void) {
	srand(time(NULL));
	int A=-100, B=100, i, j=-1, temp=0, k=0;
	int a[N], *b;
	for (i = 0; i < N; i++) {
		a[i]=rand()%(B - A+1)+A;
	}
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		if (a[i]%2==1 || a[i]%2==-1) {
			temp++;
		}
	}
	b = (int*)malloc(temp * sizeof(int));
	for (i = 0; i < N; i++) {
		j++;
		if (a[i]%2==1) {
			b[j]=a[i];	
		}
		else {
			j--;
		}
	}
	for (j = 0; j < temp; j++) {
		printf("%d ", b[j]);
	}
	free(b);
	printf("\n\n");
	
	int c[N][M];
	int G = -100, H = 100;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			c[i][j] = G + rand() % (H - G + 1);
			printf("%5d", c[i][j]);
		}
		printf("\n");
	}
printf("\n\n");
int *d;
for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i<j) && (c[i][j] % 5 == 0)) {
				k++;
			}
		}
	}
d = (int*) malloc(k * sizeof(int));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i<j) && (c[i][j] % 5 == 0)) {
			d[i] = c[i][j];
			printf("%5d", d[i]);
			}
		}
	}
free(d);
getch();
return EXIT_SUCCESS;
}

