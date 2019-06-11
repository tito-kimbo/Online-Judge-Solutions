#include <iostream>

const long long int FACTOR = 31543;

long long int elevar(int num, int pot) //num^pot
{
	long long int aux;

	if (pot == 0)
	{
		aux = 1;
	}
	else if (pot == 1)
	{
		aux = num % FACTOR;
	}
	else
	{
		aux = elevar(num, pot / 2);
		if (pot % 2 == 0)
		{
			aux = (aux*aux) % FACTOR;
		}
		else
		{
			aux = (aux*aux*num) % FACTOR;
		}
	}

	return aux;
}

int main()
{
	int a, b;

	std::cin >> a >> b;
	while (a != 0 || b != 0)
	{
		std::cout << elevar(a, b) << '\n';

		std::cin >> a >> b;
	}
}