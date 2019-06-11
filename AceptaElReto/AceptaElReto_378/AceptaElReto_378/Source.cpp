#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

//Inserción ordenada
struct villa {
	int gastado, premios;
};

bool operator<(const villa & v1, const villa &v2) {
	return v1.gastado < v2.gastado || (v1.gastado == v2.gastado && v1.premios < v2.premios);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	villa c;
	std::vector<villa> v;
	bool justa;

	std::cin >> n;
	if (n != 0)
	{
		do
		{
			v.clear();
			justa = true;
			for (int i = 0; i < n; i++)
			{
				std::cin >> c.gastado >> c.premios;
				//Inserción
				v.push_back(c);
			}
			std::sort(v.begin(), v.end());
			

			//Es justa la lotería?
			if (v.size() != 1)
			{
				k = 0;
				while (justa && k < v.size() - 1)
				{
					if (v[k+1].gastado > v[k].gastado && v[k+1].premios <= v[k].premios)
					{
						justa = false;
					}
					k++;
				}
			}
			//En cualquier otro caso -> justa = true

			if (justa){
				std::cout << "SI\n";
			}
			else{
				std::cout << "NO\n";
			}

			std::cin >> n;
		} while (n != 0);
	}
}
