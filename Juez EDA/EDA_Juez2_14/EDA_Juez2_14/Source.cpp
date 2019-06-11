#include "bintree_eda.h"
#include <utility>
#include <algorithm>

std::pair<int, int> operator+(const std::pair<int, int> & p1, const std::pair<int, int> & p2) {
	std::pair<int, int> aux;

	aux.first = p1.first + p2.first;
	aux.second = std::max(p1.second, p2.second);

	return aux;
}

std::pair<int, int> nRescueTeams(const bintree<int> & tree) {
	std::pair<int, int> ret;
	//ret = (nEquipos, nExcursionistas)

	if (tree.empty()) {
		ret.first = ret.second = 0;
	} else {
		ret = nRescueTeams(tree.left()) + nRescueTeams(tree.right());
		if (ret.first == 0 && tree.root() != 0) ret.first++;
		ret.second += tree.root();
	}

	return ret;
}

void resolver() {
	std::pair<int, int> aux;
	bintree<int> tree;
	tree = leerArbol(-1);
	aux = nRescueTeams(tree);
	std::cout << aux.first << ' ' << aux.second << '\n';
}

int main() {
	int n;

	std::cin >> n;
	for (int i = 0; i<n; ++i) {
		resolver();
	}
}