#ifndef CHILD_H
#define CHILD_H
#include <iostream>
using namespace std;

class Child{
private:
    int *a;
    string name, surname;
    int years;
    double weight, height;
public:
	Child();
    Child(string name, string surname, int years, double weight, double height);
    void set_name(string name);
    void set_surname(string surname);
    void set_years(int years);
    void set_weight(double weight);
    void set_height(double height);
	string get_name();
    string get_surname();
    int get_years();
    double get_weight();
    double get_height();
    ~Child();
};
#endif
