#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
int i,a,b;
b=0;
printf("Введите число\n");
scanf("%d", &a);
if (a%5!=0)
{
	printf("Не делится нацело"); 
}
while (a%5==0)
{
	b++;
	a=a/5;
	printf("Число / 5 = %d\n",a);
}
printf("\nДелится на пять, раз: %d",b);
getch();
return EXIT_SUCCESS;
}

