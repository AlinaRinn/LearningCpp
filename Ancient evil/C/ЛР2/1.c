#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int main(void)
{
int N,i;
double q,t;
printf("¬ведите целое число N\n");
scanf("%d", &N);
i=-2*N;
q=-2*N;
t=-1;
for (i; i<2*N; i+=1)
{
    printf(" %d",i);
}
FILE*out;
out=fopen("output.txt", "w");
for (q; q<2*N; q+=0.3)
{
t=t+1;
if (t==5) 
{
    fprintf(out,"\n");
	t=0;
	fprintf(out," %.1lf",q);
}
else
{
	fprintf(out," %.1lf",q);
}
}
fclose(out);
getch();
return EXIT_SUCCESS;
}

