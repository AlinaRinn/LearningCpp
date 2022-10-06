// 11. Сгенерировать массив из 300 строк, содержащих случайные 200000 цифр.
// Посчитать число вхождений четных и нечетных цифр в каждой строке, используя N потоков.
// Измерить время программы для N = 1, 2, 4, 10. Измерить работы время программы в каждом случае.

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

float counter() {

}

float create_threads(int number, int shoots) {
	int hits = 0;
	int thread_shoots = (int)(shoots / hunters);
	std::vector<std::thread> threads;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < hunters; i++)
	{
		threads.push_back(std::thread(hunter, std::ref(hits), thread_shoots));
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
	srand(time(0));
	std::array<std::string, 300> custom;
	for (std::string var : custom) {
		for (int i = 0; i < 200000; i++) {
			var += std::to_string((rand() % 9));
		}
		//std::cout << var << "\n\n";
	}


}