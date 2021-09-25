#include <iostream>
#include <iomanip>
using namespace std;

struct Employee
{
    string FIO;
    string gender;
    string yearBorn;
};

void print(Employee* Employees, int N) {
    cout << endl << endl;
    for (int j = 0; j < N; j++) {
        cout << Employees[j].FIO << endl;
    }
    cout << endl << endl;
}

int main()
{
    int AMOUNTOFEMPLOYEE = 7;
    Employee * Employees = new Employee[AMOUNTOFEMPLOYEE];

    Employees[0].FIO = "Loh pashiloy"; Employees[0].gender = "male"; Employees[0].yearBorn = "1999";
    Employees[1].FIO = "Alina Pimenova"; Employees[1].gender = "female"; Employees[1].yearBorn = "2004";
    Employees[2].FIO = "Alisa Eotova"; Employees[2].gender = "female"; Employees[2].yearBorn = "1984";
    Employees[3].FIO = "Ivan Govnov"; Employees[3].gender = "male"; Employees[3].yearBorn = "1928";
    Employees[4].FIO = "Vasiliy Nikolaev"; Employees[4].gender = "male"; Employees[4].yearBorn = "1977";
    Employees[5].FIO = "Mariya Kavo"; Employees[5].gender = "female"; Employees[5].yearBorn = "2010";
    Employees[6].FIO = "Zhmih Molodoy"; Employees[6].gender = "male"; Employees[6].yearBorn = "1988";
    print(Employees, AMOUNTOFEMPLOYEE);
    cout << "Hello World!\n";
    delete[] Employees;
    system("pause");
}
