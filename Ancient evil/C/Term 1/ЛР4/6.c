#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 5
#define M 5

int main(void) {
	srand(time(NULL));
	int i, j, b[N], c[N][M], tm_start=0, A=1,B=50;
	for (i = 0; i < N; i++) {
        b[i] = rand() % (B - A + 1) + A;
        printf("%6d", b[i]);
    }
    printf("\n\n");
    
    for (i = 0; i < N/2; i++) {
    	tm_start=b[i];
		b[i]=b[N-1-i];
		b[N-1-i]=tm_start;
    }
    
    for (i = 0; i < N; i++) {
        printf("%6d", b[i]);
    }
    printf("\n\n");
    
    for (i = 0; i < N; i++) {
    	for (j = 0; j < M; j++) {
        	c[i][j] = rand() % (B - A + 1) + A;
        	printf("%6d", c[i][j]);
    	}
    	printf("\n");
    }
    printf("\n\n");
    
    for (i = 0; i < N/2; i++) { 
    	for (j = 1; j <= M; j+=2) {
    		tm_start=c[i][j];
			c[i][j]=c[N-1-i][j];
			c[N-1-i][j]=tm_start;
    	}
    }
    
    for (i = 0; i < N; i++) {
    	for (int j = 0; j < M; j++) {
        	printf("%6d", c[i][j]);
    	}
    	printf("\n");
    }
    		
getch();
return EXIT_SUCCESS;
}

