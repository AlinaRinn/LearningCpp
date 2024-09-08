#ifndef SHOP_H
#define SHOP_H
#pragma once
#include <iostream>
using namespace std;
class Shop
{
private:
	string name, category;
	int quantity;
	double price;
public:
	Shop();
	Shop(string name, string category, int quantity, double price);
	Shop(const Shop &shop);
	void set_name(string name);
	void set_category(string category);
	void set_quantity(int quantity);
	void set_price(double price);
	void set_line(string line);
	string get_line();
	string get_name();
	string get_category();
	double get_price();
	int get_quantity();
	void menu();
	~Shop();
};

#endif // SHOP_H
