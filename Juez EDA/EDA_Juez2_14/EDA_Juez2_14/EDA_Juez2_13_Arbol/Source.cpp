#include <algorithm>
#include <iostream>
#include <string>
#include "bintree_eda.h"

const int INT_DELIM = -1;
const std::string STR_DELIM = "#";

template <class T>
T calculateMin(const bintree<T> & t, const T & delim) {
	T min, aux;

	if (t.empty()) {
		min = delim;
	}
	else {
		min = t.root();
		aux = calculateMin(t.left(), delim);
		if (min > aux && aux != delim) min = aux;

		aux = calculateMin(t.right(), delim);
		if(min > aux && aux != delim) min = aux;
	}

	return min;
}

template <class T>
void resolver(T delim) {
	bintree<T> tree;

	tree = leerArbol(delim);
	std::cout << calculateMin(tree, delim) << '\n';
}

int main() {
	char c;

	std::cin >> c;
	while (std::cin) {
		switch (c) {
			case 'N': {
				resolver<int>(INT_DELIM);
			}break;
			case 'P': {
				resolver<std::string>(STR_DELIM);
			}
		}
		std::cin >> c;
	}
}