#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 8
#define M 8

int main(void) {
	srand(time(NULL));
	int b[N][M], c[N][M], A=-100, B=100, temp=0, score=0, final, out, st=0;
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            b[i][j] = A + rand() * (B - A + 1) / RAND_MAX;
            printf("%7d", b[i][j]);
        }
	printf("\n");
	}
	printf("\n\n");

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
        	if (b[i][j]%4==0) {
				c[i][j]=b[i][j];
				printf("%7d", c[i][j]);
			}	
			else {
				c[i][j]=0;
				printf("%7d", c[i][j]);
			}
        }
        printf("\n");
    }
    printf("\n\n");
    
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
        	if (c[i][j]!=0) {
        		temp+=c[i][j];
        		score++;
        	}
    	}
    	if (score!=0) {
    	final=temp/score;
        printf("%7d", final );
        temp=0;
        score=0;
        }
        else {printf("    Нет");}
        if (out>final) {
        	out=final;
        	st=j;
		}
	}
	printf("\n\nСтолбец с минимальным сред знач эл-ов кратных 4 (массив 1): [%d]", st); 
    printf("\n\nМинимальное сред знач эл-та кратного 4: %d", out);    		      		
getch();
return EXIT_SUCCESS;
}

