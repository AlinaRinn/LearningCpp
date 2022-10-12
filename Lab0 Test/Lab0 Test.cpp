#include <iostream>
#include <array>
#include <string>


int main(int argc, char** argv)
{
	// Variables
	int number_threads = 1,
		string_lenght = 200;
	srand((unsigned int)time(0));
	std::array<std::string, 300> custom_array;
	std::array<int, custom_array.size()> even_array;

	// Filling Array. Also need parallelization for better performance -_-
	std::cout << "Start of filling array\n";
	for (int i = 0; i < custom_array.size(); i++) {
		for (int j = 0; j < string_lenght; j++) {
			custom_array.at(i) += std::to_string((rand() % 9));
			std::cout << custom_array.at(i) << "\n\n\n";
		}
	}

	std::string s;
	int even = 0, x = 0;
	for (int i = 0; i < string_lenght; i++) {
		s = custom_array.at(i);
		for (auto c : s) {
			x = c - '0';
			if (x % 2 == 0) {
				even++;
			}
		}
		even_array[i] = even;
		even = 0;
	}

	std::cout << "Even \n" << even << "Odd " << string_lenght - even;

}