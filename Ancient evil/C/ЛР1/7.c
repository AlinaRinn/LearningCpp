#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int main(void)
{
double z, x;
double Q;
printf
("������� �������� x � z\n");
scanf("%lf%lf",&z,&x);
if((z!=4) && (x!=-10) && (z!=10))
{
Q=log(1/(z-4)+z/(x+10-z));
printf("���������: %.4lf", Q);
}
else printf("��� �� ���������, ������������ �������� ���");
getch();
return EXIT_SUCCESS;
}

