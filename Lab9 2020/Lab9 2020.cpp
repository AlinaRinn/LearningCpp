#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#define N 11
#define M 34

using namespace std;

bool Check(char ch, char* check) {
	bool tm = false;
	for (int i = 0; i < N; i++) {
		if (ch == check[i]) {
			tm = true;
			break;
		}
	}
	return tm;
}

char Replace(char ch, char* UpperCase, char* LowerCase) {
	for (int i = 0; i < M-1; i++) {
		if (ch == UpperCase[i]) {
			ch = LowerCase[i];
		}
	}
	return ch;
}

struct Word
{
	string word;
	int copies = 0;
};

int main()
{
	// File open + check
	setlocale(LC_ALL, "rus");
	ifstream in("Oak.txt");
	if (!in.is_open()) {
		cout << "Open file error \n";
		system("pause");
		exit(-1);
	}

	vector<string> finn;
	char check[N] = { ' ', ',', '"', '—', '!', '?', '«', '»', '.', ':', ';'};
	char UpperCase[M] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char LowerCase[M] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	string word;
	char ch;

	// Reading + Refactoring
	while (!in.eof()) {
		ch = in.get();
		ch = Replace(ch, UpperCase, LowerCase);
		if (Check(ch, check) == false && ch != '\n') { //????
			word += ch;
		}
		if ((ch == ' ' || ch == '\n') && word.length() > 0) {
			finn.push_back(word);
			word.clear();
		}
	}
	in.close(); 

	// Sorting + Printing
	sort(finn.begin(), finn.end());
	cout << "Состав текста: " << "\n";
	for (int i = 0; i < finn.size(); i++) {
		cout << left << setw(5) << i+1 << finn[i] << "\n";
	}

	// Vector of Structs with words required + Printing
	word = "";
	string word2;
	int copies = 1, structVar = 0;
	vector<Word*> VecWords;
	for (int i = 0; i < finn.size()-1; i++) {
		word = finn[i];
		word2 = finn[i+1];

		if (word == word2) {
			copies++;
		}
		else {			
			VecWords.push_back(new Word);
			VecWords[structVar]->word = word;
			VecWords[structVar]->copies = copies;
			structVar++;
			copies = 1;
		}
	}

	if (copies > 0) {
		VecWords.push_back(new Word);
		VecWords[structVar]->word = word2;
		VecWords[structVar]->copies = copies;
		structVar++;
		copies = 0;
	}

	ofstream out("Oak_Analysis.txt");
	ofstream out2("Oak_NoCopies.txt");
	cout << "\n\nКол-во слов: " << "\n";
	out << "Кол-во слов: " << "\n";
	for (int i = 0; i < VecWords.size() - 1; i++) {
		cout << left << setw(5) << i + 1 << setw(25) << VecWords[i]->word << setw(3) << VecWords[i]->copies << "\n";
		out << left << setw(5) << i + 1 << setw(25) << VecWords[i]->word << setw(3) << VecWords[i]->copies << "\n";
		out2 << VecWords[i]->word << " ";
	}
	out.close();
	out2.close();
}

