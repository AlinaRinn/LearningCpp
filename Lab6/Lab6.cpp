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

	int shoot(double chance, int count) {		
		int hitter = 0;
		for (int i = 0; i < count; i++) {
			double shoot = (double)(rand()) / RAND_MAX;
			int speed = (int)(1000 / count);
			if (ammo <= 0) {
				reload();
			}
			if (shoot <= chance) {
				ammo--;
				hitter++;
				cout << "Bang!" << " Hit! " << "     Shoot's hit chance was: " << setw(10) << shoot << " | Hit chance: " << chance << endl;
				Sleep(speed);
			}
			else if (shoot > chance) {
				ammo--;
				cout << "Twiy!" << " Miss!" << "     Shoot's hit chance was: " << setw(10) << shoot << " | Hit chance: " << chance << endl;
				Sleep(speed);
			}
			chance -= 0.1;
		}
		return damage * hitter;
	}

	int multi_shoot(double chance) {
		int shootcounter = 3 + rand() % 5;
		cout << "Burst! \n";
		return shoot(chance, shootcounter);
	}

	void reload() {
		cout << "\nReloading..." << endl;
		ammo = 30;
		Sleep(5000);
	}
};

class Target {                           // Abstract class
protected:
	int radius = 100; // 0-100
	int range = 100; // 0-100
	double pntrtionchance = (radius + range) / 2; // 0-100
	bool movable = false; // 50or100
	char material = 'W'; // M - 95, W - 100, L - 99
	int hp = 5;

public:
	virtual double chance() = 0;

	virtual bool checkChance(double p) = 0;

	virtual void penetration(int p) = 0;

	virtual bool availability() = 0;

	// // // // // // // // // // // // //

	virtual int getRad() = 0;

	virtual int getRange() = 0;

	virtual double getPntr() = 0;

	virtual bool getMove() = 0;

	virtual char getMat() = 0;

	virtual int getHp() = 0;

	// // // // // // // // // // // // //

	virtual void setRange(int p) = 0;

	virtual void setPntr(double p) = 0;

	virtual void setMove(bool p) = 0;

	virtual void setMat(char p) = 0;

	virtual void setHp(int p) = 0;
};

void Target::setRange(int p) {
	range = p;
}

void Target::setPntr(double p) {
	pntrtionchance = p;
}

void Target::setMove(bool p) {
	movable = p;
}

void Target::setMat(char p) {
	material = p;
}

void Target::setHp(int p) {
	hp = p;
}

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

bool Target::checkChance(double p) {
	return p < chance() ? true : false;
}

class BigTarget : public Target {
public:
	int radius = 100; // 0-100
	int hp = 5;

	virtual void setRange(int p) {
		return Target::setRange(p);
	}

	virtual void setPntr(double p) {
		return Target::setPntr(p);
	}

	virtual void setMove(bool p) {
		return Target::setMove(p);
	}

	virtual void setMat(char p) {
		return Target::setMat(p);
	}

	virtual void setHp(int p) {
		return Target::setHp(p);
	}

	virtual int getRad() {
		return radius;
	}

	virtual int getRange() {
		return range;
	}

	virtual double getPntr() {
		return pntrtionchance;
	}

	virtual bool getMove() {
		return movable;
	}

	virtual char getMat() {
		return material;
	}

	virtual int getHp() {
		return hp;
	}

	virtual double chance() {
		return Target::chance();
	}

	virtual bool checkChance(double p) {
		return Target::checkChance(p);
	}

	virtual bool availability() {
		return hp > 0 ? true : false;
	}

	virtual void penetration(int p) {
		hp -= p;
	}
};

class MediumTarget : public Target {
public:
	int radius = 75;
	int hp = 3;

	virtual void setRange(int p) {
		return Target::setRange(p);
	}

	virtual void setPntr(double p) {
		return Target::setPntr(p);
	}

	virtual void setMove(bool p) {
		return Target::setMove(p);
	}

	virtual void setMat(char p) {
		return Target::setMat(p);
	}

	virtual void setHp(int p) {
		return Target::setHp(p);
	}

	virtual int getRad() {
		return radius;
	}

	virtual int getRange() {
		return range;
	}

	virtual double getPntr() {
		return pntrtionchance;
	}

	virtual bool getMove() {
		return movable;
	}

	virtual char getMat() {
		return material;
	}

	virtual int getHp() {
		return hp;
	}

	virtual double chance() {
		return Target::chance();
	}

