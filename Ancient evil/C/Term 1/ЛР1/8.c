#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
int x;
printf("������� ����� �� 1 �� 6\n");
scanf("%d", &x);
switch(x)
{
case (1): printf("���"); break;
case (2): printf("�����"); break;
case (3): printf("����"); break;
case (4): printf("����"); break;
case (5): printf("���"); break;
case (6): printf("������"); break;
default: printf("��� ����������") ;break;
}
getch();
return EXIT_SUCCESS;
}

