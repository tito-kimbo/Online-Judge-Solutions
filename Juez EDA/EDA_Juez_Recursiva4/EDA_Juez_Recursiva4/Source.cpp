//Eduardo Rivero Rodríguez
#include <iostream>
#include <string>
#include <vector>

/* Siendo n el tamaño del vector v, tenemos

	 {k		     si n = 1
T(n)={
	 {T(n/2)+k'n si n > 1

El tiempo de ejecución es O(nlogn).
*/

struct jugador
{
	std::string nombre;
	int canicas;
};

jugador ganador(std::vector<jugador> & v, int & n)
{
	jugador ret;
	int j;

	if (n == 1)
	{
		ret = v[0];
	}
	else
	{
		//Por cada par (j, j+1) coloca el ganador en la posición i con las canicas adecuadas.
		n = n / 2;
		j = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[j].canicas >= v[j + 1].canicas)
			{
				v[i].nombre = v[j].nombre;
				v[i].canicas = v[j].canicas + v[j + 1].canicas / 2;
			}
			else
			{
				v[i].nombre = v[j + 1].nombre;
				v[i].canicas = v[j + 1].canicas + v[j].canicas / 2;
			}
			j = j + 2;
		}

		ret = ganador(v, n);
	}

	return ret;
}

void lecturaDatos(std::vector<jugador> & v, int n)
{
	jugador aux;

	v.clear();
	for (int i = 0; i < n; i++)
	{
		std::cin >> aux.nombre;
		std::cin >> aux.canicas;
		v.push_back(aux);
	}
}

int main()
{
	int n;
	jugador sol;
	std::vector<jugador> v;

	std::cin >> n;
	while (std::cin)
	{
		lecturaDatos(v, n);
		sol = ganador(v, n);
		std::cout << sol.nombre << ' ' << sol.canicas << '\n';

		std::cin >> n;
	}
}