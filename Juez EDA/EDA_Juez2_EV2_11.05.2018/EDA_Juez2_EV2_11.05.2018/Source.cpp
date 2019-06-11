//DG24, Eduardo Rivero Rodriguez
#include "bintree_eda.h"
#include <climits>
#include <algorithm>
using namespace std;

//Auxiliary class
struct triplet {
	bool isBST;
	int max;
	int min;
};

//Constante para marcar un arbol vacio
/*
Los valores asignados aseguran que no afectara a las comprobaciones posteriores
*/
const triplet EMPTY = { true, INT_MIN, INT_MAX};

//Complejidad O(N) respecto del numero de nodos del arbol
/*
Comprobamos si ambos hijos son arboles binarios de busqueda (bst) y componemos con el nodo que los une.
*/
triplet bstCheck(const bintree<int> &bt) {
	//O(1)
	if (bt.empty()) {
		return{ true, INT_MIN, INT_MAX };
	}
	//La composicion es O(1)
	else {
		triplet l, r;
		
		if (!bt.left().empty()) {
			l = bstCheck(bt.left());
		}
		else {
			l = EMPTY;
		}

		if (!bt.right().empty()) {
			r = bstCheck(bt.right());
		}
		else {
			r = EMPTY;
		}

		bool isBST = l.isBST && r.isBST && bt.root() > l.max && bt.root() < r.min;
		triplet ret = { isBST, std::max(r.max, bt.root()), std::min(l.min, bt.root())};
		return ret;
	}
}

void resolver() {
	bintree<int> bt = leerArbol(-1);
	triplet t = bstCheck(bt);
	if (t.isBST) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}


	//El siguiente codigo se puede utilizar para comprobar la correccion del algoritmo
	//min y max solo seran correctos si el arbol es un BST.
	/*
	cout << "\n\n  <<CORRECTNESS CHECK>>  \n";
	cout << "The tree is a binary search tree -> " << t.isBST << '\n';
	cout << "\nThe following are ONLY guaranteed to be correct if the tree is a BST\n";
	cout << "Minimum element: " << t.min << '\n';
	cout << "Maximum element: " << t.max << '\n';
	cout << "\n\n";
	*/
	
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		resolver();
	}
}