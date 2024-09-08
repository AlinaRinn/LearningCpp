#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6
#define M N+1
#define n 9

void method_mnk();
void method_Gauss(double [N][M],double [N]);
void read_data(double [2][n]);
	
void method_mnk(){
	double xy[2][n],mincheck,ytmp;
	read_data(xy);
	double arr[N][M] = {{0}};
	double x[N]={0};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			for(int k=0;k<n;k++)
				arr[i][j]+=pow(xy[0][k],i+j);
		for(int k=0;k<n;k++)
			arr[i][N]+=xy[1][k]*pow(xy[0][k],i);
	}
	method_Gauss(arr,x);
	mincheck=0;
	FILE*file;
	file=fopen("output.txt","a");
	fprintf(file, "Dots: \n\n");
	for (int i=0; i<n;i++){
		ytmp=0;
		fprintf(file, "x = %5.2lf\t",xy[0][i]);
		for(int j=0; j<N;j++)
			ytmp+=pow(xy[0][i],j)*x[j];
		fprintf(file, "y = %7.2lf\n",ytmp);
			mincheck+=pow((xy[1][i]-ytmp),2);
	}
	fprintf(file, "\nR = %.10lf \n",mincheck);
	fclose(file);
}

void method_Gauss(double a[N][M],double x[N]){
	double tmp;
	int ind,count,check;
	check=1;
	while (check > 0) {
		check=0;
		for(int i=0;i<N;i++){
			ind = i;
			count=0;
			while ((a[ind][i]==0)&&(count<N)){
				ind=(ind+1)%N;
				count++;
			}
			if (ind != i){
				check++;
				for(int j=0;j<M;j++){
					tmp=a[i][j];
					a[i][j]=a[ind][j];
					a[ind][j]=tmp;
				}
			}
		}
	}
	double numb,numb1;
	for(int i=0;i<N;i++){
		numb=a[i][i];
		for(int j=0;j<M;j++)
			a[i][j]/=numb;
		for(int k=i+1;k<N;k++){
			numb1=a[k][i];
			for(int j=0;j<M;j++){
				a[k][j] += (numb1*(-1)*a[i][j]);
				a[k][j] = (a[k][j]==0)?0:a[k][j];
			}
		}
	}
	for(int i=N-1;i>=0;i--){
		x[i]=a[i][M-1];
		for(int j=M-2;j>i;j--){
			x[i]-=(x[j]*a[i][j]);
		}
		x[i]/=a[i][i];
	}
	FILE*file;
	file=fopen("output.txt","a");
	fprintf(file, "Coefficients:\n\n");
	for(int i=0;i<N;i++){
		fprintf(file, "a[%d]=  %20.17lf\n",i,x[i]);
	}
	fprintf(file, "\n");
	fclose(file);
}

void read_data(double a[2][n]){
	FILE *file;
	file=fopen("input.txt","r");
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			fscanf(file,"%lf",&a[i][j]);
		}
	}
	fclose(file);
}

int main(void) {
	FILE *file;
	file=fopen("output.txt","w");
	fclose(file);
	method_mnk();
	printf("Записано");
	return EXIT_SUCCESS; 
}
