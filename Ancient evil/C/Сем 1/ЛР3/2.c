#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20
int main(void)
{
	int i,k;
	k = -10;
	double array[N];
	for (i = 0; i < N; i++)
	{
		array[i] = pow(4,k);
		printf("4^%d=  ", k);
		k++;
		printf("%.10lf\n", array[i]);
    }
getch();
return EXIT_SUCCESS;
}

