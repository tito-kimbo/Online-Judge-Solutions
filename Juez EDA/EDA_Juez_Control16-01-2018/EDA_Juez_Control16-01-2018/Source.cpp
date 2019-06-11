//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>
#include <climits>

//FIXED -> The matrix was calculating minimums by row instead of column (too few of them)
//FIXED -> The index for reading was incorrect

int estimar(const std::vector<std::vector<int>> & v, const std::vector<int> & mins, const int & nProd, const int & acum, int currentProd)
{
	int est;

	est = acum;
	for (int i = currentProd + 1; i < nProd; i++)
	{
		est += mins[i];
	}

	return est;
}

void resolver(const std::vector<std::vector<int>> & v, std::vector<short int> & escog, const std::vector<int> & mins,
	const int &nSup, const int & nProd, int & bestValue, int acumulatedValue, int currentProd, int marked)
{
	int aux;

	if (currentProd == nProd - 1 && marked == nProd-1)
	{
		for (int i = 0; i < nSup; i++)
		{
			if (escog[i] < 3 && acumulatedValue + v[i][currentProd] < bestValue)
			{
				bestValue = acumulatedValue + v[i][currentProd];
			}
		}
	}
	else
	{
		for (int i = 0; i < nSup; i++)
		{
			if (escog[i] < 3)
			{
				//Marco y llamo
				escog[i]++;

				aux = estimar(v, mins, nProd, acumulatedValue, currentProd);
				if (aux < bestValue)
				{
					resolver(v, escog, mins, nSup, nProd, bestValue, acumulatedValue + v[i][currentProd], currentProd + 1, marked + 1);
				}
				//Desmarco
				escog[i]--;
			}
		}
	}
}

void lecturaDatos(std::vector<std::vector<int>> & v, std::vector<short int> & escog, int &nSup, int & nProd)
{
	int aux;
	std::vector<int> auxVec;

	v.clear();
	escog.clear();

	for (int i = 0; i < nSup; i++)
	{
		v.push_back(auxVec);
		escog.push_back(0);
		for (int j = 0; j < nProd; j++)
		{
			std::cin >> aux;
			v[i].push_back(aux);
		}
	}
}

void findMins(const std::vector<std::vector<int>> & v, std::vector<int> &mins, int nProds, int nSup)
{
	int min;
	
	mins.clear();
	for (int i = 0; i < nProds; i++)
	{
		min = v[0][i];
		for (int j = 1; j < nSup; j++)
		{
			if (v[j][i] < min) { min = v[j][i]; }
		}
		mins.push_back(min);
	}
}

int main()
{
	int nSuperm, nProd, nCasos, sol;
	std::vector<std::vector<int>> prods;
	std::vector<int> colMins;
	std::vector<short int> escogSup;

	std::cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
	{
		std::cin >> nSuperm >> nProd;
		lecturaDatos(prods, escogSup, nSuperm, nProd);
		sol = INT_MAX;

		//Resolución
		findMins(prods, colMins, nProd, nSuperm);

		resolver(prods, escogSup, colMins, nSuperm, nProd, sol, 0, 0, 0);
		std::cout << sol << '\n';
	}
}