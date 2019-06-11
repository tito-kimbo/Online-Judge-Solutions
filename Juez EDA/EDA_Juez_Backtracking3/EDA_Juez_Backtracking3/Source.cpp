//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>
#include <string>

const std::string NO_SOL = "SIN SOLUCION\n";
const std::string RED = "rojo";
const std::string GREEN = "verde";
const std::string BLUE = "azul";

int mostrarSoluciones(int & height, int & r, int & g, int & b, int rPlaced, int gPlaced, int bPlaced, std::vector<std::string> & sol)
{
	int numSol = 0;

	//CB
	if (height == rPlaced + gPlaced + bPlaced) //Se muestra la torre si se dan las condiciones
	{
		if (rPlaced > gPlaced + bPlaced)
		{
			for (int i = 0; i < height - 1; i++)
			{
				std::cout << sol[i] << ' ';
			}
			std::cout << sol[height - 1] << '\n';
			numSol++;
		}
	}
	else //CRec
	{
		//Prueba con azul
		if (b - bPlaced > 0)
		{
			sol.push_back(BLUE);
			numSol = numSol + mostrarSoluciones(height, r, g, b, rPlaced, gPlaced, bPlaced + 1, sol);
			sol.pop_back();
		}

		//Prueba con rojo
		if (r - rPlaced > 0)
		{
			sol.push_back(RED);
			numSol = numSol + mostrarSoluciones(height, r, g, b, rPlaced + 1, gPlaced, bPlaced, sol);
			sol.pop_back();
		}

		//Prueba con verde si se dan las condiciones
		if (g - gPlaced > 0 && sol[rPlaced + bPlaced + gPlaced - 1] != GREEN && gPlaced < bPlaced)
		{
			sol.push_back(GREEN);
			numSol = numSol + mostrarSoluciones(height, r, g, b, rPlaced, gPlaced + 1, bPlaced, sol);
			sol.pop_back();
		}
	}

	return numSol;
}

int main()
{
	int height, red, green, blue;
	std::vector<std::string> sol;

	std::cin >> height >> blue >> red >> green;
	while (height > 0) //Es innecesario hacer más comprobaciones pues la altura >= 2 para todos los demás 
	{
		if (red == 0 || height > red+green+blue)
		{
			std::cout << NO_SOL;
		}
		else
		{
			sol.push_back(RED);
			if (mostrarSoluciones(height, red, green, blue, 1, 0, 0, sol) == 0)
			{
				std::cout << NO_SOL;
			}
		}
		std::cout << '\n';

		sol.clear();
		std::cin >> height >> blue >> red >> green;
	}
}