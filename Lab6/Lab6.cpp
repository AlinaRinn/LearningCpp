#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

class AutoWeapon {
public:
	unsigned int ammo = 30,
		damage = 1;

	int single_shoot() {
		if (ammo > 0) {
			ammo--;
			cout << "Bang!";
			Sleep(1000);
		}
		else if (ammo <= 0) {
			reload();
			ammo--;
			cout << "Bang!";
			Sleep(1000);
		}
		return damage;
	}

	int multi_shoot() {
		if (ammo >= 5) {
			ammo -= 5;
			cout << "Bang! Bang! Bang! Bang! Bang!";
			Sleep(1000);
		}
		else if (ammo < 5) {
			reload();
			ammo -= 5;
			cout << "Bang! Bang! Bang! Bang! Bang!";
			Sleep(1000);
		}
		return damage * 5;
	}

	void reload() {
		cout << "\nReloading..." << endl;
		ammo = 30;
		Sleep(5000);
	}
};

class Target {                           // Abstract class
public:
	const int radius = 100; // 0-100
	int range = 100; // 0-100
	double pntrtionchance = (radius + range) / 2; // 0-100
	bool movable = false; // 50or100
	char material = 'W'; // M - 95, W - 100, L - 99
	int hp = 5;

	virtual double chance() = 0;

	virtual void penetration(int p) = 0;

	virtual bool availability() = 0;
};

double Target::chance() {             // Default
	double chnce = 0;
	movable == true ? chnce = 50 : chnce = 100;
	if (material == 'M') {
		chnce += 95;
	}
	else if (material == 'W') {
		chnce += 100;
	}
	else if (material == 'L') {
		chnce += 99;
	}
	chnce += (double)radius + (double)range + pntrtionchance;
	return chnce / 500;
}

void Target::penetration(int p) {           // Default
	hp -= p;
}

bool Target::availability() {          // Default
	return hp > 0 ? true : false;
}

class BigTarget : public Target {
public:
	const int radius = 100; // 0-100
	int hp = 5;

	virtual double chance() {
		return Target::chance();
	}

	virtual void penetration(int p) {
		return Target::penetration(p);
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class MediumTarget : public Target {
public:
	int radius = 75;
	int hp = 3;

	virtual double chance() {
		return Target::chance();
	}

	virtual void penetration(int p) {
		return Target::penetration(p);
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class SmallTarget : public Target {
public:
	int radius = 50;
	int hp = 1;

	virtual double chance() {
		return Target::chance();
	}

	virtual void penetration(int p) {
		return Target::penetration(p);
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class RectangleTarget : public Target {
public:
	int radius = 44,
		shape = 88;
	int hp = 1;


	double chance() {
		double chnce = 0;
		movable == true ? chnce = 50 : chnce = 100;
		if (material == 'M') {
			chnce += 95;
		}
		else if (material == 'W') {
			chnce += 100;
		}
		else if (material == 'L') {
			chnce += 99;
		}
		chnce += (double)radius + (double)range + pntrtionchance + shape;
		return chnce / 600;
	}

	virtual void penetration(int p) {
		return Target::penetration(p);
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class ShootingField {
public:
	int time = 60, targets = 60;

	void start() {
		vector<Target*> tar;                         // Array of links on abstract class, initialization below 
		for (int i = 0; i < targets; i++) {
			int tmp = rand() % 4,
				range = rand() % 101,
				movable = rand() % 2,
				material = rand() % 3;
			if (tmp == 0) {
				tar.push_back(new BigTarget());
			}
			else if (tmp == 1) {
				tar.push_back(new MediumTarget());
			}
			else if (tmp == 2) {
				tar.push_back(new SmallTarget());
			}
			else if (tmp == 3) {
				tar.push_back(new RectangleTarget());
			}

			tar[i]->range = range;
			movable == 0 ? tar[i]->movable = true : tar[i]->movable = false;
			if (material == 0) {
				tar[i]->material = 'M';
			}
			else if (material == 1) {
				tar[i]->material = 'W';
			}
			else if (material == 2) {
				tar[i]->material = 'L';
			}
		}

		AutoWeapon weapon;
		cout << "Total targets now: " << tar.size() << endl << endl;

		for (int i = 0; i < tar.size(); i++) {
			cout << "Target " << left << setw(3) << i << "|"
				<< " Radius: " << setw(3) << tar[i]->radius
				<< " Range: " << setw(3) << 100-tar[i]->range
				<< " HP: " << setw(2) << tar[i]->hp
				<< " Material: " << setw(2) << tar[i]->material
				<< " Movable: " << setw(2) << tar[i]->movable
				<< " Hit chance: " << setw(10) << tar[i]->chance() << endl;
		}

		cout << "\nShooting starts!\n";

		int statTD = 0; double averageDamage = 0;
		for (int i = 0; i < tar.size(); i++) {
			if (time > 0) {
				int selector = rand() % 2;
				cout << "\nCurrent Target: " << i << ", Time: "<< time << endl;
				while (tar[i]->availability() == true) {
					double shoot = (double)(rand()) / RAND_MAX;
					if (shoot <= tar[i]->chance() && selector == 0) {
						tar[i]->penetration(weapon.single_shoot());
						cout << "   Hit! " << endl;
						averageDamage++;
					}
					else if (shoot > tar[i]->chance() && selector == 0) {
						weapon.single_shoot();
						cout << "   Miss! " << endl;
					}
					else if (shoot <= tar[i]->chance() && selector == 1) {
						tar[i]->penetration(weapon.multi_shoot());
						cout << "   Hit! " << endl;
						averageDamage += 5;
					}
					else if (shoot > tar[i]->chance() && selector == 1) {
						weapon.multi_shoot();
						cout << "   Miss! " << endl;
					}
					time--;
				}
			}
			else {
				statTD = i;
				break;
			}
		}

		for (int i = 0; i < tar.size(); i++) {
			if (tar[i]->hp < 0) {
				averageDamage += tar[i]->hp;
			}
		}
		cout << "\nTime is over!\n\nStats:\n---------------" << endl;
		cout << "Targets destroyed: " << statTD << "\nTargets lost: " << targets - statTD << "\nAverage Damage: "<< averageDamage/statTD << endl;
	}

};

int main()
{
	cout << "              Welcome to the Shooting Field!\n"
		<< "                 ___________________\n"
		<< "                |-- _____________ --|\n"
		<< "                |--|  _________  |--|\n"
		<< "                |--| |  _____  | |--|\n"
		<< "                |--| | |+++++| | |--|\n"
		<< "                |--| | |+++++| | |--|\n"
		<< "                |--| |_________| |--|\n"
		<< "                |--|_____________|--|\n"
		<< "                |___________________|\n\n\n";

	srand((unsigned int)time(0));

	SmallTarget t;
	cout << t.radius;

	ShootingField S;
	S.start();
}
