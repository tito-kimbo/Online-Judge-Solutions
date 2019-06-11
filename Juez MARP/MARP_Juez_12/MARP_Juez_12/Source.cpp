//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

//O(n)
void getRange(const bintree<int> &bst,  int lower, int upper, vector<int> &range) {
	if (!bst.empty()) {
		if (bst.root() < lower) {
			getRange(bst.right(), lower, upper, range);
		}
		else if (bst.root() > upper) {
			getRange(bst.left(), lower, upper, range);
		} else {
			if(bst.root() != lower) getRange(bst.left(), lower, upper, range);
			range.push_back(bst.root());
			if (bst.root() != upper) getRange(bst.right(), lower, upper, range);
		}
	}
}

//Por el orden de los elementos podemos construir el árbol mediante DyV
//O(nlogn)
bintree<int> construyeArbol(const vector<int> &elems, int lower, int upper) {
	int mid = (lower + upper) / 2;

	if ((mid >= lower) && (mid < upper)) {
		return bintree<int>(construyeArbol(elems, lower, mid),
							elems[mid], 
							construyeArbol(elems, mid+1, upper));
	}
	else {
		return bintree<int>();
	}
}

bintree<int> leerArbol(int size) {
	vector<int> v(size);

	for (int i = 0; i < size; ++i) cin >> v[i];

	sort(v.begin(), v.end());
	return construyeArbol(v, 0, v.size());
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;

	bintree<int> bst = leerArbol(n);
	vector<int> v;
	int min, max;

	cin >> min >> max;
	getRange(bst, min, max, v);
	for (int i = 0; i < v.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << v[i];
	}
	cout << '\n';
	
	return true;
}

int main() {
	while (solve());
}