#include <string>
#include <iostream>
#include <list>

void resolver() {
	bool first;
	std::list<std::string> l;
	std::string aux;
	int nCamas, nPalabras, index;

	std::cin >> aux;
	while (aux != "F") {
		l.push_back(aux);
		std::cin >> aux;
	}
	std::cin >> nCamas >> nPalabras;

	if (nCamas == 0) {
		std::cout << "NADIE TIENE CAMA\n";
	}else if (nCamas >= l.size()) {
		std::cout << "TODOS TIENEN CAMA\n";
	}else {
		//WE ITERATE
		auto it = l.begin();
		index = 0;

		while (l.size() > nCamas) {
			index = (index + nPalabras - 1) % l.size();
			it = l.begin();
			for (int i = 0; i < index; i++) {
				it++;
			}
			l.erase(it);
		}

		first = true;
		for (auto v : l) {
			if (!first) {
				std::cout << ' ';
			}
			std::cout << v;
			first = false;
		}
		std::cout << '\n';
	}
}

int main() {
	int n;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		resolver();
	}
}