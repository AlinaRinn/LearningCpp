#include <iostream>
#include <thread>

void hunter(int _id)
{
	std::cout << "Launched by thread " << _id << std::endl;
}

int main()
{
	std::cout << "Duck hunt" << std::endl;
	const int num_threads = 10;
	std::thread thr(num_threads);
	for (int i = 0; i < num_threads; ++i)
	{
		thr[i] = std::thread(function_to_call, i);
	}

	for (int i = 0; i < num_threads; ++i)
	{
		thr[i].join;
	}
	return 0;
}