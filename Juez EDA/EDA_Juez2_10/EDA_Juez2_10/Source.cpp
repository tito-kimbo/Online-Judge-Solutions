#include <iostream>
#include <vector>
#include <algorithm>

int resolver(const int & nJefes, int profundidad) {
	int n, aux, ret;
	std::vector<int> v;

	std::cin >> n;
	ret = 0;
	for (int i = 0; i < n; i++) {
		ret += resolver(nJefes, profundidad+1);
	}
	if (n == 0 && profundidad > nJefes) ret = 1;

	return ret;
}

int main() {
	int n;

	std::cin >> n;
	while (std::cin) {
		std::cout << resolver(n, 1) << '\n';
		std::cin >> n;
	}
}