#include <iostream>
#include <map>
#include <string>
#include <vector>

struct age { int a = 0; };

bool resolver() {
	int n;
	std::string name;
	std::vector<int> toPrint;
	std::map<std::string, age> m;

	std::cin >> n;
	if (n == 0) return false;

	for (int i = 0; i < n; ++i) {
		std::cin >> name;
		m[name].a++;
	}

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> name;
		m[name].a += 1;
		toPrint.push_back(m[name].a);
	}

	for (int i = 0; i < n; ++i) {
		std::cout << toPrint[i] << '\n';
	}
	std::cout << '\n';
	return true;
}

int main() {
	while (resolver());
}