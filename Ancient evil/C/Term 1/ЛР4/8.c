#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 10
#define M 10

int main(void) {
	srand(time(NULL));
	int i,j=0, b[N][M],A=1, B=100;
	for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            b[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
            printf("%5d", b[i][j]);
        }
        printf("\n");
	}
	printf("\n\n");
	
	for (int k = 0; k < N; k++) {
  		for(int i = 0;i < N; i++) {  
    		for (int j = N - 1; j > i; j--)  {
      			if (b[k][j] < b[k][j-1]) {
        			int tmp = b[k][j];  
      				b[k][j] = b[k][j-1];  
        			b[k][j-1] = tmp;  
            	}
            }
        }
    }
	
	for (i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
        	printf("%5d", b[i][j]);
    	}
    	printf("\n");
    }

	
getch();
return EXIT_SUCCESS;
}

