//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

/* IMPLEMENTACIÓN DE MERGESORT CON CUENTA

		 { k	si n = 1 o n = 2
	T(n)={
		 { 2T(n/2)+k'n si n > 2
	
   Donde n = b-a. El coste del algoritmo es, por el Teorema de la División, O(nlogn). 
*/

//Mezcla dos subvectores [a1...a2) [a2...a3) contando el número de swaps.
//factor es una variable que reajusta la cuenta de swaps en función de los ya realizados.
int mezclarContando(std::vector<int> & v, int a1, int a2, int a3)
{
	int n, index1, index2, index3, factor;
	std::vector<int> vector1, vector2;

	n = 0;
	factor = 0;
	index1 = 0;
	index2 = 0;
	index3 = a1;

	for (int i = a1; i < a2; i++)
	{
		vector1.push_back(v[i]);
	}
	for (int i = a2; i < a3; i++)
	{
		vector2.push_back(v[i]);
	}

	while(index1 < a2-a1 && index2 < a3-a2)
	{
		if (vector1[index1] < vector2[index2])
		{
			v[index3] = vector1[index1];
			index1++;
		}
		else
		{
			v[index3] = vector2[index2];
			n += (a2+index2) - (a1+index1) - factor;

			factor++;
			index2++;
		}
		index3++;
	}

	while (index1 < a2-a1)
	{
		v[index3] = vector1[index1];
		index3++;
		index1++;
	}

	while (index2 < a3-a2)
	{
		v[index3] = vector2[index2];
		index3++;
		index2++;
	}


	return n;
}

int resolverCaso(std::vector<int> & v, int a, int b)
{
	int medio = (a+b)/2;
	int n = 0, aux;

	if (b - a == 1)
	{
		//FIN -- Ordenado
	}
	else if (b - a == 2)
	{
		if (v[a] > v[b-1])
		{
			aux = v[a];
			v[a] = v[b-1];
			v[b-1] = aux;
			n = 1;
		}
	}
	else
	{
		//CASO RECURISVO: MEZCLA - DEBE SER LINEAL
		n = resolverCaso(v, a, medio) + resolverCaso(v, medio, b) + mezclarContando(v, a, medio, b);
	}

	return n;
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
	while (std::cin)
	{
		lecturaDatos(v, n);
		std::cout << resolverCaso(v, 0, v.size()) << '\n';
		std::cin >> n;
	}
}