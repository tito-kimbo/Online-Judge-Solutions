#include <iostream>
#include <vector>
#include <cmath>

/*
{A}
def diaCerrajero(v:vector ent n: nat) dev d: nat
{Q equiv d = min w : (w = exists k : (sum x : 0<=x<k : v[x] - sum y : k<=y<n : v[y]) ) : w}

BUCLE 1: Calcula la suma de todos (la guarda en y)
BUCLE 2: Recorre de izquierda a derecha guardando resultados parciales
BUCLE 3: Halla el mínimo del vector auxiliar

Solucíón lineal (2n) probablemente haya una mejor
*/

//Posible solución -> sumar todo y comparar con la mitad de la suma

int diaCerrajero(std::vector<int> & v, int n)
{
	//std::vector<int> aux;
	int d, x, y, i, sumAux, min;

	y = 0;
	i = 0;

	while (i < n)
	{
		y = y + v[i];
		i = i + 1;
	}

	x = 0;
	i = 1;
	d = 0;

	min = (abs(x - y));
	y = y - v[0];
	x = x + v[0];

	while (i < n)
	{
		sumAux = abs(x - y);
		//std::cout << "SUMA AUX [" << i << "] : " << sumAux << '\n';

		if (sumAux < min)
		{
			d = i;
			min = sumAux;
		}

		y = y - v[i];
		x = x + v[i];

		i = i + 1;
	}

	/*
	while (i < n)
	{
		if (aux[i] < aux[d])
		{
			d = i;
		}
		
		i = i + 1;
	}*/

	return d;
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
	int n, d;

	std::cin >> n;
	while (n > 0)
	{
		lecturaDatos(v, n);
		d = diaCerrajero(v, n);

		std::cout << d << '\n';

		std::cin >> n;
	}
}