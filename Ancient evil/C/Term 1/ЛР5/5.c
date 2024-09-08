#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define N 5
#define M 30

int main(void) {
	int i=0, j=0;
	char dog[N][M];
	while (i<N) {
		scanf("%s", &dog[i]);
		i++;
	}
	printf("\n");
	for (i=0; i<N; i++) {
		if (strlen(dog[i])<=5) {
		printf("%s", dog[i]);
		printf("\n");
		}
	}
getch();
return EXIT_SUCCESS;
}

