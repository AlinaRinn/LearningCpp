#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 10

int main(void) {
	srand(time(NULL));
	int i, b[N], c[N], A=1, B=9;
	for (i = 0; i < N; i++) {
        b[i] = A + rand() * (B - A + 1) / RAND_MAX;
        printf("%5d", b[i]);
    }
    
    for (i = 0; i < N; i++) {
        c[i]=b[i];
    }
    
    for(int i = 1; i < N; ++i) {
		for(int j = 0; j < N-i; j++) {
			if(b[j] < b[j+1])	{
				int temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
	printf("\n\n");
	
	for (i = 0; i < N; i++) {
        printf("%5d", b[i]);
    }
    printf("\n\n");
    
    for(int i = 1; i < N/2; ++i) {
		for(int j = 0; j < N/2-i; j++) {
			if(c[j] < c[j+1])	{
				int temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
			}
		}
	}
	
	for(int i = 1; i < N/2; ++i) {
		for(int j = N/2; j < N-i; j++) {
			if(c[j] > c[j+1])	{
				int temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
			}
		}
	}
	
	for (i = 0; i < N; i++) {
        printf("%5d", c[i]);
    }
getch();
return EXIT_SUCCESS;
}

