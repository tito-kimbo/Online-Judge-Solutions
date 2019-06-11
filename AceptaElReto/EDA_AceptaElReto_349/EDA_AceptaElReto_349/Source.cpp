#include <iostream>
#include <string>

int notacionPolaca()
{
	std::string read;
	int ret;

	std::cin >> read;

	if (read != "+" && read != "-" && read != "*" && read != "/")
	{
		if (read[0] == '-')
		{
			ret = -(read[1] - '0');
		}
		else
		{
			ret = read[0] - '0';
		}
	}
	else
	{
		//READ IS OPERATOR
		if (read == "+")
		{
			ret = notacionPolaca() + notacionPolaca();
		}
		else if (read == "-")
		{
			ret = notacionPolaca() - notacionPolaca();
		}
		else if (read == "*")
		{
			ret = notacionPolaca() * notacionPolaca();
		}
		else
		{
			ret = notacionPolaca() / notacionPolaca();
		}
	}

	return ret;
}

int main()
{
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cout << notacionPolaca() << '\n';
	}
}