#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main(void)
{
FILE*out;
out=fopen("out.txt", "w");
int i,a;
i=0;
for(i;i<10;i++)
{
	a=-38+rand()%56;
	a*=15;
	fprintf(out, "%5d", a);
}
fclose(out);
printf("Случайные числа из данного диапозона, кратные 15, выведены в файл");
getch();
return EXIT_SUCCESS;
}

