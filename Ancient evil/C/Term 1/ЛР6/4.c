#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define N 10

typedef struct {
	char Name[100];
	char Local[100];
struct {
	int Years;
 	int Level;                 
} UpgradeLevel ;
struct {
	int Year;
 	int Counti;                 
} Count ;
} Narod ;

int main(void) {
	Narod a[N];
	Narod b;
	char nac0[]="Russians";
	char nac1[]="Japanise";
	char nac2[]="Jews";
	FILE * file1;
	file1 = fopen("narod.txt","r");
	if (file1 == 0) {
 		printf("error"); 
	}
	for (int i=0; i<N; i++) {
		fscanf(file1, "%s %s %d %d %d %d", a[i].Name, a[i].Local, &a[i].Count.Year, &a[i].Count.Counti, &a[i].UpgradeLevel.Years, &a[i].UpgradeLevel.Level);
		}
	fclose(file1);
	
	printf("                          Народности\n\n"); 
	printf("%15s%15s%10s%10s%10s%10s\n\n", "Name", "Local", "Year", "Count", "Year", "Level"); 
	for (int i=0; i<N; i++) {
 		printf("%15s", a[i].Name);
		printf("%15s", a[i].Local);
		printf("%10d", a[i].Count.Year);
		printf("%10d", a[i].Count.Counti);
		printf("%10d", a[i].UpgradeLevel.Years);
		printf("%10d", a[i].UpgradeLevel.Level);
		printf("\n");
	} 
	printf("\n");
	
	int tmp=0, tmpy=0;
	for (int i=0; i<N; i++) {
		if ((strcmp(a[i].Name,nac0)==0) && (a[i].Count.Counti>tmp)) {
			tmp=a[i].Count.Counti;
			tmpy=i;
		}
	}
	
	printf("                          Год макс численности Русские\n\n"); 
	printf("%15s%15s%10s%10s%10s%10s\n\n", "Name", "Local", "Year", "Count", "Year", "Level");
	printf("%15s", a[tmpy].Name);
	printf("%15s", a[tmpy].Local);
	printf("%10d", a[tmpy].Count.Year);
	printf("%10d", a[tmpy].Count.Counti);
	printf("%10d", a[tmpy].UpgradeLevel.Years);
	printf("%10d", a[tmpy].UpgradeLevel.Level);
	printf("\n\n");
	
	int tmp1=0, tmpy1=0;
	for (int i=0; i<N; i++) {
		if ((strcmp(a[i].Name,nac1)==0) && (a[i].Count.Counti>tmp1)) {
			tmp1=a[i].Count.Counti;
			tmpy1=i;
		}
	}
	
	printf("                          Год макс численности Японцы\n\n"); 
	printf("%15s%15s%10s%10s%10s%10s\n\n", "Name", "Local", "Year", "Count", "Year", "Level");
	printf("%15s", a[tmpy1].Name);
	printf("%15s", a[tmpy1].Local);
	printf("%10d", a[tmpy1].Count.Year);
	printf("%10d", a[tmpy1].Count.Counti);
	printf("%10d", a[tmpy1].UpgradeLevel.Years);
	printf("%10d", a[tmpy1].UpgradeLevel.Level);
	printf("\n\n");
	
	int tmp2=0, tmpy2=0;
	for (int i=0; i<N; i++) {
		if ((strcmp(a[i].Name,nac2)==0) && (a[i].Count.Counti>tmp2)) {
			tmp2=a[i].Count.Counti;
			tmpy2=i;
		}
	}
	
	printf("                          Год макс численности Евреи\n\n"); 
	printf("%15s%15s%10s%10s%10s%10s\n\n", "Name", "Local", "Year", "Count", "Year", "Level");
	printf("%15s", a[tmpy2].Name);
	printf("%15s", a[tmpy2].Local);
	printf("%10d", a[tmpy2].Count.Year);
	printf("%10d", a[tmpy2].Count.Counti);
	printf("%10d", a[tmpy2].UpgradeLevel.Years);
	printf("%10d", a[tmpy2].UpgradeLevel.Level);
	printf("\n\n");
	
	int tmp3=0, tmpy3=0;
	for (int i=0; i<N; i++) {
		if (a[i].UpgradeLevel.Level>tmp3) {
			tmp3=a[i].UpgradeLevel.Level;
			tmpy3=i;
		}
	}
	
	
	printf("                          Максимальный уровень\n\n"); 
	printf("%15s%15s%10s%10s%10s%10s\n\n", "Name", "Local", "Year", "Count", "Year", "Level");
	printf("%15s", a[tmpy3].Name);
	printf("%15s", a[tmpy3].Local);
	printf("%10d", a[tmpy3].Count.Year);
	printf("%10d", a[tmpy3].Count.Counti);
	printf("%10d", a[tmpy3].UpgradeLevel.Years);
	printf("%10d", a[tmpy3].UpgradeLevel.Level);
	printf("\n\n");
	
	
	
	
	
getch();
return EXIT_SUCCESS;
}

