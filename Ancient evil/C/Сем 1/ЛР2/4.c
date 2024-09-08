#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
int a3 = 0;
while (a3<10)
{
	a3++;
	printf("¬ведите число\n");
	int a,a1,a2;
	a=0; a1=0; a2=0;
	scanf("%d", &a);
		while (a>0.1)
		{			
		a1=a%10;
		a2+=a1;
		a=a/10;
		}
	printf("%d\n", a2);
}
getch();
return EXIT_SUCCESS;
}

