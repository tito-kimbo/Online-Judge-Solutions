#include "bintree_eda.h"
#include <utility>
#include <algorithm>

const int SAILABLE_THRESHOLD = 3;

std::pair<int,int> sailableSections(const bintree<int> & tree) {
	std::pair<int, int> ret, aux1, aux2;
	//ret = (nSailableSections, discharge)

	if (tree.empty()) {
		ret.first = 0;
		ret.second = 0;
	} else {
		aux1 = sailableSections(tree.left());
		aux2 = sailableSections(tree.right());

		ret.first = aux1.first + aux2.first;
		
		if (tree.root() == 0) {
			ret.second = aux1.second + aux2.second;
			if (tree.left().empty() && tree.right().empty()) ret.second = 1;
		} else { //tree.root() > 0
			ret.second = std::max(0, aux1.second + aux2.second - tree.root());
		}

		if (aux1.second >= SAILABLE_THRESHOLD) {
			ret.first++;
		}
		if (aux2.second >= SAILABLE_THRESHOLD) {
			ret.first++;
		}
	}

	return ret;
}

void resolver() {
	bintree<int> tree;

	tree = leerArbol(-1);
	std::cout << sailableSections(tree).first << '\n';
}

int main() {
	int n;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		resolver();
	}
}