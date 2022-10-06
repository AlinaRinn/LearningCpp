// 11. Сгенерировать массив из 300 строк, содержащих случайные 200000 цифр.
// Посчитать число вхождений четных и нечетных цифр в каждой строке, используя N потоков.
// Измерить время программы для N = 1, 2, 4, 10. Измерить работы время программы в каждом случае.

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

// Bad practice 2, no access restriction, doesnt matter =]
std::array<std::string, 300> custom_array;

float counter(int start, int stop) {

}

float create_threads(int number_threads) {
	int even = 0,
		odd = 0,
		threads_piece = (int)(custom_array.size() / number_threads),
		start = 0,
	    stop = threads_piece - 1;
	std::vector<std::thread> threads;
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < number_threads; i++)
	{
		threads.push_back(std::thread(counter, start, stop));
		start = ++stop;
		stop += threads_piece;
	}
	for (auto& th : threads)
	{
		th.join();
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "-----------------\nHits: " << hits << " Hunters: " << threads.size();
	threads.clear();
	return (float)duration.count();
}

int main()
{
	// Variables
	int number_threads = 1, 
		string_lenght = 200000;
	srand((unsigned int)time(0));

	// Fulling Array
 	for (std::string var : custom_array) {
		for (int i = 0; i < string_lenght; i++) {
			var += std::to_string((rand() % 9));
		}
	}

	// Threads
	int number_threads = 1;
	create_threads(number_threads);
	number_threads++;
	create_threads(number_threads);
	number_threads += 2;
	create_threads(number_threads);
	number_threads += 6;
	create_threads(number_threads);

	system("pause");
	return EXIT_SUCCESS;
}