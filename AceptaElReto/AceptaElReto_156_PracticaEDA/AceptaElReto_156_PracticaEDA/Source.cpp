#include <iostream>
#include <vector>
#include "math.h"

/*
Precondición: {v != null y (Exists k : k >= 1 : N = 2*k)}
fun pisosRecorridos(ini: ent, v[0...N): vector de ent) dev pisos: ent
Postcondición: {pisos = |v[0]-ini|+|v[1]-v[0]| + ( Sum i: 2<=2*i<N : |v[i+1]-v[i]| )}

Invariante: pisos = 1<=i<=N/2 y |v[0]-ini| + Sum j: 2<=2*j<i : |v[j+1]-v[j]|
Inicialización: pisos = |v[0]-ini|+|v[1]-v[0]|
Condición de bucle: 2*i < N
Función de cota: N-2*i
Restablecer: pisos = pisos + |v[i]-v[i-1]| + |v[i+1]-v[i]|
Avanzar: i = i+1;
*/

/*
int pisosRecorridos(int ini, std::vector<int> & v)
{
	int pisos, i;

	pisos = (int)abs(v[0] - ini)+(int)abs(v[1]-v[0]);
	i = 1;

	while (2*i < v.size())
	{
		pisos += (int)abs(v[2*i] - v[2*i-1]) + (int)abs(v[2*i + 1] - v[2*i]);
		i++;
	}

	return pisos;
}


void lecturaDatos(std::vector<int> & v)
{
	int aux;
	
	v.clear();
	std::cin >> aux;
	while (aux != -1)
	{
		v.push_back(aux);
		std::cin >> aux;
	}
}*/

int main()
{
	int ini, current, aux, total;
	//std::vector<int> v;

	std::cin >> ini;
	while (ini != -1)
	{
		//SOLUCION UTILIZANDO VECTOR (Verificada)
		//lecturaDatos(v);
		//std::cout << pisosRecorridos(ini, v) << '\n';

		//SOLUCION SIN UTILIZAR VECTOR
		current = ini;
		total = 0;
		std::cin >> aux;
		while (aux != -1)
		{
			total += (int)abs(aux - current);
			current = aux;

			std::cin >> aux;
		}
		std::cout << total << '\n';

		std::cin >> ini;
	}
}