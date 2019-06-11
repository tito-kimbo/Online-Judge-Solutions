#include<iostream>
#include<vector>

/*
{A equiv }
def numeroAbadias(v: vector ent, n: ent) dev a: ent
{Q equiv a = #w : (\forall t : w < t : v[w] > v[t]) y (0<=w<n): w}

1. Diseñamos invariante y condición de bucle

Invariante: a = #w : (\forall t : w < t : v[w] > v[t]) y (w > i) : w
Condición de bucle: i >= 0

2. Diseñamos inicialización

Inicialización: <max,a,i>=<v[n-1],1,n-1>

3. Diseñamos función de cota

i

4. Diseñamos avanzar

i = i - 1;

5. Diseñamos restablecer

si v[i] > max entonces
	
	max = v[i];
	a++;

fsi

6. Comprobamos terminación: Trivial pues es un bucle con contador

Complejidad lineal
*/

int numeroAbadias(std::vector<int> & v, int n)
{
	int max = v[n - 1], a = 1, i = n-1;

	while (i >= 0)
	{
		if (v[i] > max)
		{
			max = v[i];
			a++;
		}

		i--;
	}

	return a;
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
	int n, a;
	
	std::cin >> n;
	while (n > 0) //Por seguridad
	{
		lecturaDatos(v, n);
		a = numeroAbadias(v, n);

		std::cout << a << '\n';

		std::cin >> n;
	}
}