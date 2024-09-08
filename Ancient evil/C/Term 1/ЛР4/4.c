#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 6

int main(void) {
	srand(time(NULL));
	int i,j, b[N][N], buf[N], buff[N], A=-100, B=100, random;
	for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            b[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
            printf("%7d", b[i][j]);
    	}
    	printf("\n");
    }
    printf("\n\n");
    random = rand() * N / RAND_MAX;
    for (i = 0; i < N; i++) {
    	for (j = 2; j <=2 ; j++) {
    		buf[i]=b[i][j];
    	}
    }
    
    for (i = 0; i < N; i++) {
    	for (j = random; j <=random ; j++) {
    		buff[i]=b[i][j];
    		b[i][j]=buf[i];
    	}
    }
    
    for (i = 0; i < N; i++) {
    	for (j = 2; j <=2; j++) {
    		b[i][j]=buff[i];
    	}
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%7d", b[i][j]);
    	}
    	printf("\n");
    }
    printf("\n\n");
 
    for (i=0, j=N-1; i<N; i++,j--) {
    	buf[i]=b[i][j];
    }
    
    for (i = 0; i < N; i++) {
    	for (j = 3; j <=3; j++) {
    		buff[i]=b[i][j];
    		b[i][j]=buf[i];
    	}
    }
    
    for (i=0, j=N-1; i<N; i++,j--) {
    	b[i][j]=buff[i];
	}
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%7d", b[i][j]);
    	}
    	printf("\n");
    }
    
getch();
return EXIT_SUCCESS;
}

