#include <iostream>
#include <vector>

/*
{A equiv n != 0}
def piezaQueFalta(v[0...n-1): vector enteros) dev p: entero
{Q equiv p = (sum w : 1<=w<=n : w) - (sum w : 0<=w<n-1 : v[w])}

1. Dise�amos invariante y condici�n de bucle

Invariante: (p = (sum w : i<=w<=n : w) - (sum w : 0<=w<=i : v[w]) y (0<=i<n-1)
Condici�n de bucle: i < n-1

2. Dise�amos inicializaci�n

Inicializaci�n: p = (n*(n+1))/2 //Por la f�rmula de la suma desde 1 hasta n

3. Dise�amos la funci�n de cota

C equiv n-i-2

4. Dise�amos la funcionalidad de avanzar

Avanzar: p = p - v[i]

5. No es necesario restablecer

6. Comprobamos la terminaci�n: Trivial pues es un bucle con contador

Orden de complejidad: lineal (n operaciones incluyendo la asignaci�n)
*/

int piezaQueFalta(std::vector<int> & v, int n)
{
	int pieza = (n*(n+1))/2; //La suma desde 1 hasta n

	for (int i = 0; i < n - 1; i++)
	{
		pieza -= v[i];
	}

	return pieza;
}

void lecturaDatos(std::vector<int> & v, int n)
{
	int aux; 

	v.clear();
	for (int i = 0; i < n-1; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}
}

int main()
{
	std::vector<int> v;
	int n, p;

	std::cin >> n;
	while (n > 0) //Por seguridad mejor > que !=
	{
		lecturaDatos(v, n);
		p = piezaQueFalta(v, n);

		std::cout << p << '\n';

		std::cin >> n;
	}

}