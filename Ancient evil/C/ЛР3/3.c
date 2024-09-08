#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 20

int main(void)
{
	int A,B, array_int[N], temp;
	srand(time(0));
	printf("Введите интервал [A,B]\n");
	scanf("%d%d", &A,&B);
	for(int i=0; i <N; i++){
		array_int[i] = A +rand()*(B - A+1)/RAND_MAX;
		printf("%d ", array_int[i]);
	}
	for (int i=N-1; i >=0; i--){
		
		//printf("%d ", array_int[i]);
		if (array_int[i] %4 ==0 && array_int[i]>0) {
			printf("net=%d ",array_int[i]);
			temp=array_int[i];
		}
	}
	if (temp !=0) {
		printf("\n%d",temp);
	}
	else {
		printf("\n\nПоложительных чисел, кратных четырем, не обнаружено");
	}
getch();
return EXIT_SUCCESS;
}

