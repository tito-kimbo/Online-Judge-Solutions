#include <iostream>
#include <vector>

void resolver(std::vector<int> & v, int d, int & ini, int & fin)
{
	int maxSum, sum, n, auxIni, auxFin;

	n = 0;
	maxSum = v[0];
	sum = 0;
	ini = 0;
	fin = 0;
	auxIni = 0;
	auxFin = 0;

	while (n < d)
	{
		sum = sum + v[n];

		//Esta condición es mejorable -> Rediseñar
		if (sum > maxSum || (sum == maxSum && (fin-ini)>(auxFin-auxIni)))
		{
			ini = auxIni;
			fin = auxFin;
			maxSum = sum;
		}
		if (v[n] >= sum)
		{
			sum = v[n];
			auxIni = n;
			auxFin = n;

			if (sum > maxSum || (sum == maxSum && fin != ini))
			{
				ini = auxIni;
				fin = auxFin;
				maxSum = v[n];
			}
		}

		auxFin = auxFin + 1;
		n = n + 1;
	}

	ini = ini + 1;
	fin = fin + 1;
}

void lecturaDatos(std::vector<int> & v, int & n)
{
	int aux;

	v.clear();
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}
}

int main()
{
	std::vector<int> v;
	int n, c, ini, fin;

	std::cin >> c;
	for (int i = 0; i < c; i++)
	{
		lecturaDatos(v, n);
		resolver(v, n, ini, fin);
		std::cout << ini << ' ' << fin << '\n';
	}
}