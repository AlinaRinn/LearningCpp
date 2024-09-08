#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void print_range(int N)
{
	int i;
	i=-N;
	for (i;i<N;i++) 
	{
		printf(" %d", i);
	}
}

int main(void)
{
int n;
FILE*in;
in=fopen("in.txt", "r");
fscanf(in, "%d", &n);
print_range(n);
printf(" %d",n);
fclose(in);
getch();
return EXIT_SUCCESS;
}

