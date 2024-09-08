#pragma once
#include "stdafx.h"
#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <streambuf>
#include "Shop.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;
vector<Shop> random_shop;
vector<Shop> sorted_shop;

void flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}

int input()
{	
	Shop temp_shop;
	string s, file, line;
	int n;
	ifstream in;
	while ((s != "console") && (s != "file"))
	{
		cout << "Get data from console or file?\t"; getline(cin, s);
	}
	if (s == "file")
	{
		while (in.is_open() == 0)
		{
			cout << "File: \t"; getline(cin, file);
			in.open(file);
		}
		in >> n; cout << n << endl;
		getline(in, line);
		for (int i = 0; i < n; i++)
		{
			getline(in, line); cout << line << endl;
			temp_shop.set_line(line);
			random_shop.push_back(temp_shop);
			//cout << random_shop[i].get_name() << "\t" << random_shop[i].get_category() << "\t" << random_shop[i].get_quantity() << "\t" << random_shop[i].get_price() << endl;
		}
		return n;
		
	}
	else if (s == "console")
	{
		cout << "How many rows? \t"; cin >> n;
		for (int i = 0; i < n; i++)
		{
			flush_stdin();
			system("cls");
			cout << i << " line:" << endl;
			temp_shop.menu();
			random_shop.push_back(temp_shop);
		}
		return n;
	}
	else
	{
		cout << "Something went wrong!!!\n";
		return 0;
	}
}

void print_to_file(vector<Shop> shop)
{
	char yesno(0);
	while ((yesno != 'y') && (yesno != 'n'))
	{
		cout << "Wanna print data to file?\t (y/n)\t";
		cin >> yesno;
	}
	if (yesno == 'n') return;
	int n = shop.size();
	string file;
	ofstream out;
	while (out.is_open() == 0)
	{
		cout << "Print to file: \t"; getline(cin, file);
		out.open(file, ios::trunc);
	}
	out << "NAME;CATEGORY;QUANTITY;PRICE" << endl;
	for (int i = 0; i < n; i++)
	{
		out << shop[i].get_name() << ";" << shop[i].get_category() << ";";
		out << shop[i].get_quantity() << ";" << shop[i].get_price() << endl;
	}
}

void print_to_console(vector<Shop> shop)
{
	int n = shop.size();
	int MAX_NAME = 4, MAX_CAT = 8;
	for (int i = 0; i < n; i++)
	{
		if (shop[i].get_name().length() > MAX_NAME) MAX_NAME = shop[i].get_name().length();
		if (shop[i].get_category().length() > MAX_CAT) MAX_CAT = shop[i].get_category().length();
	}
	cout << setw(MAX_NAME+1) << left << "NAME" << "|" << setw(MAX_CAT+1) << "CATEGORY" << "|" << setw(10) << right << "QUANTITY" << "|" << setw(10) << "PRICE" << "|" << endl;
	for (int i = 0; i < MAX_NAME + MAX_CAT + 22 + 3; i++) cout << "-";
	cout <<"|"<< endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(MAX_NAME + 1) << left << shop[i].get_name() << "|" << setw(MAX_CAT + 1) << left << shop[i].get_category() << "|";
		cout << setw(10) << right << shop[i].get_quantity() << "|" << setw(10) << shop[i].get_price() << "|" << endl;
	}
}

double mean_price_by_category(vector<Shop> shop, string category)
{
	int n = shop.size(), counter = 0; double sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (shop[i].get_category() == category)
			{
				sum += shop[i].get_price();
				counter++;
			}
		}
		return sum / (double)counter;
}

