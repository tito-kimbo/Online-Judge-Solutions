#include <iostream>
#include <vector>

long long int mezclarContandoDesorden(std::vector<int> & v, int a, int medio, int b)
{
	std::vector<int> aux1, aux2;
	int index1, index2, index3;
	long long int n;

	index1 = 0;
	index2 = 0;
	index3 = a;
	n = 0;

	for (int i = a; i < medio; i++)
	{
		aux1.push_back(v[i]);
	}
	for (int i = medio; i < b; i++)
	{
		aux2.push_back(v[i]);
	}

	while (index1 < medio - a && index2 < b - medio)
	{
		if (aux1[index1] <= aux2[index2])
		{
			v[index3] = aux1[index1];
			index1++;
		}
		else
		{
			v[index3] = aux2[index2];
			n += medio - a - index1;
			index2++;
		}
		index3++;
	}

	while (index1 < medio - a)
	{
		v[index3] = aux1[index1];
		index1++;
		index3++;
	}

	while (index2 < b - medio)
	{
		v[index3] = aux2[index2];
		index2++;
		index3++;
	}

	return n;
}

long long int desordenTemporal(std::vector<int> & v, int a, int b)
{
	int medio, aux;
	long long int d;

	d = 0;
	medio = (a + b) / 2;

	if (b - a == 1)
	{
		//NO HAY DESORDEN
	}
	else if (b - a == 2)
	{
		if (v[a] > v[b - 1])
		{
			d = 1;
			aux = v[a];
			v[a] = v[b - 1];
			v[b - 1] = aux;
		}
	}
	else
	{
		d = desordenTemporal(v, a, medio) + desordenTemporal(v, medio, b);
		//Y AHORA LA MEZCLA - DEBE SER LINEAL!
		d += mezclarContandoDesorden(v, a, medio, b);
	}

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
	int n;
	std::vector<int> v;

	std::cin >> n;
	while (n != 0)
	{
		lecturaDatos(v, n);
		std::cout << desordenTemporal(v, 0, v.size()) << '\n';

		std::cin >> n;
	}
}