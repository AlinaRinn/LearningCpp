#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

class DefenseTower {
private:
	int hp = 100;
	int damage = 0; // 20-50
	bool availability = true;
public:
	DefenseTower() {
		damage = 20 + rand() % 31;
	}
	~DefenseTower() {}

	bool getAvailability() {
		return availability;
	}

	void setAvailability(bool p) {
		availability = p;
	}

	void setRngDamage() {
		damage = 20 + rand() % 31;
	}

	void damager(int p) {
		hp -= p;
	}

	int getDamage() {
		return damage;
	}

	int getHp() {
		return hp;
	}
};

class Dragon {
private:
	int hp = 1500;
	int damage = 0; // 20-80
public:
	Dragon() {
		damage = 20 + rand() % 61;
	}
	~Dragon() {}

	void setRngDamage() {
		damage = 20 + rand() % 61;
	}

	void damager(int p) {
		hp -= p;
	}

	int getDamage() {
		return damage;
	}

	int getHp() {
		return hp;
	}
};

class Castle {
private:
	static const int towerCount = 16;
	Dragon drag;
	DefenseTower towers[towerCount];

public:
	void Gen() {
		for (int i = 0; i < towerCount; i++) {
			towers[i].setRngDamage();
		}
		drag.setRngDamage();
	}

	void DragonAttack(int tmp) {
		if (tmp > 0 && tmp < towerCount - 1) {
			towers[tmp - 1].damager(drag.getDamage());
			towers[tmp].damager(drag.getDamage());
			towers[tmp + 1].damager(drag.getDamage());
		}
		else if (tmp == 0) {
			towers[towerCount-1].damager(drag.getDamage());
			towers[tmp].damager(drag.getDamage());
			towers[tmp + 1].damager(drag.getDamage());
		}
		else if (tmp == towerCount - 1)
		{
			towers[tmp - 1].damager(drag.getDamage());
			towers[tmp].damager(drag.getDamage());
			towers[0].damager(drag.getDamage());
		}

		for (int i = 0; i < towerCount; i++) {
			if (towers[i].getHp() <= 0) {
				towers[i].setAvailability(false);
			}
		}
		cout << "Dragon's target: Tower " << tmp << "\n";
	}

	void TowersAttack(int tmp) {
		if (tmp > 1 && tmp < towerCount - 2) {
			drag.damager(towers[tmp - 2].getDamage()*towers[tmp - 2].getAvailability() + towers[tmp - 1].getDamage()*towers[tmp - 1].getAvailability() + towers[tmp].getDamage()*towers[tmp].getAvailability() + towers[tmp + 1].getDamage()*towers[tmp + 1].getAvailability() + towers[tmp + 2].getDamage()*towers[tmp + 2].getAvailability());
		}
		else if (tmp == 0) {
			drag.damager(towers[towerCount - 2].getDamage() * towers[towerCount - 2].getAvailability() + towers[towerCount - 1].getDamage() * towers[towerCount - 1].getAvailability() + towers[tmp].getDamage() * towers[tmp].getAvailability() + towers[tmp + 1].getDamage() * towers[tmp + 1].getAvailability() + towers[tmp + 2].getDamage() * towers[tmp + 2].getAvailability());
		}
		else if (tmp == 1)
		{
			drag.damager(towers[towerCount - 1].getDamage() * towers[towerCount - 1].getAvailability() + towers[tmp - 1].getDamage() * towers[tmp - 1].getAvailability() + towers[tmp].getDamage() * towers[tmp].getAvailability() + towers[tmp + 1].getDamage() * towers[tmp + 1].getAvailability() + towers[tmp + 2].getDamage() * towers[tmp + 2].getAvailability());
		}
		else if (tmp == towerCount - 1) {
			drag.damager(towers[tmp - 2].getDamage() * towers[tmp - 2].getAvailability() + towers[tmp - 1].getDamage() * towers[tmp - 1].getAvailability() + towers[tmp].getDamage() * towers[tmp].getAvailability() + towers[0].getDamage() * towers[0].getAvailability() + towers[1].getDamage() * towers[1].getAvailability());
		}
		else if (tmp == towerCount - 2)
		{
			drag.damager(towers[tmp - 2].getDamage() * towers[tmp - 2].getAvailability() + towers[tmp - 1].getDamage() * towers[tmp - 1].getAvailability() + towers[tmp].getDamage() * towers[tmp].getAvailability() + towers[tmp + 1].getDamage() * towers[tmp + 1].getAvailability() + towers[0].getDamage() * towers[0].getAvailability());
		}
	}

	void AttackSelector() {
		int select = rand() % 2;
		(select == 0) ? cout << "Random tower mode\n\n" : cout << "Focus tower mode\n\n";
		int counter = 0;
		while (castleDefeat() != true && drag.getHp() > 0) {
			if (select == 0) {
				int tmp = rand() % towerCount;
				Gen();
				while (towers[tmp].getAvailability() == false) {
					tmp = rand() % towerCount;
				}
				DragonAttack(tmp);	
				TowersAttack(tmp);
				print(++counter);
			}

			else if (select == 1) {
				int tmp = rand() % towerCount;
				while (towers[tmp].getAvailability() == true && drag.getHp() > 0)
				{
					Gen();
					DragonAttack(tmp);
					TowersAttack(tmp);
					print(++counter);
				}
			}
		}

		if (drag.getHp() <= 0 && castleDefeat() != true) {
			cout << "\nDragon has been defeated. Castle win!" << "\n";
			int statHP = 0, statcount = 0, dgDamage = 0;
			for (int i = 0; i < towerCount; i++) {
				if (towers[i].getAvailability() == true) {
					statcount++;
					statHP += towers[i].getHp();
				}
				dgDamage += towers[i].getHp();
			}
			dgDamage = dgDamage * (-1) + (towerCount * 100); // 1
			cout << "Towers left: " << statcount << "\nTotal HP left: " << statHP << "\nRecived damage: " << dgDamage << "\nDamaged: " << 1500 - drag.getHp() << "\n"; // 2

		}
		else if (castleDefeat() == true && drag.getHp() > 0) {
			int dgDamage = 0;
			for (int i = 0; i < towerCount; i++) {
				dgDamage += towers[i].getHp();
			}
			dgDamage = dgDamage * (-1) + (towerCount * 100); // 3 idk how to link with class, let be in this way
			cout << "\nCastle has been destroyed. Dragon win...\n" << "Dragon HP left: " << drag.getHp() << "\nDragon's damage: " << dgDamage << "\n";
		}
	}

	void print(int p) {
		cout << "Turn " << p << ": \n" << "-----------------------------------------" << "\n";
		for (int i = 0; i < towerCount; i++) {
			cout << left  << "Tower " << setw(2) << i << " | HP: " << setw(4) << towers[i].getHp() << "| Damage: " << setw(3) << towers[i].getDamage() << "\n";
		}
		cout << "\nDragon damage: " << drag.getDamage() << "\nDragon HP: " << drag.getHp() << "\n\n";
	}

	bool castleDefeat() {
		int check = 0;
		for (int i = 0; i < towerCount; i++) {
			check += towers[i].getAvailability();
		}
		return (check == 0) ? true : false;
	}
};



int main()
{
	srand((unsigned int)time(0));
	Castle cast;
	cast.AttackSelector();
	system("pause");
}
