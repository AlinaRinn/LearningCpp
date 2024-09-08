#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <math.h>

#define N 10 //����������� ������� 1

#define L 10   //���������� ������� 2
#define M 10

#define A -9 //�������� �������
#define B 99

using namespace std;

int Array_pulling_1(int *a) {
	srand(time(NULL));
	cout << endl << "������ (������� 1)" << endl<< endl;
	for(int i=0;i<N;i++) {
		a[i]=rand()%(B - A+1)+A;
		cout << a[i] << " ";
		if ((i%15==0)&&(i!=0)) {
			cout << endl;
		}
	}
}

int Array_pulling_2(int b[][M]) {
	cout << endl<< endl<< endl<< endl<< endl << "��������� ������ (������� 2)" << endl<< endl;
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
   	cout << endl << endl << "������ ���������� �� ������ ������� �� �����: " << tmp << endl;
   }
   
int Array_1_2(int *a) {
	int i, abssum = 0;
    while(a[i] && i < N){
        ++i;
    }
    while(i < N)
        abssum += a[i], ++i;
        abssum = abs(abssum);
    cout<<"����� ������� ��������� ����� ���� (����������): "<<abssum<<endl;
    if (abssum==0)
    	cout<<"����� ��� ��� ��� �������� ����\n"<<endl;
    }
    
int Array_1_3(int *a) {
	cout<<"� ������ �������� �������� � ������ �������, �� ������ - � ��������:\n\n"<<endl;
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
	cout << endl<< endl<< "C���� ��������� � ��� �������, ��� ������������� �������: " << endl<< endl;
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
			cout << endl<< "������ " << st << " ����� "<< Count << endl;
		}
		score=0;
	}
}

int Array_2_2 (int b[][M]){
	int i, j, val, tp=0;
	int min_h[L], max_w[M];
	cout << endl << endl <<"�������� ����� (��� � ������, ���� � �������): " << endl;
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
        	    cout << "������ " << i << " ������� " << j << " �������� " << b[i][j] << endl;
        	    tp++;
        	}
    	}
	}
	if (tp==0) {
		cout << endl << "� ������ ������� �������� ����� ���" << endl<< endl;
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
	
	cout << endl << endl << "������� 3" << endl << endl;
	
	// x^2 -3.2x +1.12 = 0
	
	double x1 = 0, x2 = 0;
	int answer = Function_3(1, -3.2, 1.12, x1, x2);
	if (answer > 0) {
		cout << "������: " << answer << endl;
        cout << "x1 = "<< x1 << ",  x2 = " << x2 << endl;
    }
    else if(answer == 0)
        cout << "��� �������" << endl;
    else
        cout << "������� ������ �� �����" << endl;
        
    return 0;
}

