//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

/*
	El coste del algoritmo viene dado por la recursión

		 {k			  si b-a=1
	T(n)={
		 {2*T(n/2)+k' si b-a>1

	Luego por el Teorema de la División tenemos que el algoritmo es O( n^(log_2(2) ) )=O(n).
	OBS: Se utiliza el esquema DyV y no se recorre el vector salvo que sea necsario.
*/

bool esCrecP(std::vector<int> & v, int a, int b)
{
	int mid, dif;
	bool aux;

	mid = (a + b) / 2;
	if (b - a == 1)
	{
		dif = v[b]-v[a];
		aux = (0 <= dif && dif <= 1);
	}
	else
	{
		dif = v[mid + 1] - v[mid];
		aux = (0 <= dif && dif <= 1);

		if (aux)
		{
			aux = esCrecP(v, a, mid) && esCrecP(v, mid, b);
		}
	}

	return aux;
}

int main()
{
	std::vector<int> v;
	int nCasos, n, aux;
	bool resp;

	std::cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
	{
		std::cin >> n;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			std::cin >> aux;
			v.push_back(aux);
		}

		resp = esCrecP(v, 0, v.size()-1);
		if (resp)
		{
			std::cout << "SI\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}
}