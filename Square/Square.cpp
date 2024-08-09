// Алгоритм быстрого возведения в степень

#include <iostream>

float power(float value, int pow) {
	float result = 1;
	while (pow > 0) {
		if (pow % 2 == 1) {
			result *= value;
		}
		value *= value;
		pow /= 2;
	}
	return result;
}

int main()
{
	float value = 0;
	int	pow = 0;

	std::cin >> value;
	std::cin >> pow;
	std::cout << power(value, pow);
}


