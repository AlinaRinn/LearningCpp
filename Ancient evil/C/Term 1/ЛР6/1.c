#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 7
#define M 5

void zap ();
void vivod0 ();
void vivod1 ();

int main(void) {
	srand(time(NULL));
	int a[N][M], A=-29, B=42;
	zap (a);
	vivod0 (a);
	vivod1 (a);
getch();
return EXIT_SUCCESS;
}

void vivod0 (int a[N][M]) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void vivod1 (int a[N][M]) {
	for (int i=0; i<N; i++) {
		printf(" ");
		for (int j=0; j<M; j++) {
			if (a[i][j]<0) {
				printf("  -  ");
			}
			else {
				printf("  +  ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void zap (int a[N][M]) {
	int A=-29, B=42;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			a[i][j]= B + rand() * (A - B + 1) / RAND_MAX;
//			printf("%5d", a[i][j]);
		}
//		printf("\n");
	}
//	printf("\n\n");
}

//	for (int i=0; i<N; i++) {
//		for (int j=0; j<M; j++) {
//			if (a[i][j]<0) {
//				a[i][j]= (char) '-';
//			}
//			else {
//				a[i][j]= (char) '+';
//			}
//		}
//	}
