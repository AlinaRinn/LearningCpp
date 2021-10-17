#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Weapon {
public:
	int damage;
	int reload;
	int DPM() {
		int dpm = 60 / reload * damage;
		return dpm;
	}
};

class Sword : public Weapon {
public:
	void Fire() {
		cout << "Clang!" << endl;
	}
};

class Pistol : public Weapon {
public:
	void Fire() {
		cout << "Bang!" << endl;
	}
};

class Shop {
public:
	int N = 0, Sw = 0, Pw = 0;

	void Gen() {
		cout << "Enter amount of weapon to observe: \n";
		srand((unsigned int)time(0));
		cin >> N;
		Sw = rand() % N;
		Pw = N - Sw;
		Sword* sword = new Sword[Sw];
		Pistol* pistol = new Pistol[Pw];

		for (int i = 0; i < Sw; i++) {
			sword[i].damage = 80 + rand() % 20;
			sword[i].reload = 2 + rand() % 4;
		}
		for (int i = 0; i < Pw; i++) {
			pistol[i].damage = 30 + rand() % 20;
			pistol[i].reload = 1 + rand() % 2;
		}

		char exit = ' ';
		cout << "Enter 'y' if you want to select this weapon; or 'n' if don't.\n" << endl;

		if (exit != 'y') {
			for (int i = 0; i < Sw; i++) {
				cout << "Sword " << i << ": " << endl << "Damage: " << sword[i].damage << endl << "Reload: " << sword[i].reload << endl << "DPM: " << sword[i].DPM() << endl;
				cin >> exit;
				if (exit == 'y') {
					cout << "\nWeapon selected. Good luck!\n\n";
					break;
				}
			}
		}

		if (exit != 'y') {
			for (int i = 0; i < Pw; i++) {
				cout << "Pistol " << i << ": " << endl << "Damage: " << pistol[i].damage << endl << "Attack Speed: " << pistol[i].reload << endl << "DPM: " << pistol[i].DPM() << endl;
				cin >> exit;
				if (exit == 'y') {
					cout << "\nWeapon selected. Good luck!\n\n";
					break;
				}
			}
		}
		system("pause");
	}
};

int main()
{
	Shop s;
	s.Gen();
}
