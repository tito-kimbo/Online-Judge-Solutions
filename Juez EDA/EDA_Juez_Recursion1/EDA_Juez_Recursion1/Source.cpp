#include <iostream>
#include <vector>

/*
	Consideraremos el caso v.size() = 1 como "true" y lo trataremos aparte

	PRECONDICIÓN: El vector tiene tamaño mayor o igual que 2 y dicho tamaño es potencia de 2. Además a y b están en el rango del vector
	y son a su vez potencias de 2

	def resolverRecursivo(v[0...N): de enteros a,b: enteros) dev b:bool

	POSTCONDICIÓN: b comprueba (en el vevtor) si el máximo de la mitad izquierda es menor o igual que el de
	la mitad zquierda y	si el mínimo de la mitad izquierda es menor o igual que el de la derecha
*/

/*
	Análisis de la complejidad

		   { k					si n=b-a == 2
	T(n) = {
		   { 2*T(n/2)+k'		si n=b-a > 2

	Luego por el Teorema de la división la complejidad es O(n^log2(2))=O(n^1)=O(n) lineal
*/

bool resolverRecursivo(std::vector<int> & v, int a, int b)
{
	bool res;
	
	if (b - a == 2) //Caso trivial
	{
		res = v[a] <= v[b - 1];
	}
	else //b-a > 2 y potencia de 2 ==> Redividimos el vector
	{
		res = resolverRecursivo(v, a, (a+b) / 2) && resolverRecursivo(v, (a+b) / 2, b) && (v[a] <= v[(a+b)/2]) && (v[((a+b)/2)-1] <= v[b-1]);
	}
	
	//En este caso la recursión es múltiple (pues se hacen 2 llamadas recursivas en cada caso no trivial)
	return res;
}

void lecturaDatos(std::vector<int> & v)
{
	int aux;
	v.clear();

	std::cin >> aux;
	while (aux != 0)
	{
		v.push_back(aux);
		std::cin >> aux;
	}
}

int main()
{
	std::vector<int> v;
	bool parcOrdenado;


	lecturaDatos(v);
	while (v.size() != 0)
	{
		if (v.size() == 1)
		{
			parcOrdenado = true;
		}
		else
		{
			parcOrdenado = resolverRecursivo(v, 0, v.size());
		}

		if (parcOrdenado)
		{
			std::cout << "SI\n";
		}
		else
		{
			std::cout << "NO\n";
		}

		lecturaDatos(v);
	}
}