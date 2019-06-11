#include <iostream>
#include <vector>

/*
	Consideraremos el caso con una sola columna como degradado y lo trataremos aparte.

	PRECONDICIÓN: El vector tiene tamaño potencia de dos y mayor que 1. a y b marcan los
	límites del vector a comprobar y deben ser también potencias de dos.

	def resolver(v[0...N): vector de enteros, a,b,sum: enteros) dev b:bool

	POSTCONDICIÓN: b devuelve si el vector es un degradado y sus respectivas mitades también
*/

/*
		 {k		      si n= b-a = 2 (CB)
	T(n)={
		 {2*T(n/2)+k' si n= b-a > 2 (Si n > 2 será potencia de 2 por el enunciado)

	Luego por el teorema de la división la complejidad es (tras simplificar) O(n), es decir,
	el algoritmo es lineal.
*/

bool resolver(std::vector<int> & v, int a, int b, int & sum) //El parámetro "sum" por referencia sirve para reducir la complejidad
{
	bool res;
	int sumAux;

	if (b - a == 2) //Caso trivial
	{
		res = v[a] < v[b - 1];
		sum = v[a] + v[b - 1];
	}
	else
	{
		res = resolver(v, a, (a + b) / 2, sum); //Lado izquierdo
		sumAux = sum; //Suma por la izquierda
		res = res && resolver(v, (a + b) / 2, b, sum); //Lado derecho 
		res = sumAux < sum;
		sum = sumAux + sum;
	}

	return res;
}

void lecturaDatos(std::vector<std::vector<int>> & m, int & n, int & k)
{
	std::vector<int> aux;
	int intAux;

	std::cin >> n >> k;

	m.clear();
	for (int i = 0; i < n; i++)
	{
		m.push_back(aux);
		for (int j = 0; j < k; j++)
		{
			std::cin >> intAux;
			m[i].push_back(intAux);
		}
	}
}

int main()
{
	std::vector<std::vector<int>> m;
	bool degradado;
	int n, k, sum; //sum es un valor auxiliar

	lecturaDatos(m, n, k);
	while (std::cin)
	{
		degradado = true;

		//Si k = 1 se mantiene cierto
		if (k != 1)
		{
			for(int i = 0; i < n; i++)
			{ 
				degradado = degradado && resolver(m[i], 0, m[i].size(), sum);
			}
		}

		if (degradado)
		{
			std::cout << "SI\n";
		}
		else
		{
			std::cout << "NO\n";
		}

		lecturaDatos(m, n, k);
	}
}