void sort_by_price(vector<Shop> UNSORTED_SHOP, vector<Shop> SORTED_SHOP, string TARGET_CATEGORY, string FLAG, string COMPARISON_CATEGORY)
{	//не стоит вчитываться в эту порнографию
	Shop TEMP_SHOP;
	double MEAN = mean_price_by_category(UNSORTED_SHOP, COMPARISON_CATEGORY);
	int SHOP_SIZE = UNSORTED_SHOP.size();
	int NEW_SHOP_SIZE = 0;
	if (FLAG == ">")
	{
		for (int i = 0; i < SHOP_SIZE; i++)
		{
			if ((UNSORTED_SHOP[i].get_category() == TARGET_CATEGORY) && (UNSORTED_SHOP[i].get_price() > MEAN))
			{
				SORTED_SHOP.push_back(UNSORTED_SHOP[i]);
				NEW_SHOP_SIZE++;
			}

		}
	}
	else if (FLAG == "<")
	{
		for (int i = 0; i < SHOP_SIZE; i++)
		{
			if ((UNSORTED_SHOP[i].get_category() == TARGET_CATEGORY) && (UNSORTED_SHOP[i].get_price() < MEAN))
			{
				SORTED_SHOP.push_back(UNSORTED_SHOP[i]);
				NEW_SHOP_SIZE++;
			}

		}
	}
	else if (FLAG == ">=")
	{
		for (int i = 0; i < SHOP_SIZE; i++)
		{
			if ((UNSORTED_SHOP[i].get_category() == TARGET_CATEGORY) && (UNSORTED_SHOP[i].get_price() >= MEAN))
			{
				SORTED_SHOP.push_back(UNSORTED_SHOP[i]);
				NEW_SHOP_SIZE++;
			}

		}
	}
	else if (FLAG == "<=")
	{
		for (int i = 0; i < SHOP_SIZE; i++)
		{
			if ((UNSORTED_SHOP[i].get_category() == TARGET_CATEGORY) && (UNSORTED_SHOP[i].get_price() <= MEAN))
			{
				SORTED_SHOP.push_back(UNSORTED_SHOP[i]);
				NEW_SHOP_SIZE++;
			}

		}
	}
	else if (FLAG == "=")
	{
		for (int i = 0; i < SHOP_SIZE; i++)
		{
			if ((UNSORTED_SHOP[i].get_category() == TARGET_CATEGORY) && (UNSORTED_SHOP[i].get_price() == MEAN))
			{
				SORTED_SHOP.push_back(UNSORTED_SHOP[i]);
				NEW_SHOP_SIZE++;
			}

		}
	}
	else
	{
		cout << "WTF?!" << endl;
	}
	for (int i = 0; i < NEW_SHOP_SIZE - 1; i++)
	{
		for (int j = 0; j < NEW_SHOP_SIZE - i - 1; j++)
		{
			if (SORTED_SHOP[j].get_price() > SORTED_SHOP[j + 1].get_price())
			{
				TEMP_SHOP = SORTED_SHOP[j];
				SORTED_SHOP[j] = SORTED_SHOP[j+1];
				SORTED_SHOP[j+1] = TEMP_SHOP;
			}
		}
	}
	cout << "The shop is sorted by " << TARGET_CATEGORY << " with a price " << FLAG << " than the average price = " << MEAN <<" in the " << COMPARISON_CATEGORY << endl;
	print_to_console(SORTED_SHOP);
}

void main()
{
	string TARGET_CATEGORY = "Furniture";
	string COMPARISON_CATEGORY = "Electronics";
	string FLAG = ">";
	int SIZE;
	if ((SIZE = input()) == 0)
	{
		cout << "Got some troubles...";
		exit(0);
	}
	
	system("pause");
	system("cls");
	print_to_console(random_shop);
	cout << endl;
	print_to_file(random_shop);
	system("cls");
	cout << "Display in the form of a sorted table, all products from the category ""XXX"" whose price is (>,<,>=,<=,=) than the average price of goods from the category ""YYY""." << endl;
	cout << "By default" << endl;
	cout << "XXX:\t\t" << TARGET_CATEGORY << "\n(>,<,>=,<=,=):\t" << FLAG << "\nYYY:\t\t" << COMPARISON_CATEGORY << endl;
	char yesno(0);
	while ((yesno != 'y') && (yesno != 'n'))
	{
		cout << "\nWanna change it (y/n)?\t";
		cin >> yesno;
	}
	if (yesno == 'y')
	{
		flush_stdin();
		cout << "XXX:\t\t"; getline(cin, TARGET_CATEGORY);
		cout << "(>,<,>=,<=,=):\t"; getline(cin, FLAG);
		cout << "YYY:\t\t ";  getline(cin, COMPARISON_CATEGORY);
	}
	sort_by_price(random_shop, sorted_shop, TARGET_CATEGORY, FLAG, COMPARISON_CATEGORY);
	system("pause");
}

