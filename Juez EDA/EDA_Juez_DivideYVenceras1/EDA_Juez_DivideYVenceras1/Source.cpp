//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

//PODREMOS PRESUPONER QUE NO ESTÁ EN LOS LATERALES -> SE COMPROBARÁ ANTES DE LLAMAR A LA FUNCIÓN

/*
	El coste de la función es logarítmico respecto al tamaño del vector O(logn) 
*/

char fugaDePrision(std::vector<char> & v, int a, int b)
{
	int medio = (a+b+1)/2;
	char c = 0;

	if (b-a-1 == 1) //Tamaño 1 -> 
	{
		c = v[a] + 1;
	}
	else
	{
		if (v[medio - 1] - v[a] > medio - 1 - a)
		{
			c = fugaDePrision(v,a,medio);
		}
		else if (v[b - 1] - v[medio - 1] > b - medio)
		{
			c = fugaDePrision(v, medio-1, b);
		}
	}

	return c;
}

void lecturaDatos(std::vector<char> & v, int number)
{
	char aux;

	v.clear();
	for (int i = 0; i < number; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}
}

int main()
{
	int n;
	char ini, end;
	std::vector<char> v;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		//LECTURA DATOS
		std::cin >> ini >> end;
		lecturaDatos(v, end - ini);

		//SOLUCION CASO
		if (v[v.size() - 1] - v[0] == v.size() - 1) //Caso tratado aparte
		{
			if (v[0] > ini)
			{
				std::cout << ini << '\n';
			}
			else
			{
				std::cout << end << '\n';
			}
		}
		else //Caso recursivo
		{
			std::cout << fugaDePrision(v,0,v.size()) << '\n';
		}
	}
}