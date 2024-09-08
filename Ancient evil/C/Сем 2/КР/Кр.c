#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double Lower_Limit_A = -0.5;
const double Upper_Limit_B = 2;
const double Lower_Limit_C = -5;
const double Upper_Limit_D = 3.5;
const double Error_rate = 1e-4;

double Function_0(double x) {
	return 6*x-x*x*x*x+5;
}

double Function_1(double x) {
	return 1/sqrt(4-x);
}

void method_left_rectangle() {
	FILE*file;
	file=fopen("output.txt", "a");
	fprintf(file, "Method left rectangle\n\n   Function: 6x-x^4+5     Bound of integration: from %.2f to %.2f\n\n", Lower_Limit_A, Upper_Limit_B);
	fprintf(file, "         n            h           S1           S2        S1-S2\n\n");
	int n = 10;
	double h, Area_0, Area_finish;
	do {
		h = (double) (Upper_Limit_B - Lower_Limit_A) / n;
		Area_0 = 0, Area_finish = 0;
		for (int i = 0; i < n; i++)
			Area_0 += h * Function_0(Lower_Limit_A + i * h);
			n *= 2;
			h = (double) (Upper_Limit_B - Lower_Limit_A) / n;
		for (int i = 0; i < n; i++)
			Area_finish += h * Function_0(Lower_Limit_A + i * h);
		fprintf(file, "%10d   %10f   %10f   %10f   %10lf\n\n", n, h, Area_0, Area_finish, fabs(Area_0 - Area_finish));
	} while (fabs(Area_0 - Area_finish) >= Error_rate);
	fprintf(file, "   Error rate: %lf     Answer: %f\n\n", fabs(Area_0 - Area_finish), Area_finish);
	fclose(file);
}

void method_trapeze() {
	FILE*file;
	file=fopen("output.txt", "a");
	fprintf(file, "Method Trapeze\n\n   Function: 1/sqrt(4-x)     Bound of integration: from %.2f to %.2f\n\n", Lower_Limit_C, Upper_Limit_D);
	fprintf(file, "         n            h           S1           S2        S1-S2\n\n");
	int n = 10;
	double h, Area_0, Area_finish;
	do {
		h = (double) (Upper_Limit_D - Lower_Limit_C) / n;
		Area_0 = 0, Area_finish = 0;
		for (int i = 0; i < n; i++)
			Area_0 += h * (Function_1(Lower_Limit_C + i * h) + Function_1(Lower_Limit_C + (i + 1) * h)) / 2;
			n *= 2;
			h = (double) (Upper_Limit_D - Lower_Limit_C) / n;
		for (int i = 0; i < n; i++)
			Area_finish += h * (Function_1(Lower_Limit_C + i * h) + Function_1(Lower_Limit_C + (i + 1) * h)) / 2;
		fprintf(file, "%10d   %10f   %10f   %10f   %10lf\n\n", n, h, Area_0, Area_finish, fabs(Area_0 - Area_finish)); 
	} while (fabs(Area_0 - Area_finish) >= Error_rate);
	fprintf(file, "   Error rate: %lf     Answer: %f\n\n", fabs(Area_0 - Area_finish), Area_finish);
	fclose(file);
}

int main(void) {
	FILE*file;
	file=fopen("output.txt", "w");
	printf("Cleared\n\n");
	fclose(file);
	method_left_rectangle();
	method_trapeze();
	printf("Results save in file 'output.txt' ");
return EXIT_SUCCESS;
}
