// 22. «Утиная охота». Вероятность подстрелить утку составляет 1%. Произвести 1000 (суммарно, или в каждом потоке?)
// выстрелов по утке, используя 1, 2 или 4 охотников(потоки). Подсчитать число
// попаданий в утку в каждом из трех случаев.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void hunter(int &hit, int shoots)
{
	srand((unsigned int)time(0));
	std::mutex mutex;
	for (int i = 0; i < shoots; i++) {
		int random = rand() % 100;
		if (random == 7) {
			std::cout << "Bang! Gotcha! \n";
			mutex.lock();
			hit++;
			mutex.unlock();
		}
		else {
			std::cout << "Bang! Miss \n";
		}
	}
}

void create_threads(int hunters, int shoots) {
	int hits = 0;
	std::vector<std::thread> threads;

	for (int i = 0; i < hunters; i++)
	{
		threads.push_back(std::thread(hunter, std::ref(hits), shoots));
	}
	for (auto& th : threads)
	{
		th.join();
	}
	std::cout << "---------\nHits: " << hits << " Hunters: " << threads.size() << "\n\n\n";
	threads.clear();
}

int main()
{
	int shoots = 1000;
	int hunters = 1;

	std::cout << "     __\n" <<
		           " ____(o)>\n" <<
		            "\\ < _. )\n" <<
		             " `----'\n" << "\nDuck hunt" << std::endl;
	create_threads(hunters, shoots);
	hunters++;
	create_threads(hunters, shoots);
	hunters += 2;
	create_threads(hunters, shoots);

	return 0;
}