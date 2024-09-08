#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double A = -2;
const double B = 1;
const double E = 1e-4;

double f(double x) {
	return 7*x*x+9;
}

void method_left_rectangle() {
	int n = 10;
	double h, Per, Pos;
	do {
		h = (double) (B - A) / n;
		Per = 0, Pos = 0;
		for (int i = 0; i < n; i++)
			Per += h * f(A + i * h);
			n *= 2;
			h = (double) (B - A) / n;
		for (int i = 0; i < n; i++)
			Pos += h * f(A + i * h);
		printf("Левые прямоугольники:     %d   %f   %f   %f   %lf\n\n", n, h, Per, Pos, fabs(Per - Pos));
	} while (fabs(Per - Pos) >= E);
}

void method_right_rectangle() {
	int n = 10;
	double h, Per, Pos;
	do {
		h = (double) (B - A) / n;
		Per = 0, Pos = 0;
		for (int i = 0; i < n; i++)
			Per += h * f(A + (i + 1) * h);
			n *= 2;
			h = (double) (B - A) / n;
		for (int i = 0; i < n; i++)
			Pos += h * f(A + (i + 1) * h);
		printf("Правые прямоугольники:    %d   %f   %f   %f   %lf\n\n", n, h, Per, Pos, fabs(Per - Pos));
	} while (fabs(Per - Pos) >= E);
}

void method_middle_rectangle() {
	int n = 10;
	double h, Per, Pos;
	do {
		h = (double) (B - A) / n;
		Per = 0, Pos = 0;
		for (int i = 0; i < n; i++)
			Per += h * f(A + (i + 0.5) * h);
		n *= 2;
		h = (double) (B - A) / n;
		for (int i = 0; i < n; i++)
			Pos += h * f(A + (i + 0.5) * h);
		printf("Средние прямоугольники:     %d   %f   %f   %f   %lf\n\n", n, h, Per, Pos, fabs(Per - Pos));
	} while (fabs(Per - Pos) >= E);
}

void method_trapeze() {
	int n = 10;
	double h, Per, Pos;
	do {
		h = (double) (B - A) / n;
		Per = 0, Pos = 0;
		for (int i = 0; i < n; i++)
			Per += h * (f(A + i * h) + f(A + (i + 1) * h)) / 2;
			n *= 2;
			h = (double) (B - A) / n;
		for (int i = 0; i < n; i++)
			Pos += h * (f(A + i * h) + f(A + (i + 1) * h)) / 2;
		printf("ТРАПеция:                   %d   %f   %f   %f   %lf\n\n", n, h, Per, Pos, fabs(Per - Pos)); 
	} while (fabs(Per - Pos) >= E);
}

void method_simpson() {
	int n = 10;
	double h, Per, Pos;
	do {
		h = (double) (B - A) / (n*2);
		Per = 0.0, Pos = 0.0;
		for (int i = 0; i < n; i++)
			Per += (h / 3) * (f(A + 2 * i * h) + 4 * f(A + (2 * i + 1) * h) + f(A + (2 * i + 2) * h));
			n *= 2;
			h = (double) (B - A) / (n*2);
		for (int i = 0; i < n; i++)
			Pos += (h / 3) * (f(A + 2 * i * h) + 4 * f(A + (2 * i + 1) * h) + f(A + (2 * i + 2) * h));
		printf("Симпсон:                    %d  %.15f  %.15f  %.15f  %.16lf\n\n", n, h, Per, Pos, fabs(Per - Pos));
	} while (fabs(Per - Pos) >= E);
}

int main(void) {
	printf("                         n         h         S1        S2       S1-S2\n\n");
//	method_right_rectangle();
//	method_left_rectangle();
//	method_middle_rectangle();
// 	method_trapeze();
	method_simpson();
return EXIT_SUCCESS;
}

