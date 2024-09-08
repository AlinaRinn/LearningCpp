#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
char str1[1][100], str2[1][100], str3[1][100], temp1[1][200];
scanf("%s%s%s", str1, str2, str3);
printf("\nВведено:\n%s\n%s\n%s\n\nВывод:\n", str1, str2, str3);
printf("%s%s%s\n", str1, str2, str3);
printf("%s%s%s\n", str1, str3, str2);
printf("%s%s%s\n", str2, str1, str3);
printf("%s%s%s\n", str2, str3, str1);
printf("%s%s%s\n", str3, str2, str1);
printf("%s%s%s\n", str3, str1, str2);
getch();
return EXIT_SUCCESS;
}
