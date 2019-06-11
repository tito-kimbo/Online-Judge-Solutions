#include<iostream>
#include <vector>

//REVISAR Y ESPECIFICAR

int resolverCaso(std::vector<int> & v, int n, int checksum)
{
	int ini = 0, fin = 0, suma = v[0], sumas = 0;

	while (fin < n)
	{
		if (suma == checksum)
		{
			suma -= v[ini];
			ini = ini + 1;
			sumas = sumas + 1;
		}
		else if (suma > checksum)
		{
			suma = suma - v[ini];
			ini = ini + 1;
		}
		else
		{
			fin = fin + 1;
			if (fin < n)
			{
				suma = suma + v[fin];
			}
		}
	}

	return sumas;
}

void lecturaDatos(std::vector<int> & v, int & n, int & checksum)
{
	char aux;
	n = 0;

	v.clear();
	std::cin >> checksum;
	std::cin.get(aux);

	while (std::cin.peek() != '\n')
	{
		std::cin.get(aux);

		if (aux != '0')
		{
			v.push_back(aux - '0');
			n = n + 1;
		}
	}

	
}

int main()
{
	std::vector<int> v;
	int n, checksum, c, sumas;

	std::cin >> c;

	for (int i = 0; i < c; i++)
	{
		lecturaDatos(v, n, checksum);
		sumas = resolverCaso(v, n, checksum);

		std::cout << sumas << '\n';
	}
}