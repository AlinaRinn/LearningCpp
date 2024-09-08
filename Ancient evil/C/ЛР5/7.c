#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 30

int main(void) {
int f;
char sent[N]="Your number has been called";
printf("%c%c ", sent[0], sent[1]);
for (int i=0; i<N; i++) {
	if (sent[i]==' ') {
		printf("%c%c ", sent[i+1], sent[i+2] );
	}
}
getch();
return EXIT_SUCCESS;
}

