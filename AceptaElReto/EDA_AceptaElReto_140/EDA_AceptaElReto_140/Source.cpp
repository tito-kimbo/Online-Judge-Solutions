#include <iostream>
#include <string>


int main()
{
	int sum, size;
	std::string s;
	
	std::cin >> s;
	while (s[0] != '-')
	{
		sum = 0;
		size = s.size();
		for (int i = 0; i < size-1; i++)
		{
			std::cout << s[i] << " + ";
			sum += s[i] - '0';
		}
		std::cout << s[size - 1] << " = ";
		sum += s[size - 1] - '0';
		std::cout << sum << '\n';
		
		std::cin >> s;
	}
}