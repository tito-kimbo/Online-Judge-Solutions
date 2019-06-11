//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

//Devuelve si la posición (i,j) está amenazada
bool isCheck(int & i, int & j, int & total, std::vector<bool> & c, std::vector<bool> & d)
{
	bool check;

	check = c[j] || d[total + j - i - 1] || d[2 * total + i + j - 1]; //Las fórmulas para las diagonales son derivadas de la numeración utilizada

	return check;
}

int resolver(int & toPlace, int queens, int towers, int currentRow, std::vector<bool> & c, std::vector<bool> & d, std::vector<bool> & forbidden)
{
	int ways = 0;
	bool f1Marked, f2Marked;

	//CB
	if (currentRow == 0)
	{
		if (towers == 1)
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
		else //queens = 1
		{
			for (int i = 0; i < toPlace; i++)
			{
				if (!isCheck(currentRow, i, toPlace, c, d) && !forbidden[toPlace + i - currentRow - 1] && !forbidden[2 * toPlace + i + currentRow - 1])
				{
					ways++;
				}
			}
		}
	}
	else //CRec
	{
		for (int i = 0; i < toPlace; i++)
		{
			//Amenazada? -> NO => Buscar soluciones
			if (!isCheck(currentRow, i, toPlace, c, d))
			{
				//PRIMERO PROBAMOS CON UNA REINA

				if (queens > 0 && !forbidden[toPlace + i - currentRow - 1] && !forbidden[2 * toPlace + i + currentRow - 1]) //Vemos que no esté en una diagonal prohibida
				{
					//Marcar
					c[i] = true;
					d[toPlace + i - currentRow - 1] = true;
					d[2 * toPlace + i + currentRow - 1] = true;

					ways = ways + resolver(toPlace, queens - 1, towers, currentRow - 1, c, d, forbidden);

					//Desmarcar
					c[i] = false;
					d[toPlace + i - currentRow - 1] = false;
					d[2 * toPlace + i + currentRow - 1] = false;
				}

				//A CONTINUACIÓN CON UNA TORRE

				if (towers > 0)
				{
					//Marcar,teniendo en cuenta si una diagonal prohibida ya está marcada
					c[i] = true;

					if (forbidden[toPlace + i - currentRow - 1])
					{
						f1Marked = true;
					}
					else
					{
						forbidden[toPlace + i - currentRow - 1] = true;
						f1Marked = false;
					}

					if (forbidden[2 * toPlace + i + currentRow - 1])
					{
						f2Marked = true;
					}
					else
					{
						forbidden[2 * toPlace + i + currentRow - 1] = true;
						f2Marked = false;
					}

					ways = ways + resolver(toPlace, queens, towers - 1, currentRow - 1, c, d, forbidden);

					//Desmarcar devolviendo los elementos a su estado original
					c[i] = false;

					if (!f1Marked)
					{
						forbidden[toPlace + i - currentRow - 1] = false;
					}

					if (!f2Marked)
					{
						forbidden[2 * toPlace + i + currentRow - 1] = false;
					}
				}

			}

		}
	}

	return ways;
}

int main()
{
	std::vector<bool> columns, diags, forbidden;
	int n, queens, towers;

	std::cin >> towers >> queens;
	while(queens > 0 || towers > 0)
	{
		n = queens + towers;

		for (int i = 0; i < n; i++)
		{
			columns.push_back(false);
		}
		for (int i = 0; i < 4 * n - 2; i++)
		{
			diags.push_back(false);
		}
		for (int i = 0; i < 4 * n - 2; i++)
		{
			forbidden.push_back(false);
		}

		std::cout << resolver(n, queens, towers, n-1, columns, diags, forbidden) << '\n';

		//Reiniciamos los vectores de diagonales y columnas
		columns.clear();
		diags.clear();
		forbidden.clear();

		std::cin >> towers >> queens;
	}
}