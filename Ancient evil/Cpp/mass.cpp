#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <math.h>

#define N 10 //Размерность массива 1

#define L 10   //Рамерность массива 2
#define M 10

#define A -9 //Диапазон рандома
#define B 99

using namespace std;

int Array_pulling_1(int *a) {
	srand(time(NULL));
	cout << endl << "Массив (задание 1)" << endl<< endl;
	for(int i=0;i<N;i++) {
		a[i]=rand()%(B - A+1)+A;
		cout << a[i] << " ";
		if ((i%15==0)&&(i!=0)) {
			cout << endl;
		}
	}
}

int Array_pulling_2(int b[][M]) {
	cout << endl<< endl<< endl<< endl<< endl << "Двумерный массив (задание 2)" << endl<< endl;
	srand(time(NULL));
	for(int i=0;i<L;i++) {
		for(int j=0;j<M;j++) {
			b[i][j]=rand()%(B - A+1)+A;
			cout << " " << b[i][j];
		}
		cout << endl;
	}
}
	

int Array_1_1(int *a){
	int tmp =0; 
    for(int i = 0; i < N; i++) {
        if(abs(a[i]) < abs(a[tmp])){
            tmp = i;
        }
    }
    
    tmp+=1;
   	cout << endl << endl << "Первый минималный по модулю элемент по счету: " << tmp << endl;
   }
   
int Array_1_2(int *a) {
	int i, abssum = 0;
    while(a[i] && i < N){
        ++i;
    }
    while(i < N)
        abssum += a[i], ++i;
        abssum = abs(abssum);
    cout<<"Сумма модулей элементов после нуля (последнего): "<<abssum<<endl;
    if (abssum==0)
    	cout<<"Нулей нет или все элементы нули\n"<<endl;
    }
    
int Array_1_3(int *a) {
	cout<<"В первой половине элементы с четных позиций, во второй - с нечетных:\n\n"<<endl;
    int j = 0;
    int* t = new int[(N>>2) + 1];
    int* tr = new int[(N>>2) + 1];
    for(int i = 0; i < N - 1; i += 2, ++j){
        t[j] = a[i];
        tr[j] = a[i + 1];
    }
    for(int i = 0; i < j; ++i) {
        a[i] = t[i];
	}
    int k = 0;
    for(int i = j; i < j << 1; ++i, ++k){
        a[i] = tr[k];
    }
    for(int i = 0; i < N; ++i){
        cout<<a[i]<<" ";
        if ((i%15==0)&&(i!=0)) {
			cout << endl;
		}
    }
    delete [] t;
    delete [] tr;
	}
	
int Array_2_1 (int b[][M]){
	int Count, score=0, st=0;
	cout << endl<< endl<< "Cумма элементов в тех строках, где отрицательный элемент: " << endl<< endl;
	for(int i=0;i<L;i++) {
		for(int j=0;j<M;j++) {
			if (b[i][j] < 0){
				score=1;
			}
		}
		if (score==1) {
			for(int j=0;j<M;j++) {
				Count+= b[i][j];
			}
			st=i+1;
			cout << endl<< "Строка " << st << " Сумма "<< Count << endl;
		}
		score=0;
	}
}

int Array_2_2 (int b[][M]){
	int i, j, val, tp=0;
	int min_h[L], max_w[M];
	cout << endl << endl <<"Седловые точки (Мин в строке, макс в столбце): " << endl;
 	for ( i= 0; i<L; i++ ) {
    	val= b[i][0];
    	for ( j= 1; j<M; j++ ) {
        	if ( b[i][j]<val ) { val= b[i][j]; }
    	}
    min_h[i]= val;
	}
 	for ( j= 0; j<M; j++ ) {
    val= b[0][j];
    	for ( i= 1; i<L; i++ ) {
        	if ( b[i][j]>val ) { val= b[i][j]; }
    	}
    max_w[j]= val;
	}
 	for ( i= 0; i<L; i++ ) {
    	for ( j= 0; j<M; j++ ) {
        	if ( b[i][j] == max_w[j] && b[i][j] == min_h[i] ) {
        	    cout << "Строка " << i << " Элемент " << j << " Значение " << b[i][j] << endl;
        	    tp++;
        	}
    	}
	}
	if (tp==0) {
		cout << endl << "В данной матрице седловых точек нет" << endl<< endl;
	}
}

int Function_3(double a, double b, double c, double & x1, double & x2)
{
    if (abs(a) < numeric_limits<double>::epsilon())
        return -1;
 
    double D = (b * b) - (4 * a * c);
 
    if ( D < 0.0)
        return 0;
 
    if (abs(D) < numeric_limits<double>::epsilon())
    {
        x1 = x2 =  -b / ( 2 * a);
        return 1;
    }
 
    x1  = (-b + sqrt(D)) /  2 * a;
    x2 = (-b - sqrt(D)) / 2 * a;
    return 2;
}
	
int main(void) {
	setlocale(LC_ALL, "Russian");
	int a[N], b[L][M];
	
	Array_pulling_1(a);
	Array_1_1(a);
	Array_1_2(a);
	Array_1_3(a);
	
	Array_pulling_2(b);
	Array_2_1(b);
	Array_2_2(b);
	
	cout << endl << endl << "Задание 3" << endl << endl;
	
	// x^2 -3.2x +1.12 = 0
	
	double x1 = 0, x2 = 0;
	int answer = Function_3(1, -3.2, 1.12, x1, x2);
	if (answer > 0) {
		cout << "Корней: " << answer << endl;
        cout << "x1 = "<< x1 << ",  x2 = " << x2 << endl;
    }
    else if(answer == 0)
        cout << "Нет решений" << endl;
    else
        cout << "Входные данные не верны" << endl;
        
    return 0;
}

