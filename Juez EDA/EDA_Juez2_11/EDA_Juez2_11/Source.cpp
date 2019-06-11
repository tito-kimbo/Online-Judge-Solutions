#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> resolver() {
	char c;
	int countEmpty;
	std::vector<int> v, aux;
	//Format: [nodes] [leafs] [height]

	std::cin >> c;
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	countEmpty = 0;
	
	if(c == '*'){
		v[0]++;
		for (int i = 0; i < 2; ++i) {
			aux = resolver();
			if (aux[0] == 0 && aux[1] == 0 && aux[2] == 0) {
				countEmpty++;
			}
			v[0] += aux[0];
			v[1] += aux[1];
			v[2] = std::max(v[2], aux[2]);
		}
		v[2]++;
	}
	
	if (countEmpty == 2) {
		v[1]++;
	}

	return v;
}


int main() {
	int n;
	std::vector<int> sol;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		sol = resolver();
		std::cout << sol[0] << ' ' << sol[1] << ' ' << sol[2] << '\n';
		sol.clear();
	}
}