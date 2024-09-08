#include "stdafx.h"
#include "Shop.h"
#include <iostream>
#include <string>
using namespace std;

Shop::Shop()
{
	set_name("default_name");
	set_category("default_cat");
	set_quantity(0);
	set_price(0.0);
}

Shop::Shop(string name = "default_name", string category = "default_cat", int quantity = 0, double price = 0.0)
{
	set_name(name);
	set_category(category);
	set_quantity(quantity);
	set_price(price);
}

Shop::Shop(const Shop &shop)
{
	set_name(shop.name);
	set_category(shop.category);
	set_quantity(shop.quantity);
	set_price(shop.price);
}

void Shop::set_name(string name) { this->name = name; }
void Shop::set_category(string category) { this->category = category; }
void Shop::set_quantity(int quantity) { this->quantity = quantity; }
void Shop::set_price(double price) { this->price = price; }
string Shop::get_name() { return this->name; }
string Shop::get_category() { return this->category; }
int Shop::get_quantity() { return this->quantity; }
double Shop::get_price() { return this->price; }

void Shop::set_line(string line)
{
	int pos1 = 0, pos2 = 0; string temp;
	pos2 = line.find(";");
	this->name.assign(line, pos1, pos2 - pos1);
	pos1 = pos2; pos2 = line.find(";", pos1 + 1);
	this->category.assign(line, pos1 + 1, pos2 - pos1 - 1);
	pos1 = pos2; pos2 = line.find(";", pos1 + 1);
	this->quantity = atoi(temp.assign(line, pos1 + 1, pos2 - pos1 - 1).c_str());
	temp.erase();
	pos1 = pos2; pos2 = line.length();
	this->price = atof(temp.assign(line, pos1 + 1, pos2 - 1  -pos1).c_str());
}

string Shop::get_line()
{
	string output = get_name();
	output += "\t"; output += get_category();
	output += "\t"; output += get_quantity();
	output += "\t"; output += get_price();
	output += "\n";
	return output;
}

void Shop::menu()
{
	string n, c; int i; double d;
	cout << "Name = "; getline(cin, n); set_name(n);
	cout << get_name() << " category = "; getline(cin, c); set_category(c);
	cout << get_name() << " quantity = "; cin >> i; set_quantity(i);
	cout << get_name() << " price ="; cin >> d; set_price(d);
}

Shop::~Shop()
{
}
