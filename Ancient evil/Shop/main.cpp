#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include "class.h"
#define N 10

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
    shop *a = new shop [N];
    char answer;
	cout << "��� �� ������ ������ ������? � ���������� - ������� k, �� ����� - ������� f" << endl;
	tryAgain:
	cin >> answer;
	if (answer=='k'){
		int num=0; string str; double floatnum=0;
		for(int i=0; i<N; i++){
			cout << "�������� " << i << ": ������� �����" << endl;
			cin >> str;
    		a[i].set_name(str); 
    		cout << "�������� " << i << ": ������� ��� ������" << endl;
    		cin >> str;
    		a[i].set_type(str);
    		cout << "�������� " << i << ": ������� ���-��" << endl;
    		cin >> num;
			a[i].set_amount(num); num=0;
			cout << "�������� " << i << ": ������� ����" << endl;
    		cin >> floatnum;
    		a[i].set_cost(floatnum);
		}
	}
    else if(answer=='f'){
    	ifstream fin("shop.txt");
    	int num=0; string str=""; double floatnum=0;
    	for(int i=0; i<N; i++){
			fin >> str;
    		a[i].set_name(str); str="";
    		fin >> str;
    		a[i].set_type(str); str="";
    		fin >> num;
			a[i].set_amount(num); num=0;
    		fin >> floatnum;
    		a[i].set_cost(floatnum); floatnum=0;
		}
	}
    else {
    	cout << "������� 1 ������, f ��� k" << endl;
    	goto tryAgain;
	}
	double temp=0, average=0; int iterator=0;
	for (int i =0; i<N; i++){
		if (a[i].get_type() == "�������_�������") {
			temp+=a[i].get_cost();
			iterator++;
		}
	}
	average=temp/iterator;
	
	cout << endl << "����� � ������� - �, � ���� - f" << endl;
	tryAgain2:
	cin >> answer;
	if (answer=='c'){   
		printf("\n�����          ���                 ���-��    ����\n\n");  //��, ��� ����� printf �����, �������, �� ������������)
		for(int i=0; i<N; i++){
			printf("%-15s%-20s%-10d%-10.2lf\n", a[i].get_name().c_str(), a[i].get_type().c_str(), a[i].get_amount(), a[i].get_cost());	 
		}
		cout << endl << endl << "������� ���� �������� �������:" << average << endl << endl;
		cout << endl << "��������, ���� ������� ����:" << endl << endl;
		for (int i =0; i<N; i++){
			if (a[i].get_type() == "��������" && a[i].get_cost() > average) {
				printf("\n�����          ���                 ���-��    ����\n\n");
				printf("%-15s%-20s%-10d%-10.2lf\n", a[i].get_name().c_str(), a[i].get_type().c_str(), a[i].get_amount(), a[i].get_cost());	 
			}
		}
		cout << endl << "�������� ��������� ������ b ������� ������ 3 �� ���������� �, ��������� \n����������� �����������:" << endl << endl;
		shop b[N]  = a[2]; 
		cout << "               �����                 ���    ���-��      ����" << endl << endl;
		for(int i=0; i<N; i++){
			cout << setw (20) << b[i].get_name() << setw (20) << b[i].get_type() << setw (10) << b[i].get_amount() << setw (10) << b[i].get_cost() <<  endl;
 		}
	}
	else if (answer=='f'){
		ofstream out("outshop.txt");
		out << "               �����                 ���    ���-��      ����" << endl << endl;
		for(int i=0; i<N; i++){
			out << setw (20) << a[i].get_name() << setw (20) << a[i].get_type() << setw (10) << a[i].get_amount() << setw (10) << a[i].get_cost() <<  endl;
 		}
 		out << endl << endl << "������� ���� �������� �������:" << average << endl << endl;
 		out << endl << "��������, ���� ������� ����:" << endl << endl;
 		for (int i =0; i<N; i++){
			if (a[i].get_type() == "��������" && a[i].get_cost() > average) {
				out << "               �����                 ���    ���-��      ����" << endl << endl;
				out << setw (20) << a[i].get_name() << setw (20) << a[i].get_type() << setw (10) << a[i].get_amount() << setw (10) << a[i].get_cost() <<  endl;	 
			}
		}
		out << endl << "�������� ��������� ������ b ������� ������ 3 �� ���������� �, ��������� ����������� �����������:" << endl << endl;
		shop b[N]  = a[2]; 
		out << "               �����                 ���    ���-��      ����" << endl << endl;
		for(int i=0; i<N; i++){
			out << setw (20) << b[i].get_name() << setw (20) << b[i].get_type() << setw (10) << b[i].get_amount() << setw (10) << b[i].get_cost() <<  endl;
 		}
 		out.close();
 	}
	else {
		cout << "� ������� - �, � ���� - f" << endl;
    	goto tryAgain2;
	}
//    delete[] a;   c ������������ �� �����
	system("pause");
    return 0;
}
