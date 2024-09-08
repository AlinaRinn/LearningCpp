#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int euhaoem(int *array, int N) {
	int i, antiodd, temp;
	for (i=0; i<N; i++) {
		if (array[i]%2!=0) {
	    	antiodd=array[i];
		}
		if (array[i]>antiodd) {
	    	temp++;
		}	
	}
return temp;
}

int minec5(int *array, int N) {
	int i, c5, temp=999999; 
	for (i=0; i<N; i++) {
		if (array[i]%5==0) {
	    	c5=array[i];
		}	
		if (temp>c5) {
			temp=c5;
		}
	}
return temp;
}

int minerh(int *array, int N) {
	int i, rh, temp=-999999; 
	for (i=0; i<N; i++) {
		if (i>(N/2)) {
	    	rh=array[i];
		}	
		if ((temp<rh) && rh<0) {
			temp=rh;
		}
	}
return temp;
}

int main(void) {
	srand(time(NULL));
	const int N=10;
	int array[N], i, A=-100, B=100;
	for (i=0; i<N; i++) {
		array[i] = rand()%(B - A+1)+A;
		}
    printf("Количество элементов, которые больше последнего нечет элемента в массиве: %d", euhaoem(array, N));
    printf("\nМинимальный элемент кратный 5: %d ", minec5(array, N));
    printf("\nМаксимальный отрицательный элемент правой половины массива: %d \n\n", minerh(array, N));
	for (i=0; i<N; i++) {
		printf("%d  ", array[i]);
		}
	
getch();
return EXIT_SUCCESS;
}


