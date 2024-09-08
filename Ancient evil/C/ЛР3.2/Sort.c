#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 200000;
const int A = -25000, B = 25000;

void swap(long long int *x, long long int *y) {
	long long int t = *x;
	*x = *y;
	*y = t;
}

void generation() {
	srand(time(0));
	FILE *file;
	file = fopen("input.txt", "w");
	for (int i = 0; i < N; i++) {
		fprintf(file, "%7d", A + rand() % (B - A + 1));
	}
	fclose(file);
}

void read(long long int a[N]) {
	FILE *file;
	if ((file = fopen("input.txt", "r")) == NULL) {
		printf("file open error");
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		fscanf(file, "%7d", &a[i]);
	}
	fclose(file);
}

void prin(long long int a[N]) {
	FILE *file;
	file = fopen("input.txt", "a");
	fprintf(file, "\n");
	for (int i = 0; i < N; i++) {
		fprintf(file, "%6d", a[i]);
	}
	fclose(file);
}

void simple_sort() {
	FILE*file1;
	file1=fopen("time.txt", "a");
	long long int a[N], min, count = 0;
	read(a);
	double t1 = (double) clock();
	for (int i = 0; i < N - 1; i++) {
		min = i;
		for (int j = i + 1; j < N; j++) {
			if (a[j] < a[min])
				min = j;
		}
		swap(&a[i], &a[min]);
		count++;
	}
	double t2 = (double) clock();
	prin(a);
	fprintf(file1, "\t%d\t\t%.10lf\n", count, (t2 - t1) / CLOCKS_PER_SEC);
	fclose(file1);
}

void bubble_sort() {
	FILE*file1;
	file1=fopen("time.txt", "a");
	long long int a[N], count = 0, sw = 1;
	read(a);
	double t1 = (double) clock();
	while (sw > 0) {
		sw = 0;
		for (int j = 0; j < N - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				count++;
				sw = 1;
			}
		}
	}

	double t2 = (double) clock();
	prin(a);
	fprintf(file1, "\nbubble_sort\t%d\t%.10lf\n", count, (t2 - t1) / CLOCKS_PER_SEC);
	fclose(file1);
}

void comb_sort() {
	FILE*file1;
	file1=fopen("time.txt", "a");
	long long int a[N], count = 0, step = N - 1;
	read(a);
	double fakt = 1.2473309;
	double t1 = (double) clock();
	while (step >= 1) {
		for (int i = 0; i + step < N; ++i) {
			if (a[i] > a[i + step]) {
				swap(&a[i + step], &a[i]);
				count++;
			}
		}
		step /= fakt;
	}
	double t2 = (double) clock();
	prin(a);
	fprintf(file1, "\ncomb_sort\t%d\t\t%.10lf\n", count, (t2 - t1) / CLOCKS_PER_SEC);
	fclose(file1);
}

int cou = 0;

void qs(long long int *a, int fir, int last) {
	if (fir < last) {
		long long int i = fir, j = last, p = a[(i + j) / 2];
		do {
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			if (i <= j) {
				swap(&a[i], &a[j]);
				cou++;
				i++;
				j--;
			}
		} while (i <= j);
		qs(a, fir, j);
		qs(a, i, last);
	}
}

void qs_star() {
	FILE*file1;
	file1=fopen("time.txt", "a");
	long long int a[N];
	read(a);
	double t1 = (double) clock();
	qs(a, 0, N - 1);
	double t2 = (double) clock();
	prin(a);
	fprintf(file1, "\nqs_star\t\t%d\t\t%.10lf\n", cou, (t2 - t1) / CLOCKS_PER_SEC);
	fclose(file1);
}

int main(void) {
	printf("Выполнение...");
	FILE*file1;
	file1=fopen("time.txt", "w");
	fprintf(file1, "\t\tswap\t\ttime\n\nsimple_sort");
	fclose(file1);
	generation();
	simple_sort();
	bubble_sort();
	comb_sort();
	qs_star();
	printf("Завершено");
	return EXIT_SUCCESS;
}
