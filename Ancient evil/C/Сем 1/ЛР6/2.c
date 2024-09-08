#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 10

typedef struct {
	char Name_of_index[100];
	char FS_of_inventor[100];
 	int Data_of_born;
 	int index_in_periodicaly;
 	int weight;
 	int group_in_periodicaly;
 	char isotops[5];
} Chemicaly_index ;

int main(void) {
	Chemicaly_index one[N];
	FILE * file;
	file = fopen("list.txt","r");
	if (file == 0) {
 		printf("error"); 
		}
 	for (int i=0; i<N; i++) {
		fscanf(file, "%s %s %d %d %d %d %s", one[i].Name_of_index, one[i].FS_of_inventor, &one[i].Data_of_born, &one[i].index_in_periodicaly, &one[i].weight, &one[i].group_in_periodicaly, &one[i].isotops);
		}
	fclose(file); 
	printf("                          Таблица элементов\n\n"); 
	printf("%10s%20s%10s%8s%8s%8s%8s\n\n", "Name", "FS of inventor", "DateBrn", "index", "weight", "group", "isotps"); 
	for (int i=0; i<N; i++) {
 		printf("%10s", one[i].Name_of_index);
		printf("%20s", one[i].FS_of_inventor);
		printf("%10d", one[i].Data_of_born);
		printf("%8d", one[i].index_in_periodicaly);
		printf("%8d", one[i].weight);
		printf("%8d", one[i].group_in_periodicaly);
		printf("%8s", one[i].isotops);
		printf("\n");
	} 
	printf("\n                          Тяжелые элементы\n\n"); 
	printf("%10s%20s%10s%8s%8s%8s%8s\n\n", "Name", "FS of inventor", "DateBrn", "index", "weight", "group", "isotps");
	for (int i=0; i<N; i++) {
		if (one[i].weight>100) {
 		printf("%10s", one[i].Name_of_index);
		printf("%20s", one[i].FS_of_inventor);
		printf("%10d", one[i].Data_of_born);
		printf("%8d", one[i].index_in_periodicaly);
		printf("%8d", one[i].weight);
		printf("%8d", one[i].group_in_periodicaly);
		printf("%8s", one[i].isotops);
		printf("\n");
		}
	} 
	printf("\n                          Элементы 19ого века\n\n"); 
	printf("%10s%20s%10s%8s%8s%8s%8s\n\n", "Name", "FS of inventor", "DateBrn", "index", "weight", "group", "isotps");
	for (int i=0; i<N; i++) {
		if ((one[i].Data_of_born>1800) && (one[i].Data_of_born<1901)) {
			printf("%10s", one[i].Name_of_index);
			printf("%20s", one[i].FS_of_inventor);
			printf("%10d", one[i].Data_of_born);
			printf("%8d", one[i].index_in_periodicaly);
			printf("%8d", one[i].weight);
			printf("%8d", one[i].group_in_periodicaly);
			printf("%8s", one[i].isotops);
			printf("\n");
 		} 
	}
	
getch();
return EXIT_SUCCESS;
}

