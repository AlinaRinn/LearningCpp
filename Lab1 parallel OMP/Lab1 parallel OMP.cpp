// 22. «Утиная охота». Вероятность подстрелить утку составляет 1%. Произвести 1000 (суммарно, или в каждом потоке?)
// выстрелов по утке, используя 1, 2 или 4 охотников(потоки). Подсчитать число
// попаданий в утку в каждом из трех случаев. Юзаем OMP

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <omp.h>
std::mutex mutex;

// Function, which shoots the duck
void hunter(int shoots, int &hit)
{
	int local_hit = 0;
	srand((unsigned int)time(0));

	for (int i = 0; i < shoots; i++) {
		int random = rand() % 100;
		if (random == 7) {
			local_hit++;
		}
	}

#pragma omp critical
	hit += local_hit;
}

int main()
{
	int shoots = 50000000, // Must be /2
		hunters = 4,
		thread_shoots,
		hit = 0;
	double start = 0.0, end = 0.0;
	std::cout << "     __\n" <<
		" ____(o)>\n" <<
		"\\ < _. )\n" <<
		" `----'\n" << "\nDuck hunt" << std::endl;

	// Function calls & time output

	for (int i = 1; i <= hunters; i++)
	{
		auto begin = std::chrono::high_resolution_clock::now();
		start = omp_get_wtime();
		hit = 0;
		thread_shoots = (int)(shoots / i);
#pragma omp parallel shared(hit) num_threads(i)
		{
			hunter(thread_shoots, std::ref(hit));
		}
		auto dend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = dend - begin;
		std::cout << " Total time: " << (float)duration.count() << "\n" << "Hits: " << hit << "\n";
		end = omp_get_wtime();
		std::cout << end - start << std::endl;

	}
	system("pause");
	return 0;
}