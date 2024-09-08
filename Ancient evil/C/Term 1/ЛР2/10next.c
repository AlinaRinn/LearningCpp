#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
char str[10][20];
int i=0;
int a = 0;
int b = 1;
int c = 2;
scanf("%s", str[i]);
scanf("%s", str[i]);
scanf("%s", str[i]);
i=0;
while(i < 3)
{	
	printf("%s%s%s\n", str[a], str[b], str[c]);
    if (a == 2 ){
        a = 0;
        b = 1;
        c = 2;
    }
    if( a == 2){
        b = 0;
        c = 1;
        a = 2;
    }
    
    if( c == 2){
        c = 0;
        a = 1;
        b = 2;
    }
i++;
}
a = 0;
b = 1;
c = 2;

while(i < 3)
{
	printf("%s%s%s\n", str[c], str[b], str[a]);
    if( a == 2 ){
        a = 0;
        b = 1;
        c = 2;
    }
    if( b == 2){
        b = 0;
        c = 1;
        a = 2;
    }
    
    if( c == 2){
        c = 0;
        a = 1;
        b = 2;
    }
i++;
}
getch();
return EXIT_SUCCESS;
}

