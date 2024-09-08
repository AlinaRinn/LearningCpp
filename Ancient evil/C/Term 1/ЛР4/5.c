#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 12
int main(void) {
	srand(time(NULL));
	int i, b[N], A=1, B=10, tm_prev, tm_next;
	for (i = 0; i < N; i++) {
        b[i] = 1+i;
        printf("%4d", b[i]);
    }
    printf("\n\n");
    
    for (i = 1; i < N; i+=3) {
    	tm_prev=b[i-1];
    	tm_next=b[i+1];
    	b[i+1]=tm_prev;
    	b[i-1]=tm_next;	
    }
    
    for (i = 0; i < N; i++) {
    	printf("%4d", b[i]);
	}
	printf("\n\n");
	
	for (i = 1; i < N; i+=6) {
    	tm_prev=b[i];
    	tm_next=b[i+3];
    	b[i+3]=tm_prev;
    	b[i]=tm_next;	
    }
    
    for (i = 0; i < N; i++) {
    	printf("%4d", b[i]);
	}
	
	if (N%3!=0) {
		printf("\n\nМассив не кратен 3, последний элемент переставлен не будет");
	}

getch();
return EXIT_SUCCESS; 
}

//1 2 3  4 5 6  7 8  9  10 11 12     
//3 2 1  6 5 4  9 8  7  12 11 10
//3 5 1  6 2 4  9 11 7  12  8 10

