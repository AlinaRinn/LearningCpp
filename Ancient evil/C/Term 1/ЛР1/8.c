#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
int x;
printf("Введите число от 1 до 6\n");
scanf("%d", &x);
switch(x)
{
case (1): printf("Дон"); break;
case (2): printf("Волга"); break;
case (3): printf("Амур"); break;
case (4): printf("Лена"); break;
case (5): printf("Обь"); break;
case (6): printf("Енисей"); break;
default: printf("Нет информации") ;break;
}
getch();
return EXIT_SUCCESS;
}

