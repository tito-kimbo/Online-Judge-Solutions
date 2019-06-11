#include <iostream>
#include <vector>

int numLados(int n)
{
	int aux;

	if(n == 1)
	{
		aux = 4;
	}
	else
	{
		aux = 4 * n + 4*numLados(n/2);
	}

	return aux;
}

int main()
{
	int n;

	std::cin >> n;
	while (std::cin)
	{
		std::cout << numLados(n) << '\n';

		std::cin >> n;
	}
}