//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

//Devuelve si la posición (i,j) está amenazada
bool isCheck(int & i, int & j, int & total, std::vector<bool> & c, std::vector<bool> & d)
{
	bool check;

	check = c[j] || d[total+j-i-1] || d[2*total+i+j-1]; //Las fórmulas para las diagonales son derivadas de la numeración utilizada

	return check;
}

int resolver(int & toPlace, int currentRow, std::vector<bool> & c, std::vector<bool> & d)
{
	int ways = 0;

	//CB
	if (currentRow == 0)
	{
		for (int i = 0; i < toPlace; i++)
		{
			//Amenazada? -> NO => 1 solución más
			if (!isCheck(currentRow, i, toPlace, c, d))
			{
				ways++;
			}
		}
	}
	else //CRec
	{
		for (int i = 0; i < toPlace; i++)
		{
			//Amenazada? -> NO => Buscar soluciones
			if (!isCheck(currentRow,i, toPlace, c, d))
			{
				//Marcar
				c[i] = true;
				d[toPlace + i - currentRow-1] = true;
				d[2 * toPlace + i + currentRow-1] = true;

				ways = ways + resolver(toPlace, currentRow - 1, c, d);
				//Descarcar
				c[i] = false;
				d[toPlace + i - currentRow-1] = false;
				d[2 * toPlace + i + currentRow-1] = false;

			}

		}
	}

	return ways;
}

int main()
{
	std::vector<bool> columns, diags;
	int casos, n;

	std::cin >> casos;
	for (int i = 0; i < casos; i++)
	{
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			columns.push_back(false);
		}
		for (int i = 0; i < 4*n-2; i++)
		{
			diags.push_back(false);
		}

		std::cout << resolver(n, n-1, columns, diags) << '\n';

		//Reiniciamos los vectores de diagonales y columnas
		columns.clear();
		diags.clear();
	}
}