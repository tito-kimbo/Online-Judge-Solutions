//Eduardo Rivero Rodríguez
#include <iostream>

const int N = 10000;
//Tamaño del array estático

/*
	Se utilizará el tipo long long int para representar a los enteros (datos del problema)

	{A equiv N!=0}
	def criogenizacion(v[]: vector ent., n:entero) dev. <mayor,fMayor,menor,fMenor>:<ent.,ent.,ent.,ent.>
	{Q equiv (mayor = maxw : 0<=w<N : v[w]) y (fMayor = #w : 0<=w<N : v[w]) y (menor = minw : 0<=w<N : v[w]) y 
	(fMenor = #w : 0<=w<N : v[w]) }

	1. Diseñamos el invariante y la condición del bucle

	Invariante: (mayor = maxw : 0<=w<i : v[w]) y (fMayor = #w : 0<=w<i : mayor = v[w]) y (menor = minw : 0<=w<i : v[w]) y 
	(fMenor = #w : 0<=w<i : menor = v[w])
	Condición del bucle: i <= n - 1 

	2. Diseñamos la inicialización t. q. {A}Inicialización{I}

	Inicialización: i=1; mayor = v[0]; fMayor = 1; menor = v[0]; fMenor = 1;

	3. Diseñamos la función de cota

	n-i-1

	4. Diseñamos la funcionalidad avanzar 

	i = i+1

	5. Diseñamos la funcionalidad restablecer t. q. {I y B}Restablecer{pmd(Avanzar, Invariante)}

	casos
		v[i] = mayor {fMayor = fMayor + 1;}
		v[i] > mayor {mayor = v[i]; fMayor = 1;}
		resto {nada}
	fcasos

	casos 
		v[i] = menor {fMenor = fMenor + 1;}
		v[i] < menor {menor = v[i]; fMenor = 1;}
		resto {nada}
	fcasos

	6. Probar la terminación. Trivial pues el contador solo crece en la ejecución del bucle luego la función de cota
	llegará a un punto en que sea menor que 0.
*/

void criogenizacion(long long int v[], int n, long long int &mayor, long long int &fMayor, long long int &menor, long long int &fMenor)
{
	int i = 1;
	mayor = v[0];
	fMayor = 1;
	menor = v[0];
	fMenor = 1;

	while (i <= n - 1)
	{
		if (v[i] == mayor)
		{
			fMayor = fMayor + 1;
		}
		else if (v[i] > mayor)
		{
			mayor = v[i];
			fMayor = 1;
		}
		else {}

		if (v[i] == menor)
		{
			fMenor = fMenor + 1;
		}
		else if (v[i] < menor)
		{
			menor = v[i];
			fMenor = 1;
		}
		else {}


		i = i + 1;
	}
	
}

void lecturaDatos(long long int v[], int &n)
{
	long long int aux;
	n = 0;

	std::cin >> aux;
	while (aux != 0)
	{
		v[n] = aux;
		n++;

		std::cin >> aux;
	}
}

int main()
{
	//En base a los requerimientos del enunciado, se utilizará un array estático de tamaño 10,000
	long long int v[N], highest, lowest, timesHighest, timesLowest;
	int n, c;

	std::cin >> c;
	for (int i = 0; i < c; i++)
	{
		lecturaDatos(v, n);
		criogenizacion(v, n, highest, timesHighest, lowest, timesLowest);
		std::cout << lowest << ' ' << timesLowest << ' ' << highest << ' ' << timesHighest << '\n';
	}
}