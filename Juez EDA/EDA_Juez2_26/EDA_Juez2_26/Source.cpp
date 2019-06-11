#include "bintree_eda.h"
#include <utility>
#include <climits>
using namespace std;

//O(n) en el caso peor
pair<int, int> optimalLeaf(bintree<int> const& bt, int nDrags) {

	if (bt.empty()) {
		return { INT_MAX, -1 };
	}
	if (bt.root() >= 3) {
		return{nDrags, bt.root()};
	}
	else {
		pair<int, int> r, l;
		int addedDragons = 0;
		if (bt.root() == 1) addedDragons = 1;

		l = optimalLeaf(bt.left(), nDrags + addedDragons);
		r = optimalLeaf(bt.right(), nDrags + addedDragons);

		if (l.first <= r.first) {
			return l;
		}
		else {
			return r;
		}
	}
}

void resolver() {
	bintree<int> bt = leerArbol(-1);

	cout << optimalLeaf(bt, 0).second << '\n';
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resolver();
	}
}