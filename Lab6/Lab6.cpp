#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

class AutoWeapon {
	unsigned int ammo = 30,
		damage = 1;

public:
	int single_shoot() {
		if (ammo > 0) {
			ammo--;
			cout << "Bang!" << endl;
			Sleep(1000);
			return damage;
		}
		else if (ammo <= 0) {
			return 0;
			reload();
		}
	}

	int multi_shoot() {
		if (ammo >= 5) {
			ammo -= 5;
			cout << "Bang! Bang! Bang! Bang! Bang!" << endl;
			Sleep(1000);
			return damage * 5;
		}
		else if (ammo < 5) {
			return 0;
			reload();
		}
	}

	void reload() {
		cout << "Reloading..." << endl;
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
	unsigned int hp = 5;

	virtual double chance() = 0;

	virtual int penetration() = 0;

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
	chnce += radius + range + pntrtionchance;
	return chnce / 500;
}

int Target::penetration() {           // Default
	return hp -= 1;
}

bool Target::availability() {          // Default
	return hp > 0 ? true : false;
}

class BigTarget : public Target {
public:
	const int radius = 100; // 0-100
	unsigned int hp = 5;

	virtual double chance() {
		return Target::chance();
	}

	virtual int penetration() {
		return Target::penetration();
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class MediumTarget : public Target {
public:
	int radius = 75;
	unsigned int hp = 3;

	virtual double chance() {
		return Target::chance();
	}

	virtual int penetration() {
		return Target::penetration();
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class SmallTarget : public Target {
public:
	int radius = 50;
	unsigned int hp = 1;

	virtual double chance() {
		return Target::chance();
	}

	virtual int penetration() {
		return Target::penetration();
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class RectangleTarget : public Target {
public:
	int radius = 44,
		shape = 88;
	unsigned int hp = 1;


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
		chnce += radius + range + pntrtionchance + shape;
		return chnce / 600;
	}

	virtual int penetration() {
		return Target::penetration();
	}

	virtual bool availability() {
		return Target::availability();
	}
};

class ShootingField {
public:
	unsigned int time = 60;

	void start() {
		int cntr_trgt_1 = 0, cntr_trgt_2 = 0, cntr_trgt_3 = 0, cntr_trgt_4 = 0, selector = 0;
		cntr_trgt_1 = rand() % 20;
		cntr_trgt_2 = rand() % 20;
		cntr_trgt_3 = rand() % 20;
		cntr_trgt_4 = rand() % 20;
		selector = rand() % 2;
		BigTarget* target = new BigTarget[cntr_trgt_1];
		AutoWeapon weapon;
		cout << "Total targets now: " << cntr_trgt_1 << endl;

		while (time > 0) {
			double shoot = (double)(rand()) / RAND_MAX;
			if (selector == 0) {
				for (int i = 0; i < cntr_trgt_1; i++) {
					while (target[i].availability() == true) {
						weapon.single_shoot();
						if (shoot < target[i].chance()) {
							target[i].penetration();
						}
						time--;
					}
				}
			}

			else if (selector == 1) {
				for (int i = 0; i < cntr_trgt_1; i++) {
					while (target[i].availability() == true) {
						weapon.multi_shoot();
						if (shoot < target[i].chance()) {
							target[i].penetration();
							target[i].penetration();
							target[i].penetration();
							target[i].penetration();
							target[i].penetration();
						}
						time -= 5;
					}
				}
			}
		}

		cout << "Time is over" << endl;
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
	ShootingField S;
	S.start();
}
