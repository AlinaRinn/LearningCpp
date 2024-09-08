#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 5
#define M 5

int main(void) {
srand(time(NULL));
char a[50];
int k, C=1.1, D=100.1;
double l;
FILE*file;
file=fopen("out.txt", "w");
while (k<N) {
	k++;
	scanf("%s", &a);
	fprintf(file, "%s\n", a);
}
fclose(file);
file=fopen("out.txt", "a");
k=0;
while (k<M) {
	k++;
	l= (float) rand() / RAND_MAX * (D - C) + C;
	fprintf(file, "%lf\n", l);
}
fclose(file);
getch();
return EXIT_SUCCESS;
}

