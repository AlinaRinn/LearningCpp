#include <iostream>
#include <fstream>
#define N 27
#define R 34

using namespace std;

char DetectLangandCase(char ch, int* number, char* UpperCaseRu, char* LowerCaseRu, char* UpperCaseEn, char* LowerCaseEn) {
	char check = 'N'; 

	for (int i = 0; i < N; i++) {
		if (ch == UpperCaseEn[i]) {
			check = 'E'; 
			*number = i;
		}
		else if (ch == LowerCaseEn[i]) {
			check = 'e';
			*number = i;
		}
	}

	for (int i = 0; i < R; i++) {
		if (ch == UpperCaseRu[i]) {
			check = 'R';
			*number = i;
		}
		else if (ch == LowerCaseRu[i]) {
			check = 'r';
			*number = i;
		}
	}
	return check;
} // N - not a letter, Ee - English, Rr - Russian

void CesarReplace(int* number, char* UpperCaseRu, char* LowerCaseRu, char* UpperCaseEn, char* LowerCaseEn, int CesarLvlRu, int CesarLvlEn) {
	char ch; // Text character
	char checker; // Lang and case check
	ifstream in("input.txt");
	if (!in.is_open()) {
		cout << "Open file error \n";
		system("pause");
		exit(-1);
	}
	ofstream out("output1.txt");
	
	while (!in.eof()) {
		ch = in.get();
		checker = DetectLangandCase(ch, number, UpperCaseRu, LowerCaseRu, UpperCaseEn, LowerCaseEn);

		if (checker == 'r' || checker == 'R') {
			int arrayValidateRu = *number + CesarLvlRu;

			if (arrayValidateRu > R - 2) {
				arrayValidateRu = 0 + (arrayValidateRu - (R - 1));
			}
			if (checker == 'R') {
				ch = UpperCaseRu[arrayValidateRu];
			}
			else if (checker == 'r') {
				ch = LowerCaseRu[arrayValidateRu];
			}
		}
		else if (checker == 'e' || checker == 'E') {
			int arrayValidateEn = *number + CesarLvlEn;

			if (arrayValidateEn > N - 2) {
				arrayValidateEn = 0 + (arrayValidateEn - (N - 1));
			}
			if (checker == 'E') {
				ch = UpperCaseEn[arrayValidateEn];
			}
			else if (checker == 'e') {
				ch = LowerCaseEn[arrayValidateEn];
			}
		}
	
		out << ch;
		cout << ch;
	}

	in.close();
	out.close();

	int tmp = 0;
	cout << "\n\nКлюч расшифровки (EN): ";
	tmp = (N - 1) - CesarLvlEn;
	cout << tmp;
	cout << "\n\nКлюч расшифровки (RU): ";
	tmp = (R - 1) - CesarLvlRu;
	cout << tmp;
	cout << "\n\nЗаписано в файл" << "\n";
}

void VizenerReplace(char* KeyChar, int* number, char* UpperCaseRu, char* LowerCaseRu, char* UpperCaseEn, char* LowerCaseEn) {
	char ch; // Text character
	char checker; // Lang and case check and number - number in 'case' array
	int *KeyInt = new int[strlen(KeyChar)]();
	int KeyIterator = 0;

	cout << "\nКлюч в числовом виде: ";

	for (int i = 0; i < strlen(KeyChar); i++)
	{
		DetectLangandCase(KeyChar[i], number, UpperCaseRu, LowerCaseRu, UpperCaseEn, LowerCaseEn);
		KeyInt[i] = *number;
		cout << KeyInt[i] << " ";
	}
	cout << " (0-25) \n\n";
	ifstream in("input.txt");
	if (!in.is_open()) {
		cout << "Open file error \n";
		system("pause");
		exit(-1);
	}
	ofstream out("output2.txt");

	while (!in.eof()) {
		ch = in.get();
		checker = DetectLangandCase(ch, number, UpperCaseRu, LowerCaseRu, UpperCaseEn, LowerCaseEn);

		if (KeyIterator >= strlen(KeyChar)) {
			KeyIterator = 0;
		}

		if (checker == 'r' || checker == 'R') {
			int arrayValidateRu = *number + KeyInt[KeyIterator];
	
			if (arrayValidateRu > R - 2) {
				arrayValidateRu = 0 + (arrayValidateRu - (R - 1));
			}
			if (checker == 'R') {
				ch = UpperCaseRu[arrayValidateRu];
			}
			else if (checker == 'r') {
				ch = LowerCaseRu[arrayValidateRu];
			}
			KeyIterator++;
		}
		else if (checker == 'e' || checker == 'E') {
			int arrayValidateEn = *number + KeyInt[KeyIterator];

			if (arrayValidateEn > N - 2) {
				arrayValidateEn = 0 + (arrayValidateEn - (N - 1));
			}
			if (checker == 'E') {
				ch = UpperCaseEn[arrayValidateEn];
			}
			else if (checker == 'e') {
				ch = LowerCaseEn[arrayValidateEn];
			}
			KeyIterator++;
		}

		out << ch;
		cout << ch;
	}
	cout << "\n\nКлюч шифровки: " << KeyChar;
	cout << "\n\nКлюч расшифровки: ";
	for (int i = 0; i < strlen(KeyChar); i++)
	{
		ch = LowerCaseEn[(N-1) - KeyInt[i]];
		cout << ch;
	}

	in.close();
	out.close();
	cout << "\n\nЗаписано в файл" << "\n";
}

