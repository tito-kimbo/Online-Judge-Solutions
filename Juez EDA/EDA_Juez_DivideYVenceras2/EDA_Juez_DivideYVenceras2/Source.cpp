//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>


/*
  Función para el coste

       { k			si n(=b-a)= 1
  T(n)={
	   { T(n/2)+k'  si n(=b-a)> 1

  Por el teorema de la división el coste es logarítmico O(logn).
  */

int encuentraMinimo(std::vector<int> & v, int a, int b)
{
	int ret, mid = (a+b+1)/2;

	if (b-a == 1)
	{
		ret = v[b-1];
	}
	else
	{
		if (v[mid] < v[mid-1])
		{
			ret = encuentraMinimo(v, mid, b);
		}
		else // MAYOR
		{
			ret = encuentraMinimo(v, a, mid);
		}
	}

	return ret;
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
	int n;

	std::cin >> n;
	while (std::cin)
	{
		lecturaDatos(v, n);
		std::cout << encuentraMinimo(v, 0, v.size()) << '\n';

		std::cin >> n;
	}
}