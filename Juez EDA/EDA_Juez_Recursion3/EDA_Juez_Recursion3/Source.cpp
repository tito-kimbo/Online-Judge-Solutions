#include <iostream>
#include "math.h"

/*
	PRECONDICI�N: s > 0 && esPolidivisible(s) && n = numDigitos(s)

	def poliDivisibles(long long int s, int n, int max)

	POSTCONDICI�N: Se muestran todos los polidivisibles que tengan s como ra�z y hasta max d�gitos en l�neas independientes 
*/

/*
	Puesto que el n�mero de llamadas recursivas depende del n�mero introducido, proporcionaremos una cota superior

	Esto es, dado que el n�mero introducido tendr� al menos un d�gito y en cada una de las ejecuciones ocurrir�

	- MAXIMO 5 llamadas recursivas para 2 d�gitos
	- MAXIMO 3 llamadas recursivas para 3 d�gitos
	- MAXIMO 2 llamadas recursivas para 4,5 d�gitos
	- MAXIMO 1 llamada recursiva para m�s de 5 d�gitos

	si n = maxDigitos - digitos tendremos que una cota superior es

		 {k				si n=0
	T(n)={
		 {5*T(n-1)+k'  si n>0

	Por la regla de la resta tendremos que la complejidad ser� de O(5^n).

	NOTA: Realmente la complejidad es menor. Esto se debe a que el caso de 5 llamadas recursivas solo se puede dar en el primer
	valor.
*/

void poliDivisibles(long long int s, int n, int max)
{
	long long int aux;

	if (n < max)
	{
		for (int i = 0; i < 10; i++)
		{
			aux = 10 * s + i;
			if (aux % (n+1) == 0)
			{
				std::cout << aux << '\n';
				poliDivisibles(aux, n + 1, max);
			}
		}
	}
	//Else -> nada 
}

void escribePolidivisibles(long long int root, int maxDigits) //Equivalente a resuelve
{
	int digits;

	digits = (int)floor(log10(root))+1;
	std::cout << root << '\n';
	poliDivisibles(root, digits, maxDigits);
	std::cout << "---\n";
}

int main()
{
	long long int num;
	int maximumDigits;

	std::cin >> num >> maximumDigits;
	while (std::cin)
	{
		escribePolidivisibles(num, maximumDigits);
		std::cin >> num >> maximumDigits;
	}
}