int main()
{
	// All symbols
	char UpperCaseRu[R] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char LowerCaseRu[R] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	char UpperCaseEn[N] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char LowerCaseEn[N] = "abcdefghijklmnopqrstuvwxyz";
	int number = 0; // number in 'case' arrays, 0-25 or 0-32
	bool selector;

	setlocale(LC_ALL, "rus");
	cout << "Добро пожаловать в Шифры!\n**************************\n"
		<< "Шифр Цезаря (0)\n\n"
		<< "Шифрование\n------------\nТекст для шифровки поместите в файл 'input.txt' в один каталог с программой.\n"
		<< "Введите в консоль количество символов сдвига для каждого языка.\n"
		<< "Зашифрованный текст будет выведен в файл 'output1.txt' и в консоль.\n\n"
		<< "Дешифровка\n------------\nЗашифруйте ваш файл со сдвигом (кол-во букв в алфавите) - (ваш сдвиг)\n"
		<< "\n\nШифр Виженера (1)\n\n"
		<< "Шифрование\n------------\nТекст для шифровки поместите в файл 'input.txt' в один каталог с программой.\n"
		<< "Введите в консоль Ключ-Слово (Латиница).\n"
		<< "Зашифрованный текст будет выведен в файл 'output2.txt' и в консоль.\n\n"
		<< "Дешифровка\n------------\nЗашифруйте ваш файл еще раз со словом-ключом, выведенным в консоль\n"
		<< "\n\nШифр Виженера (1)\n\n"
		<< "\n\nШифр Цезаря поддерживает русский и английский языки, Вижнера - русский\n\n\n";
	
	loop:
	cout << "\n\nВыберите шифрование (0-1): \n";
	cin >> selector;

	if (selector == 0) {
		int CesarLvlRu = 0; // 1-32, 0 and 33 - initial
		int CesarLvlEn = 0; // 1-25, 0 and 26 - initial
		cout << "Сдвиг для Английского языка (1-25):\n";
		cin >> CesarLvlEn;
		cout << "Сдвиг для Русского языка (1-32):\n";
		cin >> CesarLvlRu;
		cout << "\n\n\n";
		CesarReplace(&number, UpperCaseRu, LowerCaseRu, UpperCaseEn, LowerCaseEn, CesarLvlRu, CesarLvlEn);
	}
	else if (selector == 1) {
		string KeyWord = "";
		cout << "Слово-ключ (только латинские символы):\n";
		cin >> KeyWord;
		char *KeyChar = new char[KeyWord.length()];
		//strcpy(KeyChar, KeyWord.c_str());
		strncpy(KeyChar, KeyWord.c_str(), KeyWord.length() + 1);
		cout << "\nВведен ключ: ";

		for (int i = 0; i < strlen(KeyChar); i++)
		{
			cout << KeyChar[i];
		}

		cout << "\n\nКлюч будет записан в файл";
		VizenerReplace(KeyChar, &number, UpperCaseRu, LowerCaseRu, UpperCaseEn, LowerCaseEn);
	}
	goto loop;
	system("pause");
}

