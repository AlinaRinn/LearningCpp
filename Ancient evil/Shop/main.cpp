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
	cout << "Как вы хотите ввести данные? С клавиатуры - введите k, из файла - введите f" << endl;
	tryAgain:
	cin >> answer;
	if (answer=='k'){
		int num=0; string str; double floatnum=0;
		for(int i=0; i<N; i++){
			cout << "Итерация " << i << ": Введите Товар" << endl;
			cin >> str;
    		a[i].set_name(str); 
    		cout << "Итерация " << i << ": Введите Тип товара" << endl;
    		cin >> str;
    		a[i].set_type(str);
    		cout << "Итерация " << i << ": Введите кол-во" << endl;
    		cin >> num;
			a[i].set_amount(num); num=0;
			cout << "Итерация " << i << ": Введите цену" << endl;
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
    	cout << "Введите 1 символ, f или k" << endl;
    	goto tryAgain;
	}
	double temp=0, average=0; int iterator=0;
	for (int i =0; i<N; i++){
		if (a[i].get_type() == "Детское_питание") {
			temp+=a[i].get_cost();
			iterator++;
		}
	}
	average=temp/iterator;
	
	cout << endl << "Вывод в консоль - с, в файл - f" << endl;
	tryAgain2:
	cin >> answer;
	if (answer=='c'){   
		printf("\nТовар          Тип                 Кол-во    Цена\n\n");  //да, тут через printf вывел, надеюсь, не возбраняется)
		for(int i=0; i<N; i++){
			printf("%-15s%-20s%-10d%-10.2lf\n", a[i].get_name().c_str(), a[i].get_type().c_str(), a[i].get_amount(), a[i].get_cost());	 
		}
		cout << endl << endl << "Средняя цена детского питания:" << average << endl << endl;
		cout << endl << "Продукты, цена которых выше:" << endl << endl;
		for (int i =0; i<N; i++){
			if (a[i].get_type() == "Продукты" && a[i].get_cost() > average) {
				printf("\nТовар          Тип                 Кол-во    Цена\n\n");
				printf("%-15s%-20s%-10d%-10.2lf\n", a[i].get_name().c_str(), a[i].get_type().c_str(), a[i].get_amount(), a[i].get_cost());	 
			}
		}
		cout << endl << "Заполним экземпляр класса b копиями строки 3 из экземпляра а, используя \nконструктор копирования:" << endl << endl;
		shop b[N]  = a[2]; 
		cout << "               Товар                 Тип    Кол-во      Цена" << endl << endl;
		for(int i=0; i<N; i++){
			cout << setw (20) << b[i].get_name() << setw (20) << b[i].get_type() << setw (10) << b[i].get_amount() << setw (10) << b[i].get_cost() <<  endl;
 		}
	}
	else if (answer=='f'){
		ofstream out("outshop.txt");
		out << "               Товар                 Тип    Кол-во      Цена" << endl << endl;
		for(int i=0; i<N; i++){
			out << setw (20) << a[i].get_name() << setw (20) << a[i].get_type() << setw (10) << a[i].get_amount() << setw (10) << a[i].get_cost() <<  endl;
 		}
 		out << endl << endl << "Средняя цена детского питания:" << average << endl << endl;
 		out << endl << "Продукты, цена которых выше:" << endl << endl;
 		for (int i =0; i<N; i++){
			if (a[i].get_type() == "Продукты" && a[i].get_cost() > average) {
				out << "               Товар                 Тип    Кол-во      Цена" << endl << endl;
				out << setw (20) << a[i].get_name() << setw (20) << a[i].get_type() << setw (10) << a[i].get_amount() << setw (10) << a[i].get_cost() <<  endl;	 
			}
		}
		out << endl << "Заполним экземпляр класса b копиями строки 3 из экземпляра а, используя конструктор копирования:" << endl << endl;
		shop b[N]  = a[2]; 
		out << "               Товар                 Тип    Кол-во      Цена" << endl << endl;
		for(int i=0; i<N; i++){
			out << setw (20) << b[i].get_name() << setw (20) << b[i].get_type() << setw (10) << b[i].get_amount() << setw (10) << b[i].get_cost() <<  endl;
 		}
 		out.close();
 	}
	else {
		cout << "В консоль - с, В файл - f" << endl;
    	goto tryAgain2;
	}
//    delete[] a;   c деструктором не нужен
	system("pause");
    return 0;
}
