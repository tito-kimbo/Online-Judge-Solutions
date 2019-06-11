#include <iostream>
#include <vector>
#include <math.h>



long long int readInputAndResolve(int n)
{
	long long int maxBenefit, currentBenefit, maxSum, currentSum;
	int i, aux;

	i = 0;
	maxBenefit = 0;
	currentBenefit = 0;
	maxSum = 0;
	currentSum = 0;
	aux = 0;

	while (i < n)
	{
		std::cin >> aux;

		currentSum = currentSum + aux;
		currentBenefit = currentBenefit + aux;

		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
		if (currentBenefit > maxBenefit)
		{
			maxBenefit = currentBenefit;
		}
		if (currentBenefit < 0)
		{
			currentBenefit = 0;
		}

		i = i + 1;
	}

	if (currentBenefit + maxSum > maxBenefit)
	{
		maxBenefit = currentBenefit + maxSum;
	}
	
	return maxBenefit;
}

int main()
{
	int n;
	long long int max;

	std::cin >> n;

	while (n != 0)
	{
		max = readInputAndResolve(n);
		std::cout << max << '\n';

		std::cin >> n;
	}
}