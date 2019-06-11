#include <iostream>
#include <vector>

//APLIC. DE BACKTRACKING - e representa el último valor
void escribeCrecientePorLosPelosDivertidos(std::vector<int> & v, int & n, int & d, int e, int currentLength, int rep)
{

	if (currentLength == n)
	{
		for (int i = 0; i < n-1; i++)
		{
			std::cout << v[i] << ' ';
		}
		std::cout << v[n-1] << '\n';
	}
	else //currentLength < n
	{
		//Dos posibilidades: Añadir e (solo si rep < 3), añadir e+1
		if (rep < d)
		{
			v.push_back(e);
			escribeCrecientePorLosPelosDivertidos(v, n, d, e, currentLength + 1, rep + 1);
			v.pop_back();
		}

		v.push_back(e + 1);
		escribeCrecientePorLosPelosDivertidos(v, n, d, e+1, currentLength + 1, 1);
		v.pop_back();
	}
}

int main()
{
	int nCasos, n, d, e;
	std::vector<int> v;

	std::cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
	{
		std::cin >> n >> d >> e;
		v.clear();
		v.push_back(e);
		escribeCrecientePorLosPelosDivertidos(v, n, d, e, 1, 1);
	}
}