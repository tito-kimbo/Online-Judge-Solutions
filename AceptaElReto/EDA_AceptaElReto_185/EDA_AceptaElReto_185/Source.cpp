#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>

//Sets are ordered!
class DislikedElements
{
	std::map<std::string, bool> map;

	public:
		DislikedElements()
		{}

		void addList(const std::vector<std::string> & v, bool liked)
		{
			for (int i = 0; i < v.size(); i++)
			{
					map[v[i]] = liked || map[v[i]];
			}
		}

		void reset()
		{
			map.clear();
		}

		void show()
		{
			bool firstPrinted = false;

			for (auto iter = map.begin(); iter != map.end();)
			{
				if (!iter->second)
				{
					if (firstPrinted) std::cout << " ";
					std::cout << iter->first;
					firstPrinted = true;
				}
				iter++;
			}
			std::cout << '\n';
		}
};

int main()
{
	int n;
	bool l;
	DislikedElements d;
	std::vector<std::string> v;
	std::string aux;

	std::cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			v.clear();
			std::cin >> aux;
			if (aux == "SI:")
			{
				l = true;
			}
			else
			{
				l = false;
			}
			std::cin >> aux;

			while (aux != "FIN")
			{
				v.push_back(aux);
				std::cin >> aux;
			}
			d.addList(v, l);
		}

		d.show();

		d.reset();
		std::cin >> n;
	}
}