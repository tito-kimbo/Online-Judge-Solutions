#include "bintree_eda.h"
#include <utility>
using namespace std;

//O(n) respecto al numero de nodos
template <class T>
pair<bool, int> esZurdo(bintree<T> const& bt) {

	if (bt.empty()) {
		return{ true, 0 };
	}
	else if (bt.left().empty() && bt.right().empty()) {
		return { true, 1 };
	}
	else {
		pair<bool, int> l, r;

		l = esZurdo(bt.left());
		r = esZurdo(bt.right());

		return{ l.first && r.first && (l.second > r.second), l.second + r.second + 1};
	}

}

void resolver() {
	bintree<char> bt = leerArbol('.');

	if (esZurdo(bt).first) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		resolver();
	}

}