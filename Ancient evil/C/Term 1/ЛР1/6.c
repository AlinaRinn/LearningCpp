#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <windef.h>

int main(void)
{
int s,d,f,Mid,Max,Min;
double srznch;
printf("������� 3 �����\n");
scanf("%d%d%d", &s, &d, &f);
if(s%2==0 && d%2==0 && f%2==0)
{
Max=max (s,max (d,f));
Min=min (s,min (d,f));
if( Max>s && s>Min ) {Mid=s;}
if( Max>d && d>Min ) {Mid=d;}
if( Max>f && f>Min ) {Mid=f;}
printf("��� ���������� ������, ���������:  %d\n",(Max*Min)%Mid);
}
if(s%2==1 || d%2==1 || f%2==1)
{
srznch=(s+d+f)/3;
printf("���� �� ���������� ��������, ���������:  %.1lf  %.1lf  %.1lf",s/srznch,d/srznch,f/srznch);
}
getch();
return EXIT_SUCCESS;
}
