#include <iostream>
#include "math.h"

bool esPolidivisible(long long int n, int d)
{
	bool b;

	if (d == 1)
	{
		b = true;
	}
	else
	{
		b = (n % d == 0) && esPolidivisible( (n-(n%10))/10, d - 1);
	}

	return b;
}

int main()
{
	long long int number;
	int digits;

	std::cin >> number;
	while (std::cin)
	{
		digits = (int)floor(log10(number)) + 1;

		if (esPolidivisible(number, digits))
		{
			std::cout << "POLIDIVISIBLE\n";
		}
		else
		{
			std::cout << "NO POLIDIVISIBLE\n";
		}

		std::cin >> number;
	}
}