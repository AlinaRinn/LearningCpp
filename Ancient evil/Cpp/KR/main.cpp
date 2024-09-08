//6 варик
#include <iostream>
#include <fstream>
#include <string.h>
#include "child.h"
#define N 10
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
    Child *a = new Child [N];
    char answer;
	cout << "Как вводим данные? Ручками - введите k, из файлика - введите f" << endl;
	tryAgain:
	cin >> answer;
	if (answer=='k'){
		int num=0; string str; double floatnum=0;
		for(int i=0; i<N; i++){
			cout << "Ребенок " << i << ": Введите имя" << endl;
			cin >> str; 
    		a[i].set_name(str); 
    		cout << "Ребенок " << i << ": Введите фамилию" << endl;
    		cin >> str;
    		a[i].set_surname(str);
    		cout << "Ребенок " << i << ": Введите возраст" << endl;
    		cin >> num;
			a[i].set_years(num); num=0;
			cout << "Ребенок " << i << ": Введите вес" << endl;
    		cin >> floatnum; 
    		a[i].set_weight(floatnum); floatnum=0;
    		cout << "Ребенок " << i << ": Введите рост" << endl;
    		cin >> floatnum;
    		a[i].set_height(floatnum); floatnum=0;
		}
	}
    else if(answer=='f'){
    	ifstream fin("child.txt");
    	if (!fin) {
			cout << "А Файлика то нет.\n";
			system("pause");
			return 1;
		}
    	int num=0; string str=""; double floatnum=0;
    	for(int i=0; i<N; i++){
			fin >> str;
    		a[i].set_name(str); str="";
    		fin >> str;
    		a[i].set_surname(str); str="";
    		fin >> num;
			a[i].set_years(num); num=0;
    		fin >> floatnum;
    		a[i].set_weight(floatnum); floatnum=0;
    		fin >> floatnum;
    		a[i].set_height(floatnum); floatnum=0;
		}
		fin.close();
    	
	}
    else {
    	cout << "Ввод с клавиатуры - k, из файла - f, попробуй еще раз" << endl;
    	goto tryAgain;
	}
	
	int temp=0, element=0, equality=0;
	temp=a[0].get_height();
	for(int i=0; i<N ; i++) {
		if (a[i].get_height() > temp){
			temp=a[i].get_height();
			element=i;
		}
	}
//	cout << "Самый высокий: " << a[element].get_name()<< " " << a[element].get_surname()<< " " << a[element].get_years()<< " " << a[element].get_weight()<< " " << a[element].get_height()<< " " << endl << endl;
	for(int i=0; i<N ; i++) {
		if (temp == a[i].get_height() && element != i){
			equality=i;
		}
	}
//	if (equality !=0) {
//		cout << "Самый высокий №2: " << a[element].get_name()<< " " << a[element].get_surname()<< " " << a[element].get_years()<< " " << a[element].get_weight()<< " " << a[element].get_height()<< " " << endl << endl;
//	}

	cout << "Как выведем данные? В консоль - с, в файл - f" << endl;
	tryAgain2:
	cin >> answer;
	if (answer=='c'){   // надеюсь, форматированный вывод не возбраняется?) С++ функции кашу какую то делают, что с setw, что с cout и табуляцией. Ну или компилятор дурит.
		printf("\n       Имя        Фамилия   Возраст       Вес      Рост\n\n");
		for(int i=0; i<N; i++){
			printf("%10s%15s%10d%10.1lf%10.1lf\n", a[i].get_name().c_str(), a[i].get_surname().c_str(), a[i].get_years(), a[i].get_weight(), a[i].get_height());	 
		}
		cout << endl << endl << "Самый высокий: " << a[element].get_name()<< " " << a[element].get_surname()<< " " << a[element].get_years()<< " " << a[element].get_weight()<< " " << a[element].get_height()<< " " << endl << endl;
		if (equality !=0) {
			cout << "Самый высокий №2: " << a[element].get_name()<< " " << a[element].get_surname()<< " " << a[element].get_years()<< " " << a[element].get_weight()<< " " << a[element].get_height()<< " " << endl << endl;
		}
	}
	else if (answer=='f'){
		ofstream out("outchild.txt");
		out << "Имя     Фамилия     Возраст     Вес     Рост" << endl;
		for(int i=0; i<N; i++){
			out << a[i].get_name() << "\t" << a[i].get_surname() << "      \t" << a[i].get_years() << "\t" << a[i].get_weight() << "\t" << a[i].get_height() << endl;
 		}
 		out << endl << endl << "Самый высокий: " << a[element].get_name()<< " " << a[element].get_surname()<< " " << a[element].get_years()<< " " << a[element].get_weight()<< " " << a[element].get_height()<< " " << endl << endl;
		if (equality !=0) {
			out << "Самый высокий №2: " << a[element].get_name()<< " " << a[element].get_surname()<< " " << a[element].get_years()<< " " << a[element].get_weight()<< " " << a[element].get_height()<< " " << endl << endl;
		}
 		out.close();
 	}
	else {
		cout << "Вывод в консоль - с, в файл - f, попробуй еще раз" << endl;
    	goto tryAgain2;
	}
    delete[] a;
	system("pause");
	return 0;
}
