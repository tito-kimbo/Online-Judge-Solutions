//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>
#include <cmath>

class polinomio
{
	public:

		polinomio(const std::vector<int> & v)
		{
			std::pair<int, int> aux;

			//Format <coefficient, exponent>
			for (int i = 0; i < v.size(); i += 2)
			{
				aux.first = v[i];
				aux.second = v[i + 1];
				addTerm(aux);
			}
			//for (std::pair<int,int> x : pol) std::cout << "(" << x.first << "," << x.second << ")\n";
		}

		void addTerm(const std::pair<int, int> & p) //Inserción ordenada, O(n^2) en el caso peor
		{
			int pos = 0;

			while (pos < pol.size() && pol[pos].second < p.second)
			{
				pos++;
			}

			if (pos == pol.size())
			{
				pol.push_back(p);
			}
			else if (pol[pos].second == p.second)
			{
				pol[pos].first += p.first;
			}
			else //We insert
			{
				pol.insert(pol.begin() + pos, p);
			}
		}

		int evaluate(int n) //O(n) respecto al tamaño del polinomio [el mayor exponente]
		{
			int aux = 0, factor = 1, j = 0;

			for (int i = 0; i < pol.size(); i++)
			{
				while (j < pol[i].second)
				{
					factor *= n;
					j++;
				}
				aux += pol[i].first*factor;
			}

			return aux;
		}

	private:
		std::vector<std::pair<int, int>> pol;
};

//La complejidad es O(n^2) por la inserción de datos
//La resolución del problema es O(n)
void resolver(const std::vector<int> & v)
{
	int evs, aux;
	polinomio p = polinomio(v);

	std::cin >> evs;
	for (int i = 0; i < evs; i++)
	{
		std::cin >> aux;
		std::cout << p.evaluate(aux);
		if (i != evs - 1)
		{
			std::cout << ' ';
		}
	}
	std::cout << '\n';
}

int main()
{
	std::vector<int> v;
	int i, j;

	std::cin >> i >> j;
	while (std::cin)
	{
		if (i != 0 || j != 0)
		{
			v.push_back(i);
			v.push_back(j);
		}
		else
		{
			resolver(v);
			v.clear();
		}
		std::cin >> i >> j;
	}

}