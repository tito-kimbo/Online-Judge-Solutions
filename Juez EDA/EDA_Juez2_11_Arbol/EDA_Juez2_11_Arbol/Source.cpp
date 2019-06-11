#include <vector>
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template <typename T>
std::vector<int> doCalculations(const bintree<T> & t) {
	std::vector<int> values,auxLeft, auxRight; //[nodes] [leaves] [height]
	values.push_back(0);
	values.push_back(0);
	values.push_back(0);

	if (!t.empty()) {
		values[0]++;
		auxLeft = doCalculations(t.left());
		auxRight = doCalculations(t.right());
		if (t.left().empty() && t.right().empty()) values[1]++;

		values[0] += auxLeft[0] + auxRight[0];
		values[1] += auxLeft[1] + auxRight[1];
		values[2] = std::max(auxLeft[2], auxRight[2])+1;

	}

	return values;
}

template <typename T>
int calculateNodes(const bintree<T> & t) {
	int nodes;

	if (t.empty()) nodes = 0;
	else {
		nodes = calculateNodes(t.left()) + calculateNodes(t.right()) + 1;
	}
	
	return nodes;
}

template <typename T>
int calculateLeaves(const bintree<T> & t) {
	
	if (t.empty()) {
		return 0;
	}else {
		if (t.left().empty() && t.right().empty()) {
			return 1;
		}
		else {
			return calculateLeaves(t.left()) + calculateLeaves(t.right());
		}
	}
}

template <typename T>
int calculateHeight(const bintree<T> & t) {
	int hLeft, hRight;
	if (t.empty()) {
		return 0;
	}
	else {
		hRight = calculateHeight(t.right());
		hLeft = calculateHeight(t.left());
		return std::max(hRight, hLeft) + 1;
	}
}

void resolver() {
	bintree<char> tree;
	std::vector<int> sol;
	tree = leerArbol('.');

	sol = doCalculations(tree);
	std::cout << sol[0] << ' ' << sol[1] << ' ' << sol[2] << '\n';
}

int main() {
	int n;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		resolver();
	}
}