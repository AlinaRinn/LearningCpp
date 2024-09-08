#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

double function(double z)
{   
double c;
c=3*pow(z,3)+3*pow(z,4)+6*z+1;
return c;
}

double mult(double y,double x)
{
	double b=1;
	for (x = -13.2; x <= 15.5; x += 5.6) {
	y = function(x);
	b*=y;
	}
return b;
}
  
int main(void)
{   
    double j,f,i,k;
    f=1; j=1;
        for(i=-13.2;i<15.5;i+=5.6)
		{
			printf("%.2lf   ", i);
		}
		printf("\n\n");
		for(i=-13.2;i<15.5;i+=5.6)
		{   
		    k=j;
			j=function(i);
			printf("%.4lf ",j);
			f=mult(k,j);
		}
	printf("\n\nПроизведение: %lf",f);
getch();
return EXIT_SUCCESS;
}

