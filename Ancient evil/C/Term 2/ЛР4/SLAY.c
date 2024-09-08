#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int N = 5, M = 6;

void swap(float *x, float *y) {
	float t = *x;
	*x = *y;
	*y = t;
}

void reader(float a[N][M]) {
	FILE *file;

	file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("file open error");
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			fscanf(file, "%f", &a[i][j]);
	}
}

void printer(float a[N]) {
	FILE *file;
	file = fopen("output.txt", "a");
	char al[] = "abcde";
	for (int i = 0; i < N; i++) {
		fprintf(file, "%c=%.20lf\t", al[i], a[i]);
	}
	fprintf(file, "\n");
	fclose(file);

}

void method_Gauss() {
	float a[N][M];
	reader(a);
	int ind, count, c = 1;
	while (c > 0) {
		c = 0;
		for (int i = 0; i < N; i++) {
			ind = i;
			count = 0;
			while ((a[ind][i] == 0) && (count < N)) {
				ind = (ind + 1) % N;
				count++;
			}
			if (ind != i) {
				c = 1;
				for (int j = 0; j < M; j++)
					swap(&a[i][j], &a[ind][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--)
			a[i][j] /= a[i][i];
		for (int k = i + 1; k < N; k++) {
			for (int j = M - 1; j >= 0; j--) {
				a[k][j] -= a[i][j] * a[k][i];

			}
		}
	}

	float b[M];
	for (int i = 0; i < N; i++)
		b[i] = a[i][N];
	for (int i = N - 2; i >= 0; i--)
		for (int j = i + 1; j < N; j++)
			b[i] -= b[j] * a[i][j];

	printer(b);
	reader(a);
	printf("Gauss\n");
	float S;
	for (int i = 0; i < N; i++) {
		S = 0;
		for (int j = 0; j < M - 1; j++) {
			S += a[i][j] * b[j];
		}
		printf("S%d = %lf\t\tError rate = %lf \n", i, S, fabs(S-a[i][M-1]));
	}

}

void method_Gauss_Zeidel() {
	float a[N][M], old[N], new[N], error[N], max;
	float E = 1e-13;
	int ind, count, c=1;
	reader(a);
	while (c > 0) {
		c = 0;
		for (int i = 0; i < N; i++) {
			ind = i;
			count = 0;
			while ((a[ind][i] == 0) && (count < N)) {
				ind = (ind + 1) % N;
				count++;
			}
			if (ind != i) {
				c = 1;
				for (int j = 0; j < M; j++) {
					swap(&a[i][j], &a[ind][j]);
				}
			}
		}
	}
	do {
		for (int i = 0; i < N; i++) {
			old[i] = new[i];
		}
		c = 0;
		for (int i = 0; i < N; i++) {
			new[i] = a[i][M - 1];
			for (int j = 0; j < (M - 1); j++) {
				if (i == j)
					continue;
				new[i] -= (a[i][j] * new[j]);
			}
			new[i] /= a[i][i];
		}
		for (int i = 0; i < N; i++) {
			error[i] = fabs((new[i] - old[i]) / new[i]);
			if (i == 0)
				max = error[i];
			else
				max = ((error[i - 1] < error[i]) ? error[i] : max);
		}
	} while (max > E);
	printer(new);

	printf("Gauss_Zeidel\n");
	float S;
	for (int i = 0; i < N; i++) {
		S = 0;
		for (int j = 0; j < M - 1; j++) {
			S += a[i][j] * new[j];
		}
		printf("S%d = %lf\t\tError rate = %lf \n", i, S, fabs(S-a[i][M-1]));
	}
}

int main(void) {
	FILE*file1;
	file1 = fopen("output.txt", "w");
	printf("Txt cleared\n\n");
	fclose(file1);
	method_Gauss();
	method_Gauss_Zeidel();

	return EXIT_SUCCESS;
}
