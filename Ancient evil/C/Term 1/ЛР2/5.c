#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int main(void)
{
double i,y,z;
printf("�������� �: ");
for(i=-13.2;i<15.5;i+=5.6)
{
	printf("  %.1lf", i);
}
printf("\n\n�������� �: ");
for(i=-13.2;i<15.5;i+=5.6)
{
	y=3*pow(i,3)+3*pow(i,4)+6*i+1;
	printf("  %.1lf", y);
	z+=y;
}
printf("\n\n����� �������� �: %.1lf",z);
getch();
return EXIT_SUCCESS;
}

