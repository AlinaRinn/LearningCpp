#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 10

typedef struct {
	char Name[100];
 	int Date_of_born;                 
} Theorem ;

typedef struct {
	char FullName[100];
	char Country[100];
 	int Date_of_born;             
 	int Date_of_death;
 	int countTheorems;
 	Theorem*counter;
} Matematiki ;

int main(void) {
	Matematiki count[N];
	Matematiki t;
	Matematiki d;
	FILE * file1;
	file1 = fopen("math.txt","r");
	if (file1 == 0) {
 		printf("error"); 
		}
 	for (int i=0; i<N; i++) {
		fscanf(file1, "%s %s %d %d %d", count[i].FullName, count[i].Country, &count[i].Date_of_born, &count[i].Date_of_death, &count[i].countTheorems);
		}
	fclose(file1); 
	
	printf("                          Математики\n\n"); 
	printf("%25s%20s%10s%10s%10s\n\n", "Name", "Country", "DateBrn", "DateDth", "Theorems"); 
	for (int i=0; i<N; i++) {
 		printf("%25s", count[i].FullName);
		printf("%20s", count[i].Country);
		printf("%10d", count[i].Date_of_born);
		printf("%10d", count[i].Date_of_death);
		printf("%10d", count[i].countTheorems);
		printf("\n");
	} 
	
	printf("\n                          Больше всего теорем\n\n"); 
	printf("%25s%20s%10s%10s%10s\n\n", "Name", "Country", "DateBrn", "DateDth", "Theorems"); 
	for (int i=0; i<N; i++) {
		if (count[i].countTheorems>=10) {
 		printf("%25s", count[i].FullName);
		printf("%20s", count[i].Country);
		printf("%10d", count[i].Date_of_born);
		printf("%10d", count[i].Date_of_death);
		printf("%10d", count[i].countTheorems);
		printf("\n");
		}
	} 
	
//	int tmp;
//	for (int i = N - 1; i >= 0; i--)
//  {
//        for (int j = 0; j < i; j++) 
//     {
//          if (count[j].Date_of_born > count[j+1].Date_of_born)
//          {
//              tmp = count[j].Date_of_born;
//                count[j].Date_of_born = count[j+1].Date_of_born;
//                count[j+1].Date_of_born = tmp;
//            }
//        }
//    }
	for (int i = N-1; i > 0; --i) {
		if (count[i].Date_of_born > count[i-1].Date_of_born) {
			t = count[i];
			count[i] = count[i-1];
			count[i-1] = t;
			i = N;
		}
	}
    
	printf("\n                          Год рождения ^\n\n"); 
	printf("%25s%20s%10s%10s%10s\n\n", "Name", "Country", "DateBrn", "DateDth", "Theorems"); 
	for (int i=0; i<N; i++) {
 		printf("%25s", count[i].FullName);
		printf("%20s", count[i].Country);
		printf("%10d", count[i].Date_of_born);
		printf("%10d", count[i].Date_of_death);
		printf("%10d", count[i].countTheorems);
		printf("\n");
	} 
	
	for (int i = N; i > 0; --i) {
		if (count[i].Date_of_death < count[i-1].Date_of_death) {
			d = count[i];
			count[i] = count[i-1];
			count[i-1] = d;
			i = N;
		}
	}
	
	printf("\n                          Год смерти v\n\n"); 
	printf("%25s%20s%10s%10s%10s\n\n", "Name", "Country", "DateBrn", "DateDth", "Theorems"); 
	for (int i=0; i<N; i++) {
 		printf("%25s", count[i].FullName);
		printf("%20s", count[i].Country);
		printf("%10d", count[i].Date_of_born);
		printf("%10d", count[i].Date_of_death);
		printf("%10d", count[i].countTheorems);
		printf("\n");
	} 
	

getch();
return EXIT_SUCCESS;
}

