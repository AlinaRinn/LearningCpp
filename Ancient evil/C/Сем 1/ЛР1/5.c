#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) 
{
FILE*data;
data = fopen("data.txt", "r");
if (data == NULL) printf("������, ����");
int max, x, y;
double mid, min, a, b, c;
fscanf(data, "%d%d%lf%lf%lf", &x, &y, &a, &b, &c);
max=(x > y) ? x : y;
min=(((a<b)?a:b)<c)?((a<b)?a:b):c;
printf("������������ ����� ����� ����� %d\n����������� ����� ������� ����� %lf", max, min);
fclose(data);
getch();
return EXIT_SUCCESS;
}
