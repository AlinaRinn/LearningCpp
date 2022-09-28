// 22. «Утиная охота». Вероятность подстрелить утку составляет 1%. Произвести 1000 (суммарно, или в каждом потоке?)
// выстрелов по утке, используя 1, 2 или 4 охотников(потоки). Подсчитать число
// попаданий в утку в каждом из трех случаев.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
std::mutex mutex;

void hunter(int &hit, int shoots, double &total_time)
{
	double time_thread = 0;
	clock_t start, end;
	int local_hit = 0;
	start = clock();

	srand((unsigned int)time(0));
	for (int i = 0; i < shoots; i++) {
		int random = rand() % 100;
		if (random == 7) {
			//std::cout << "Bang! Gotcha! \n";
			local_hit++;
		}
		else {
			//std::cout << "Bang! Miss \n";
		}
	}
	end = clock();
	time_thread = ((double)end - start) / ((double)CLOCKS_PER_SEC);
	mutex.lock();
	total_time += time_thread;
	hit += local_hit;
	mutex.unlock();
	std::cout << "Hunter's time: " << time_thread << "\n";
}

void create_threads(int hunters, int shoots) {
	int hits = 0;
	int thread_shoots = shoots / hunters;
	double total_time = 0;
	std::vector<std::thread> threads;

	for (int i = 0; i < hunters; i++)
	{
		threads.push_back(std::thread(hunter, std::ref(hits), thread_shoots, std::ref(total_time)));
	}
	for (auto& th : threads)
	{
		th.join();
	}
	std::cout << "-----------------\nHits: " << hits << " Hunters: " << threads.size() << " Total time: " << total_time << "\n\n\n";
	threads.clear();
}

int main()
{
	int shoots = 10000000; // Must be /2
	int hunters = 1;

	std::cout << "     __\n" <<
		           " ____(o)>\n" <<
		            "\\ < _. )\n" <<
		             " `----'\n" << "\nDuck hunt" << std::endl;
	create_threads(hunters, shoots);
	hunters += 3;
	create_threads(hunters, shoots);
	hunters += 4;
	create_threads(hunters, shoots);

	system("pause");
	return 0;
}