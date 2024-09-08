#include <iostream>
#include "child.h"

Child::Child(){
}

Child::Child(string name, string surname, int years, double height, double weight)
{
    this->name = name;
    this->surname = surname;
    this->years = years;
    this->height = height;
    this->weight = weight;
}
void Child::set_name(string name)
{
    this->name = name;
}
void Child::set_surname(string surname)
{
    this->surname = surname;
}
void Child::set_years(int years)
{
    this->years = years;
}
void Child::set_weight(double weight)
{
    this->weight = weight;
}
void Child::set_height(double height)
{
    this->height = height;
}
string Child::get_name()
{
    return this->name;
}
string Child::get_surname()
{
    return this->surname;
}
int Child::get_years()
{
    return this->years;
}
double Child::get_weight()
{
    return this->weight;
}
double Child::get_height()
{
    return this->height;
}

Child::~Child(){
}
