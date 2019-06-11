#include <iostream>
#include <vector>

/*
def mismaNacionalidad(x,y)
dev true si existe y 0<=y<n t. q. x,y\in v[y]

{A equiv n != 0}
def numParejas(v[0...n): vector enteros, n: nat) dev p: nat
{Q equiv (#x,y : no(mismaNacionalidad(x,y)) : (x,y) ) }


PRIMER BUCLE 

Invariante: sum = sumw : 0<=w<i : v[w]
Condición bucle: i < n

Inicialización: sum = 0, i = 0;
Cota: n-i-1
Avanzar: i = i + 1

Restablecer: sum = sum + v[i]

Termina por ser variable con contador
Lineal O(n)

SEGUNDO BUCLE

Invariante: p = #x,y : no(mismaNac(x,y)) y x\in v[k] y 0<=k<j
Condición bucle: j < n-1

Inicialización: j = 0; p = 0;
Restablecer: sum = sum-v[j]; prod = prod + v[j]*sum;
Avanzar: j = j+1 

Termina por ser variable con contador
Lineal O(n)

Luego el algoritmo es lineal
*/

long long int numParejas(std::vector<int> & v, int n)
{
	long long int sum = 0;
	int i = 0;

	while (i < n)
	{
		sum = sum + v[i];

		i = i + 1;
	}

	int j = 0;
	long long int p = 0;

	while (j < n - 1) //El último es trivial
	{
		sum = sum - v[j];
		p = p + v[j] * sum;

		j = j + 1;
	}

	return p;
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
	long long int p;
	int n;

	std::cin >> n;
	while (n != 0)
	{
		lecturaDatos(v, n);
		p = numParejas(v, n);

		std::cout << p << '\n';

		std::cin >> n;
	}
}