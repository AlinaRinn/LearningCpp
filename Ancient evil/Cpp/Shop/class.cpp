#include <iostream>
#include "class.h"
#include <algorithm>

shop::shop(){
}

shop::shop(string name, string type, int amount, double cost)
{
    this->name = name;
    this->type = type;
    this->amount = amount;
    this->cost = cost;
}
	
shop::shop(const shop& copy) : a(new int[10]), name(copy.name), type(copy.type), amount(copy.amount), cost(copy.cost){
//	std::copy(copy.a, copy.name + copy.type + copy.amount + copy.cost, a);  
//	cout << "Конструктор копирования" << endl << endl;
}

void shop::set_name(string name)
{
    this->name = name;
}
void shop::set_type(string type)
{
    this->type = type;
}
void shop::set_amount(int amount)
{
    this->amount = amount;
}
void shop::set_cost(double cost)
{
    this->cost = cost;
}
string shop::get_name()
{
    return this->name;
}
string shop::get_type()
{
    return this->type;
}
int shop::get_amount()
{
    return this->amount;
}
double shop::get_cost()
{
    return this->cost;
}
string NSFW_shop::get_pass()
{
	return this->pass;
}
void NSFW_shop::cyberbulling(){
	cout << "НаHa, lox" << endl;
}

shop::~shop()
{
//	cout << "Деструктор" << endl << endl;
    delete[] a;
}
