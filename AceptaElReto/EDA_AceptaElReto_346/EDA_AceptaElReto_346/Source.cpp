#include <iostream>
#include <vector>
#include <math.h>

int resolverCaso2(std::vector<int> & v, int n, int a)
{
	int ini, end, diff, maxNum;

	ini = 0;
	end = 0;
	maxNum = 1;

	while (end < n)
	{
		diff = v[end] - v[ini];
		if (diff < a)
		{
			maxNum = fmax(maxNum, end - ini + 1);
			end = end + 1;
		}
		else //diff > a
		{
			ini = ini + 1;
		}
	}

	return maxNum;
}

void lecturaDatos(std::vector<int> & v, int n)
{
	int aux;

	v.clear();
	for (int i = 0; i < n; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}
}

int main()
{
	std::vector<int> v;
	int n, a, maxNum;

	std::cin >> n >> a;
	while (n != 0 || a != 0)
	{
		lecturaDatos(v, n);
		maxNum = resolverCaso2(v, n, a);

		std::cout << maxNum << '\n';
		std::cin >> n >> a;
	}

}