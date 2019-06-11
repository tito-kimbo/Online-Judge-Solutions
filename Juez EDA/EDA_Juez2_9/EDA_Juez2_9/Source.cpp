#include <iostream>
#include <vector>
#include <algorithm>

int resolver() {
	int n, aux, current, max;
	std::vector<int> v;

	std::cin >> n;
	current = 1;
	max = 0;
	for (int i = 0; i < n; i++) {
		max = std::max(max, resolver());
	}

	return current+max;
}

int main() {
	int n;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cout << resolver() << '\n';
	}
}