#include <iostream>
#include <map>
#include <string>

bool resolver() {
	int n;
	std::string name, res;
	std::map<std::string, int> m; 

	std::cin >> n;
	std::cin.get();
	if (n == 0) return false;

	for (int i = 0; i < n; ++i) {
		std::getline(std::cin, name);			
		std::getline(std::cin, res);

		if (res == "CORRECTO") {
			m[name]++;
		}
		else { //INCORRECTO
			m[name]--;
		}
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second != 0) {
			std::cout << it->first << ", " << it->second << '\n';
		}
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resolver());
}