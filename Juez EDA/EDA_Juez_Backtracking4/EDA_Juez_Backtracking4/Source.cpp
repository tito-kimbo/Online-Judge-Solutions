//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

const int UPPER_BOUND = 1000000;

//Returns the minimum of two numbers
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//Finds the minimums in a matrix
void findMinimums(std::vector<std::vector<int>> & v, std::vector<int> & minimums, int & n)
{
	int aux;

	minimums.clear();
	for (int i = 0; i < n; i++)
	{
		aux = v[i][0];
		for(int j = 1; j < n; j++)
		{ 
			aux = min(aux, v[i][j]);
		}
		minimums.push_back(aux);
	}
}

//La poda se realiza cuando no es factible la ruta -> Por ser el coste mínimo mayor que el menor hallado hasta el momento
int asignacionOptima(std::vector<std::vector<int>> & v, std::vector<bool> & cols, int & n, int & upperBound, std::vector<int> & minimums, int currentRow, int currentCost)
{
	int j, ret, minSum; 

	if (currentRow == n-1)
	{
		j = 0;
		while (!cols[j])
		{
			j++;
		}
		ret = v[currentRow][j];


		if (currentCost + ret < upperBound)
		{
			upperBound = currentCost + ret;
		}
	}
	else
	{
		ret = UPPER_BOUND;
		minSum = currentCost;

		for (int i = currentRow+1; i < n; i++)
		{
			minSum += minimums[i];
		}

		for (int i = 0; i < n; i++)
		{
			minSum += v[currentRow][i];
			if (cols[i] && (minSum < upperBound) )
			{
				//MARCADO
				cols[i] = false;

				ret = min(ret, v[currentRow][i] + asignacionOptima(v, cols, n, upperBound, minimums, currentRow + 1, v[currentRow][i]+currentCost));

				//DESMARCADO
				cols[i] = true;
			}
			minSum -= v[currentRow][i];
		}
	}

	return ret;
}

void lecturaDatos(std::vector<std::vector<int>> & v, std::vector<bool> & c, int n)
{
	std::vector<int> vAux;
	int aux;

	v.clear();
	c.clear();
	for (int i = 0; i < n; i++)
	{
		v.push_back(vAux);
		c.push_back(true);
		for (int j = 0; j < n; j++)
		{
			std::cin >> aux;
			v[i].push_back(aux);
		}
	}
}

int main()
{
	std::vector<std::vector<int>> v;
	std::vector<int> minimums;
	std::vector<bool> c;
	int n, boundary;

	std::cin >> n;
	while (n != 0)
	{
		lecturaDatos(v,c, n);
		boundary = UPPER_BOUND;
		findMinimums(v, minimums, n);
		std::cout << asignacionOptima(v, c, n, boundary, minimums, 0, 0) << '\n';

		std::cin >> n;
	}
}