	virtual bool checkChance(double p) {
		return Target::checkChance(p);
	}

	virtual bool availability() {
		return hp > 0 ? true : false;
	}

	virtual void penetration(int p) {
		hp -= p;
	}
};

class SmallTarget : public Target {
public:
	int radius = 50;
	int hp = 1;

	virtual void setRange(int p) {
		return Target::setRange(p);
	}

	virtual void setPntr(double p) {
		return Target::setPntr(p);
	}

	virtual void setMove(bool p) {
		return Target::setMove(p);
	}

	virtual void setMat(char p) {
		return Target::setMat(p);
	}

	virtual void setHp(int p) {
		return Target::setHp(p);
	}

	virtual int getRad() {
		return radius;
	}

	virtual int getRange() {
		return range;
	}

	virtual double getPntr() {
		return pntrtionchance;
	}

	virtual bool getMove() {
		return movable;
	}

	virtual char getMat() {
		return material;
	}

	virtual int getHp() {
		return hp;
	}

	virtual double chance() {
		return Target::chance();
	}

	virtual bool checkChance(double p) {
		return Target::checkChance(p);
	}

	virtual bool availability() {
		return hp > 0 ? true : false;
	}

	virtual void penetration(int p) {
		hp -= p;
	}
};

class RectangleTarget : public Target {
public:
	int radius = 44,
		shape = 88;
	int hp = 1;

	virtual void setRange(int p) {
		return Target::setRange(p);
	}

	virtual void setPntr(double p) {
		return Target::setPntr(p);
	}

	virtual void setMove(bool p) {
		return Target::setMove(p);
	}

	virtual void setMat(char p) {
		return Target::setMat(p);
	}

	virtual void setHp(int p) {
		return Target::setHp(p);
	}

	virtual int getRad() {
		return radius;
	}

	virtual int getRange() {
		return range;
	}

	virtual double getPntr() {
		return pntrtionchance;
	}

	virtual bool getMove() {
		return movable;
	}

	virtual char getMat() {
		return material;
	}

	virtual int getHp() {
		return hp;
	}

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

	virtual bool checkChance(double p) {
		return p < chance() ? true : false;
	}

	virtual bool availability() {
		return hp > 0 ? true : false;
	}

	virtual void penetration(int p) {
		hp -= p;
	}
};

class ShootingField {
public:
	int time = 30, targets = 60;

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

			tar[i]->setRange(range);
			movable == 0 ? tar[i]->setMove(true) : tar[i]->setMove(false);
			if (material == 0) {
				tar[i]->setMat('M');
			}
			else if (material == 1) {
				tar[i]->setMat('W');
			}
			else if (material == 2) {
				tar[i]->setMat('L');
			}
		}

		AutoWeapon weapon;
		cout << "Total targets now: " << tar.size() << endl << endl;

		for (int i = 0; i < tar.size(); i++) {
			cout << "Target " << left << setw(3) << i << "|"
				<< " Radius: " << setw(3) << tar[i]->getRad()
				<< " Range: " << setw(3) << 100 - tar[i]->getRange()
				<< " HP: " << setw(2) << tar[i]->getHp()
				<< " Material: " << setw(2) << tar[i]->getMat()
				<< " Movable: " << setw(2) << tar[i]->getMove()
				<< " Hit chance: " << setw(10) << tar[i]->chance() << endl;
		}

		cout << "\nShooting starts!\n";

		int statTD = 0; double averageDamage = 0;
		for (int i = 0; i < tar.size(); i++) {
			if (time > 0) {
				int selector = rand() % 2;
				cout << "\nCurrent Target: " << i << ", Time: " << time << endl;
				averageDamage += tar[i]->getHp();
				while (tar[i]->availability() == true) {
					if (selector == 0) {
						tar[i]->penetration(weapon.shoot(tar[i]->chance(), 1));
						time--;
					}
					else if (selector == 1) {
						int tmp = weapon.multi_shoot(tar[i]->chance());
						tar[i]->penetration(tmp);
						time--;
					}
				}
				statTD++;				
			}
		}
		cout << "\nTime is over!\n\nStats:\n---------------" << endl;
		cout << "Targets destroyed: " << statTD << "\nTargets lost: " << targets - statTD << "\nAverage Damage: " << averageDamage / statTD << endl;
		vector<Target*>().swap(tar);
		cout << "Allocated memory: " << tar.capacity() << endl;
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
		system("pause");
	}
