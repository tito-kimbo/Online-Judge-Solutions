#include <iostream>
#include <vector>
#include "bintree_eda.h"

template <class T>
int calculateFrontier(const bintree<T> & current, std::vector<T> & v) {
	int empty;

	if (current.empty()) {
		empty = 1;
	}
	else {
		empty = calculateFrontier(current.left(), v) + calculateFrontier(current.right(), v);
		if (empty == 2) v.push_back(current.root());
	}
	return empty;
}

int main() {
	int n;
	bool first;
	std::vector<int> front;
	bintree<int> tree;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		tree = leerArbol(-1);
		calculateFrontier(tree, front);

		first = true;
		for (int i = 0; i < front.size(); ++i) {
			if (!first) std::cout << ' ';
			std::cout << front[i];
			first = false;
		}
		std::cout << '\n';
		front.clear();
	}

}