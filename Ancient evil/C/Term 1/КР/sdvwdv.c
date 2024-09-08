#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <malloc.h>
#define N 3
#define F 3
#define G 3

int main(void) {
	srand(time(NULL));
	int a[N], b[F][G],*c, *d, A=-100, B=100, i, j, temp=0, temp2=0, f=-1, f1=-1;
	double hh1=0.0, temp1=0.0;
	for (i = 0; i < N; i++) {                                              
		a[i]=A + rand() * (B - A + 1) / RAND_MAX;  
		printf("%12d", a[i]);                                                   
	}
	printf("\n\n");
	for (i = 0; i < F; i++) {
        for (j = 0; j < G; j++) {
            b[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
            printf("%12d", b[i][j]);
        }
        printf("\n");
	}
	for (i = 0; i < N; i++) {
		if (a[i]>0) {
        	temp++;
        }
	}
	printf("\n\n");
	printf("Массив 1:");
	c = (int*)malloc(temp * sizeof(int));
	for (i = 0; i < N; i++) {
		f++;
		if (a[i]>0) {
            c[f] = a[i];
            printf("%12d", c[f]);
        }
        else {
        	f=f-1;
		}
	}
	for (i = 0; i < F; i++) {
        for (j = 0; j < G; j++) {
			hh1+=b[i][j];
        }
	}
	temp1=hh1/(F*G);
	printf("\n\nСр знач: %lf", temp1);
	for (i = 0; i < F; i++) {
        for (j = 0; j < G; j++) {
			if (b[i][j]<temp1) {
				temp2++;
			}
        }
	}
	printf("\n\nМассив 2:");
	d = (int*)malloc(temp2 * sizeof(int));   
	for (i = 0; i < F; i++) {
		for (j = 0; j < G; j++) {
			f1++;
			if (b[i][j]<temp1) {
				d[f1] = b[i][j];
				printf("%8d", d[f1]);
			}
		else {
			f1=f1-1;
		}
    	}
	}
//	for (i = 0; i < temp2; i++) {
//		printf("%6d", d[i]);
//	}
free(c);
free(d);
getch();
return EXIT_SUCCESS;
}

