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
		printf("»м€= ");
    	scanf("%s", &c[i]); 
	}
	printf("»мена, кончающиес€ на гласную:\n");
	for (i = 0; i<10; i++)
	{
		len=strlen(c[i]);
		sym=c[i][len-1];
		if (sym == 'е' || sym == 'у'||sym == 'а'||sym == 'о'||sym == 'э'||sym == '€'||sym == 'и'||sym =='ю')
		{
			printf(" %s\n", c[i]);
	    }
	}
getch();
return EXIT_SUCCESS;
}

