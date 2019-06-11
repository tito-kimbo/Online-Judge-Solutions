//Eduardo Rivero Rodr�guez
#include<iostream>
#include<vector>

//Primero, declaramos los predicados auxiliares esPico y esValle y definimos sus funciones asociadas
//Puesto que la primera y �ltima posici�n del vector no pueden verificar las condiciones para ser valle
//o pico, s�lo es necesario comprobar las posiciones entre 1 y N-1 (V[0...N))

/*
	{A equiv (N != 0) y (1<= n < N-1)}
	def esPico(v[0...N): vector de enteros, n: natural) dev b:bool
	{Q equiv b = ESPECIF}
*/
bool esPico(std::vector<int> & v, int n)
{
	bool b = (v.size() > 2 && v[n - 1] < v[n] && v[n + 1] < v[n]);
	return b;
}

/*
	{A equiv (N != 0) y (1<= n < N-1)}
	def esValle(v[0...N): vector de enteros, n: natural) dev b:bool
	{Q equiv b = ESPECIF}
*/
bool esValle(std::vector<int> & v, int n)
{
	bool b = (v.size() > 2 && v[n - 1] > v[n] && v[n + 1] > v[n]);
	return b;
}

/*
	{A equiv (n=N y n != 0)}
	def picosYValles(v[0...N): vector de enteros, n: nat) dev <x,y>: nat
	{Q equiv (x = #w : 1<=w<n-1 y esPico(v,w) : v[w]) y (y = #w : 1<=w<n-1 y esValle(v,w) : v[w])}

	1. Dise�amos el invariante y la condici�n del bucle a partir de la postcondici�n

	Invariante: (x= #w : 1<=w<i y esPico(v,w) : v[w]) y (y= #w : 1<=w<i y esValle(v,w) : v[w])
	Condici�n del bucle: (i < n-1)
	
	2. Dise�amos la inicializaci�n 

	Inicializaci�n: i=1; x=0; y=0;

	3. Dise�amos la funci�n de cota

	Cota: n-i-2 (Est� claro que n-i-2 >= 0 si se da B)

	4. Dise�amos las instrucciones de avanzar para que decrezca la cota

	Avanzar: i=i+1 (Obviamente hace decrecer la cota)

	5. Dise�amos las instrucciones de restablecer

	Restablecer: 
	
	casos
		esPico(v,i)  -> x=x+1
		esValle(v,i) -> y=y+1
		�esPico(v,i) y �esValle(v,i) -> nada
	fcasos

	Y con esto tenemos derivado el algoritmo al completo

	ORDEN DE COMPLEJIDAD: O(n)
*/
void picosYValles(std::vector<int> & v, int n, int & x, int & y)
{
	int i = 1;
	x = 0;
	y = 0;

	while (i < n - 1)
	{
		if (esPico(v, i))
		{
			x = x + 1;
		}
		else if (esValle(v, i))
		{
			y = y + 1;
		}
		else
		{}//NADA

		i++;
	}
}

//Lee los datos en el formato establecido por el ejercicio
void lecturaDatos(std::vector<int> & v, int & n)
{
	int aux;
	std::cin >> n;

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
	int c, n, picos, valles;

	std::cin >> c;
	for (int i = 0; i < c; i++)
	{
		lecturaDatos(v, n);
		picosYValles(v, n, picos, valles);
		std::cout << picos << ' ' << valles << '\n';
	}
}