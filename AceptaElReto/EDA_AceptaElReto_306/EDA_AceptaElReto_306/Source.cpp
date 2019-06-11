#include <iostream>
#include <vector>

/*
	(0 1)^n
	(1 1)
*/

const int FACTOR = 46337;

std::vector<long long int> operator*(std::vector<long long int> & v1, std::vector<long long int> & v2)
{
	std::vector<long long int> aux;

	aux.push_back( (v1[0] * v2[0] + v1[1] * v2[1])%FACTOR );
	aux.push_back( (v1[0] * v2[2] + v1[1] * v2[3])%FACTOR );
	aux.push_back((v1[2] * v2[0] + v1[3] * v2[1]) % FACTOR);
	aux.push_back((v1[2] * v2[2] + v1[3] * v2[3]) % FACTOR);

	return aux;
}

std::vector<long long int> fibonacci(int n)
{
	std::vector<long long int> aux;
	
	switch (n)
	{
		case 1:
		{
			aux.push_back(0);
			aux.push_back(1);
			aux.push_back(1);
			aux.push_back(1);
		}break;
		case 2:
		{
			aux.push_back(1);
			aux.push_back(1);
			aux.push_back(1);
			aux.push_back(2);
		}break;
		default:
		{
			aux = fibonacci(n / 2);
			
			if (n % 2 == 0)
			{
				aux = aux*aux;
			}
			else
			{
				std::vector<long long int> aux2 = fibonacci(1);
				aux = (aux*aux);
				aux = aux*aux2;
			}
		}break;
	}

	return aux;
}

int main()
{
	int n;

	std::cin >> n;
	while (n != 0)
	{
		std::cout << fibonacci(n)[1] << '\n';

		std::cin >> n;
	}
}