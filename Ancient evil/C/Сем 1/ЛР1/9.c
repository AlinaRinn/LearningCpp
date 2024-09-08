#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
int a,b,c,d,a1,a2,b1,b2,c1,c2,d1,d2,mod1,mod2,sum=0;
printf("¬ведите 4 числа\n");
scanf("%d%d%d%d",&a,&b,&c,&d);
a1 = a*100;
b1 = b*100;
c1 = c%10;
c2 = c/10;
d1 = d%10;
d2 = d/10;
c = c1*10 + c2;
d = d1*10 + d2;

mod1=a1+c;
mod2=b1+d;
printf("%d %d\n", mod1,mod2);
while(mod1>0){
	a2 = mod1 % 10;
	mod1/=10;
	sum += a2 ;
}
printf("%d",sum);

getch();
return EXIT_SUCCESS;
}

