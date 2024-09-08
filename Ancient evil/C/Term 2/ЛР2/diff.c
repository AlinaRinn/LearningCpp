#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

const double A = 1, B = 5.5;

void vivod();
void method_euler_mod(double);
void method_euler(double);
void method_euler_improve(double);
void method_runge_kutt(double);
double f (double, double);
double fd (double, double);

int main(void) {
	FILE*file;
	file=fopen("diff.txt", "w");
	fclose(file);
	printf("Очищено\n");
	double step[3] = { 0.5, 0.1, 0.01 };
	for (int i = 0; i < 3; i++) {
		vivod(step[i]);
		method_euler(step[i]);
		method_euler_mod(step[i]);
		method_euler_improve(step[i]);
		method_runge_kutt(step[i]);
		printf("Записано шаг %.2f\n", step[i]);
	}
	getch();
	return EXIT_SUCCESS;
}

void vivod(double h) {
	FILE*file;
	file=fopen("diff.txt", "a");
	fprintf(file, "\n\nh=%.2f\n\nx=\n\n", h);
	for (double i = A; i <= B; i += h) {
		fprintf(file, "%12.2f", i);
	}
	fclose(file);
}

double f(double x, double y) {
	return ((x+1)*exp(x)-y)/x;
}

double fd(double x, double y) {
	return -x/(x*exp(x)+pow(x,2)-exp(x)+y);
}

void method_euler(double h) {
	FILE*file;
	file=fopen("diff.txt", "a");
	double y = exp(1);
	double x = 1;
	fprintf(file,   "\n\neuler=\n\n%17.8lf", y);
	for (double i=x; i < B; i += h) {
		y += h * f(x, y);
		x += h;
		fprintf(file,   "%17.8lf", y);
	}
	fclose(file);
}

void method_euler_mod(double h) {
	FILE*file;
	double y = exp(1), xd, yd;
	file=fopen("diff.txt", "a");
	fprintf(file,   "\n\neuler_mod=\n\n%17.8lf", y);
	for (double i = A; i < B; i += h) {
		xd = i + h / 2;
		yd = y + h / 2 * fd(i, y);
		y = y + h * f(xd, yd);
		fprintf(file,   "%17.8lf", y);
	}
	fclose(file);
}

void method_euler_improve(double h) {
	FILE*file;
	double y = exp(1), yd;
	file=fopen("diff.txt", "a");
	fprintf(file,   "\n\neuler_improve=\n\n%17.8lf", y);
	for (double i = A; i < B; i += h) {
		yd = y + h * fd(i, y);
		y = y + h / 2 * (f(i, y) + f(i + h, yd));
		fprintf(file,   "%17.8lf", y);
	}
	fclose(file);
}

void method_runge_kutt(double h) {
	FILE*file;
	double y = exp(1);
	double k1, k2, k3, k4;
	file=fopen("diff.txt", "a");
	fprintf(file,   "\n\nrunge_kutt=\n\n%17.8lf", y);
	for (double i = A; i < B; i += h) {
		k1 = f(i, y);
		k2 = f(i + (h / 2), y + (k1*h / 2));
		k3 = f(i + (h / 2), y + (k2*h / 2));
		k4 = f(i + h, y + k3*h);
		y = y + (h / 6) * (k1+2*k2+2*k3+k4);
		fprintf(file,   "%17.8lf", y);
	}
	fclose(file);
}

//x*exp(x)+exp(x)+(y/x)-(exp(x)/x)

