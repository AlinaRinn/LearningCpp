#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

class shop{
private:
    int *a;
    string name, type;
    int amount;
    double cost;
public:
	shop();
    shop(string name, string type, int amount, double cost);
    shop(const shop& copy);
    void set_name(string name);
    void set_type(string type);
    void set_amount(int amount);
    void set_cost(double cost);
	string get_name();
    string get_type();
    int get_amount();
    double get_cost();
    ~shop();
};

class NSFW_shop : public shop     // "Создать дочерний класс со уникальными полями и функциями"
{								// Создал, о использовании в задании речи не идет \_0-0_/
	private:
		string name, type;
    	int amount;
    	double cost;
    	
		string pass;
		double cost_p;      
	public:
		string get_pass();
		void cyberbulling();
		
};

#endif
