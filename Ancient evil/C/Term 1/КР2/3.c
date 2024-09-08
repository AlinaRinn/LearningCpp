#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 10

typedef struct {
	char Firma[100];
	char Mark[100];
 	char Type[100];             
 	char Dobavki[50];
 	int weight;
 	int Cost;
} Choco ;

int main(void) {
	char pol[250];
	Choco raz[N];
	FILE * file;
	file = fopen("Chocoladki.txt","r");
	if (file == 0) {
 		printf("error"); 
	}
	for (int i=0; i<N; i++) {
		fscanf(file, "%s %s %s %s %d %d", raz[i].Firma, raz[i].Mark, raz[i].Type, raz[i].Dobavki, &raz[i].weight, &raz[i].Cost);
		}
	fclose(file);
	
	printf("                          Шоколадки\n\n"); 
	printf("%20s%15s%10s%10s%10s%10s\n\n", "Firma", "Mark", "Type", "Dobavki", "Weight", "Cost"); 
	for (int i=0; i<N; i++) {
 		printf("%20s", raz[i].Firma);
		printf("%15s", raz[i].Mark);
		printf("%10s", raz[i].Type);
		printf("%10s", raz[i].Dobavki);
		printf("%10d", raz[i].weight);
		printf("%10d", raz[i].Cost);
		printf("\n");
	} 
	printf("\n\nВведите Фирму\n");
	scanf("%s", pol);
	printf("                          Ваша фирма:\n\n");
	printf("%20s%15s%10s%10s%10s%10s\n\n", "Firma", "Mark", "Type", "Dobavki", "Weight", "Cost"); 
	for (int i = 0; i < N; i++) {
		if (strcmp(pol, raz[i].Firma) == 0) {
 		printf("%20s", raz[i].Firma);
		printf("%15s", raz[i].Mark);
		printf("%10s", raz[i].Type);
		printf("%10s", raz[i].Dobavki);
		printf("%10d", raz[i].weight);
		printf("%10d", raz[i].Cost);
		printf("\n");
		}
	}
	
	int tmp3=0, tmpy3=0, tmpy2=0;
	for (int i=0; i<N; i++) {
		if (raz[i].weight>tmp3) {
			tmp3=raz[i].weight;
			tmpy3=i;
		}
	}
	
	for (int i=0; i<N; i++) {
		if ((raz[i].weight==tmp3) && (i!=tmpy3)){
			tmpy2=i;
			printf("\n                        Максимальный вес\n\n"); 
			printf("%20s%15s%10s%10s%10s%10s\n\n", "Firma", "Mark", "Type", "Dobavki", "Weight", "Cost"); 
			printf("%20s", raz[tmpy2].Firma);
			printf("%15s", raz[tmpy2].Mark);
			printf("%10s", raz[tmpy2].Type);
			printf("%10s", raz[tmpy2].Dobavki);
			printf("%10d", raz[tmpy2].weight);
			printf("%10d", raz[tmpy2].Cost);
			printf("\n\n");
		}
	}
	
	printf("\n                        Максимальный вес\n\n"); 
	printf("%20s%15s%10s%10s%10s%10s\n\n", "Firma", "Mark", "Type", "Dobavki", "Weight", "Cost"); 
	printf("%20s", raz[tmpy3].Firma);
	printf("%15s", raz[tmpy3].Mark);
	printf("%10s", raz[tmpy3].Type);
	printf("%10s", raz[tmpy3].Dobavki);
	printf("%10d", raz[tmpy3].weight);
	printf("%10d", raz[tmpy3].Cost);
	printf("\n\n");
getch();
return EXIT_SUCCESS;
}

