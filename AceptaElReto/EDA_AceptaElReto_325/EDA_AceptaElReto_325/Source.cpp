#include <iostream>
#include <string>

std::string combinacionesHelado(int c, int v, std::string prefix) //vainilla, chocolate
{
	std::string aux;

	//Casos triviales -> (1,0) o (0,1)
	if (c == 0 && v == 1)
	{
		aux = "V";
	}
	else if (c == 1 && v == 0)
	{
		aux = "C";
	}
	else //Caso no trivial -> c > 0 y v > 0
	{

		if (c == 0)
		{
			aux = "V" + combinacionesHelado(c, v - 1, ""); //PREFIX IS IRRELEVANT HERE
		}
		else if (v == 0)
		{
			aux = "C" + combinacionesHelado(c - 1, v, ""); //PREFIX IS IRRELEVANT HERE
		}
		else
		{
			aux = "C" + combinacionesHelado(c - 1, v, prefix+"C") + " " + prefix + "V" + combinacionesHelado(c, v - 1, prefix+"V");
		}
	}

	return aux;
}

int main()
{
	int n, chocolate, vainilla;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> chocolate >> vainilla;
		std::cout << combinacionesHelado(chocolate, vainilla, "") << '\n';
	}
}