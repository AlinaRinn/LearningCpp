#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
int main(void)
{   
int i,len,sym;
char c[10][50];
	for (i = 0; i<10; i++) 
	{
		printf("���= ");
    	scanf("%s", &c[i]); 
	}
	printf("�����, ����������� �� �������:\n");
	for (i = 0; i<10; i++)
	{
		len=strlen(c[i]);
		sym=c[i][len-1];
		if (sym == '�' || sym == '�'||sym == '�'||sym == '�'||sym == '�'||sym == '�'||sym == '�'||sym =='�')
		{
			printf(" %s\n", c[i]);
	    }
	}
getch();
return EXIT_SUCCESS;
}

