// 22. «Утиная охота». Вероятность подстрелить утку составляет 1%. Произвести 1000 (суммарно, или в каждом потоке?)
// выстрелов по утке, используя 1, 2 или 4 охотников(потоки). Подсчитать число
// попаданий в утку в каждом из трех случаев.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
std::mutex mutex;

void hunter(int &hit, int shoots)
{
	int local_hit = 0;
	srand((unsigned int)time(0));

	for (int i = 0; i < shoots; i++) {
		int random = rand() % 100;
		if (random == 7) {
			local_hit++;
		}
	}

	mutex.lock();
	hit += local_hit;
	mutex.unlock();
}

void create_threads(int hunters, int shoots) {
	int hits = 0;
	int thread_shoots = shoots / hunters;
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
	std::cout << "-----------------\nHits: " << hits << " Hunters: " << threads.size() << " Total time: " << (float)duration.count() << "\n\n\n";
	threads.clear();
}

int main()
{
	int shoots = 100000000; // Must be /2
	int hunters = 1;

	std::cout << "     __\n" <<
		           " ____(o)>\n" <<
		            "\\ < _. )\n" <<
		             " `----'\n" << "\nDuck hunt" << std::endl;
	create_threads(hunters, shoots);
	hunters += 1;
	create_threads(hunters, shoots);
	hunters += 2;
	create_threads(hunters, shoots);

	system("pause");
	return 0;
}