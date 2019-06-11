//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

/*
	PRECONDICIÓN: {v != null, n = v.size()}
	def resolverSelección(v: vector enteros, n: entero) dev maxDif, vecesRacha, ultimosPartidos: enteros
	POSTCONDICIÓN: {}

	INVARIANTE: (maxDif = ) && (vecesRacha = #) && (ultimosPartidos = # i :  : i)
*/

//Solución en O(n), pues recorre el vector una única vez
void resolverSeleccion(std::vector<int> & v, int n, int & maxDif, int & vecesRacha, int & ultimosPartidos)
{
	int a1, b1;
	int aMax, bMax;
	int nVeces;

	a1 = 0;
	b1 = 0;
	aMax = 0;
	bMax = 0;
	nVeces = 0;
	maxDif = bMax - aMax;
	vecesRacha = nVeces;
	ultimosPartidos = v.size() - bMax;

	for (int i = 0; i < n; i++)
	{
		if (v[i] <= 0)
		{
			a1 = i + 1;
		}
		else
		{
			b1 = i + 1;
		}

		if (b1 - a1 == bMax-aMax)
		{
			nVeces++;
			aMax = a1;
			bMax = b1;
		}
		else if (b1 - a1 > bMax - aMax)
		{
			nVeces = 1;
			aMax = a1;
			bMax = b1;
		}

		maxDif = bMax - aMax;
		vecesRacha = nVeces;
		ultimosPartidos = v.size() - bMax;
	}

	//MUESTRA -> RACHAMAXIMA NUMVECESMAXRACHA PARTIDOSDESDELAULTIMARACHA
	//std::cout << (bMax - aMax) << ' ' << nVeces << ' ' << v.size() - bMax << '\n';
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
	int n, tamRacha, repRacha, ultimosPart;
	std::vector<int> v;

	std::cin >> n;
	while (std::cin)
	{
		lecturaDatos(v, n);
		resolverSeleccion(v, n, tamRacha, repRacha, ultimosPart);
		std::cout << tamRacha << ' ' << repRacha << ' ' << ultimosPart << '\n';
		std::cin >> n;
	}
}