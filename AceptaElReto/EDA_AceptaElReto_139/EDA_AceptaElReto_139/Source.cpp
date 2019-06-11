#include <iostream>
#include <set>
#include <cmath>

class Num 
{
	int n, length;
	std::set<int> previous;

	public:
		Num() {}
		Num(int num)
		{
			n = num;
			length = floor(log10(num))+1;
			previous.insert(n);
			isCubeFinite();
		}

	private:
		void isCubeFinite()
		{
			int s = sumOfCubes();
			
			std::cout << n;

			if (s == 1 && n != 1)
			{
				std::cout << " - 1 -> cubifinito.\n";
			}
			else if (s == 1)
			{
				std::cout << " -> cubifinito.\n";
			}
			else if (previous.count(s) == 1)
			{
				std::cout << " - " << s << " -> no cubifinito.\n";
			}
			else
			{
				std::cout << " - ";
				previous.insert(s);
				n = s;
				length = floor(log10(s)) + 1;
				isCubeFinite();
			}
		}
		
		int sumOfCubes()
		{
			int sum = 0, num = n, factor = pow(10,length), aux;

			for (int i = length; i>0; i--)
			{
				factor /= 10;
				aux = num / factor;
				num -= aux*factor;
				aux = aux*aux*aux;
				sum += aux;

				//std::cout << factor << " - " << aux << " -  " << sum << "\n";
			}

			return sum;
		}

};

int main()
{
	Num n;
	int number;

	std::cin >> number;
	while (number != 0)
	{
		n = Num(number);

		std::cin >> number;
	}
}