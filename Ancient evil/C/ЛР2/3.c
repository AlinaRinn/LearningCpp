#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
int i,a,b;
b=0;
printf("������� �����\n");
scanf("%d", &a);
if (a%5!=0)
{
	printf("�� ������� ������"); 
}
while (a%5==0)
{
	b++;
	a=a/5;
	printf("����� / 5 = %d\n",a);
}
printf("\n������� �� ����, ���: %d",b);
getch();
return EXIT_SUCCESS;
}

