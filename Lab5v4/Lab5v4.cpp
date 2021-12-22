#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

class Hero {
protected:
	int strength = 0;
	double cost = 0;
	string inf = "NotInit";

public:
	int get_strength() {
		return strength;
	}
	double get_cost() {
		return cost;
	}
	string get_type() {
		return inf;
	}
	void set_strength(int p) {
		strength = p;
	}
	void set_cost(double p) {
		cost = p;
	}
	void set_type(string p) {
		inf = p;
	}
	virtual void Ability() = 0;
};

class Warrior : public Hero {
public:
	void Ability() {
		cout << "Features: Good melee attack; High armor class" << endl;
	}

	Warrior(int p1, double p2, string p3) {
		strength = p1;
		cost = p2;
		inf = p3;
	}
};

class Hunter : public Hero {
public:
	void Ability() {
		cout << "Features: Good range attack; High movement speed" << endl;
	}

	Hunter(int p1, double p2, string p3) {
		strength = p1;
		cost = p2;
		inf = p3;
	}
};

class Castle {
private:
	vector<Hero*> her;

public:
	void Gen() {
		int amount = 10;
		for (int i = 0; i < amount; i++) {
			int tmp = rand() % 2;
			if (tmp == 0) {
				her.push_back(new Warrior(3 + rand() % 8, (double)100 + rand() % 301, "Warrior"));
			}
			else if (tmp == 1) {
				her.push_back(new Hunter(1 + rand() % 8, (double)80 + rand() % 221, "Hunter"));
			}
		}
	}

	void Army() {
		Gen();
		int strth = 0;
		double money = 0, reqMoney = 0;
		cout << "Enter Min strength(1-10) and your money(Recommended 2000+): " << endl;
		cin >> strth;
		cin >> money;

		for (int i = 0; i < her.size(); i++) {
			cout << "Hero " << i << ": " << her[i]->get_type() << endl;
			cout << "Stength: " << her[i]->get_strength() << endl;
			cout << "Cost: " << her[i]->get_cost() << endl;
			her[i]->Ability();
			if (her[i]->get_strength() < strth) {
				double tmp = double(strth) - her[i]->get_strength(); // Multiplier
				her[i]->set_strength(strth);
				her[i]->set_cost(her[i]->get_cost() * (1 + (tmp / strth)));
				cout << "----------------\nHero resolved: " << endl;
				cout << "New stength: " << her[i]->get_strength() << endl;
				cout << "New cost: " << her[i]->get_cost() << endl;
			}
			reqMoney += her[i]->get_cost();
			cout << endl;
		}

		cout << "Money: " << money << endl << "Total cost: " << reqMoney << endl;

		if (reqMoney > money) {
			cout << "=> restart" << endl << endl << endl;
			Gen();
			Army();
		}
	}

	~Castle() {
		vector<Hero*>().swap(her);
	};
};

int main()
{
	srand((unsigned int)time(0));
	Castle cast;
	cast.Army();
	system("pause");
}


//один герой подговаривает других героев набить себе цену. Если их собирается менее 3 человек то цена для них уменьшается на 10%, а если более и до 8, то их цена увеличивается на 25%