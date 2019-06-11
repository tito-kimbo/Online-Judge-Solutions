#include <iostream>

int numPajaritas(int a, int b)
{
	int num;

	if (a < 10 || b < 10)
	{
		num = 0;
	}
	else
	{
		if (a == b)
		{
			num = 1;
		}
		else if (a > b)
		{
			num = a / b + numPajaritas(a%b, b);
		}
		else
		{
			num = b / a + numPajaritas(a, b%a);
		}
	}

	return num;
}

int main()
{
	int a, b, number;

	std::cin >> a >> b;
	while (a != 0 || b != 0)
	{
		number = numPajaritas(a,b);
		std::cout << number << '\n';
		std::cin >> a >> b;
	}
}