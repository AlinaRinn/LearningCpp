#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void calculation(x,y,z)
{
double W;
	if (x!=0 && y!=0)
	{
		W = (1+2*x+3*y+4*z)/(pow(x,2)/y + pow(y,2)/x + pow(z,2)/y);
		printf("%.2lf", W);
    }
    else
    {
    printf("ОДЗ не соблюдено");    
	}
}

int main(void)
{
int x,y,z;
FILE*input;
input=fopen("input.txt", "r");
fscanf(input, "%d %d %d", &x,&y,&z);
calculation(x,y,z);
getch();
return EXIT_SUCCESS;
}

