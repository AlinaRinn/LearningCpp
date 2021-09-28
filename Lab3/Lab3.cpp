#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Employee
{
    string FIO;
    string gender;
    int yearBorn = 0;
};

void print(Employee* Emp, int N) {
    for (int j = 0; j < N; j++) {
        cout << left << setw(4) << j+1 << left << setw(20) << Emp[j].FIO << left << setw(8) << Emp[j].gender << left << setw(5) << Emp[j].yearBorn << endl;
    }
    cout << endl;
}

void print(int* E, int N) {
    for (int j = 0; j < N; j++) {
        cout << left << setw(5) << E[j];
    }
    cout << endl << endl;
}

double average(Employee* Emp, int N) {
	double avrg = 0;
	for (int j = 0; j < N; j++) {
		avrg += 2021.00 - Emp[j].yearBorn;
	}
	avrg = avrg / N;
	return avrg;
}

double average(int* E, int N) {
	double avrg = 0;
	for (int j = 0; j < N; j++) {
		avrg += E[j];
	}
	avrg = avrg / N;
	return avrg;
}

int main()
{
    int amountOfEmployees = 8;
    Employee * Employees = new Employee[amountOfEmployees];
    int * defaultArray = new int[10];
    string Names[20] = {"Olivia", "Emma", "Ava", "Charlotte", "Sophia", "Amelia", "Isabella", "Mia", "Evelyn", "Harper", "Camila", "Gianna", "Abigail", "Luna", "Ella", "Elizabeth", "Sofia", "Emily", "Avery", "Mila"};
    srand((unsigned int)time(0));
    //filling
    for (int j = 0; j < 10; j++) {
        defaultArray[j] = j + 1;
    }
    for (int j = 0; j < amountOfEmployees; j++) {
        int rndgender = rand() % 2;
        int rndname = rand() % 20;
        Employees[j].yearBorn = 1910 + rand() % 99;
        Employees[j].FIO = Names[rndname];
        if (rndgender == 0) {
            Employees[j].gender = "male";
        }
        else {
            Employees[j].gender = "female";
        }
    }


    //Employees[0].FIO = "Loh pashiloy"; Employees[0].gender = "male"; Employees[0].yearBorn = 1999;
    //Employees[1].FIO = "Alina Pimenova"; Employees[1].gender = "female"; Employees[1].yearBorn = 2004;
    //Employees[2].FIO = "Alisa Eotova"; Employees[2].gender = "female"; Employees[2].yearBorn = 1984;
    //Employees[3].FIO = "Ivan Govnov"; Employees[3].gender = "male"; Employees[3].yearBorn = 1928;
    //Employees[4].FIO = "Vasiliy Nikolaev"; Employees[4].gender = "male"; Employees[4].yearBorn = 1977;
    //Employees[5].FIO = "Mariya Kavo"; Employees[5].gender = "female"; Employees[5].yearBorn = 2010;
    //Employees[6].FIO = "Zhmih Molodoy"; Employees[6].gender = "male"; Employees[6].yearBorn = 1988;

    //print
    cout << "Employees list: " << endl << endl;
    print(Employees, amountOfEmployees);
    cout << "Average age: " << average(Employees, amountOfEmployees) << endl << endl;

    cout << "Array: " << endl << endl;
    print(defaultArray, 10);
    cout << "Average(in array): " << average(defaultArray, 10) << endl << endl;

    //clear
    delete[] Employees;
    delete[] defaultArray;
    system("pause");
}
