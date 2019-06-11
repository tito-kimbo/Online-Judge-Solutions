#include "bintree_eda.h"
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
//DFS vs BFS
/*
DFS: Necesita determinar la coincidencia más alta => Explorar todas las ramas
BFS: Necesita determinar las ramas no accesibles
*/

bool accesible(const int & r) {
	int cota = (int)sqrt(r), i;
	//Es r primo? Una solución más eficiente es aplicar Programación Dinámica a la criba de Eratóstenes
	//almacenando los primos y con marcadores hasta la cota
	bool isPrime = (r % 2 != 0);

	i = 3;
	while (isPrime && i <= cota) {
		isPrime = (r % i != 0);
		i += 2;
	}
	return !isPrime;
}

std::pair<int, int> getClosestM7(const bintree<int> & tree) {
	std::pair<int, int> ret, aux1, aux2;
	//ret = (num, depth)

	if (tree.empty() || !accesible(tree.root())) {
		ret.first = -1;
		ret.second = INT_MAX;
	} else {
		if (tree.root() % 7 == 0) {
			ret.first = tree.root();
			ret.second = 1;
		} else {
			aux1 = getClosestM7(tree.left());
			aux2 = getClosestM7(tree.right());

			if (aux1.second <= aux2.second) ret = aux1;
			else ret = aux2;
			if (ret.second != INT_MAX) ret.second++;
		}
	}

	return ret;
}

void resolver() {
	bintree<int> tree = leerArbol(-1);
	std::pair<int, int> sol = getClosestM7(tree);

	if (sol.first == -1) {
		std::cout << "NO HAY\n";
	} else {
		std::cout << sol.first << ' ' << sol.second << '\n';
	}
}

int main() {
	int n;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		resolver();
	}
}