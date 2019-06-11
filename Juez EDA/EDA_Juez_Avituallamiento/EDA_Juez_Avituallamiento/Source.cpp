//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

//La lectura de datos y la interpretación del resultado serán externos a la función derivada

/*
Especificación formal de la función maxSegIgual

{N >= 0}
def iguales(v[0...N]: vector enteros, a,b: naturales) dev b: boolean
{b = forall x : a<x<b : v[x]=v[a]}

{v[0...N) != null} //Equivalente a N > 0
def maxSegIgual(v[0...N): vector enteros) dev n:ent
{n = max a,b : 0<=a<b<=N y iguales(v,a,b) : b-a-1}

1. Diseñamos el invariante y la condición del bucle

Invariante:
Condición del bucle: k < N

2. Diseñamos la inicialización para que {A}Inicializacion{Q}

Inicialización:	k=1; a=0; b=1; n=0; aux=0;

3. Diseñamos la función de cota

N-k-1

4. Diseñamos la funcionalidad avanzar para hacer decrecer la función de cota

Avanzar: k=k+1

5. Diseñamos la funcionalidad restablecer para que se cumpla {I y B}Restablecer{pmd(Avanzar, Invariante)}

Restablecer:

		si v[b]=v[b-1]
			aux = aux+1; n:= n máx aux;
		sino
			aux=0; a=k-1;

		b=k;

6. Probar la terminación. Pero esto es trivial pues el bucle lo lleva un contador que solo se modifica aumentando
en la funcionalidad Avanzar.

El orden de complejidad del algoritmo es lineal O(n)
*/

int maxSegIgual(std::vector<int> & v)
{
	int k = 1, a = 0, b = 1, n = 0, aux = 0;

	while (k < v.size())
	{
		if (v[b] == v[b - 1])
		{
			aux = aux + 1;
			if (aux > n)
			{
				n = aux;
			}
		}
		else
		{
			aux = 0;
			a = b;
		}
		b = b + 1;

		k = k + 1;
	}

	return n;
}

void leerEntrada(std::vector<int> & v)
{
	int aux;

	v.clear();
	std::cin >> aux;
	while (aux != -1)
	{
		v.push_back(aux);
		std::cin >> aux;
	}
}

int main()
{
	std::vector<int> v;
	int segAvit;

	leerEntrada(v);
	while(v.size() != 0)
	{
		//Resolución
		segAvit = maxSegIgual(v);
		//Interpretación
		switch (segAvit)
		{
			case 0:
			{
				std::cout << "HOY NO COMEN\n";
			}break;
			default:
			{
				std::cout << segAvit << std::endl;
			}break;
		}

		//Lectura de datos
		leerEntrada(v);
	}
	
}