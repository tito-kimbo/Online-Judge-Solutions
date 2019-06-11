//Eduardo Rivero Rodríguez
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "TreeMap_AVL.h"
using namespace std;


//OJO a las rotaciones
//En inserción y en borrado
template <class Clave, class Comparador = std::less<Clave>>
class arbol_k : public map<Clave,int,Comparador> {
	typedef typename map<Clave,int,Comparador>::TreeNode TreeNode;
	using Link = TreeNode *;
	typedef typename map<Clave,int,Comparador>::clave_valor clave_valor;
protected:
	int actualizaValores(Link raiz) {
		if (raiz == nullptr) {
			return 1;
		}
		else {
			raiz->valor = actualizaValores(raiz->izq);
			actualizaValores(raiz->der);
		}
	}

	static int cuentaElems(Link &k) {
		if (k == nullptr) return 0;
		else return cuentaElems(k->dr) + cuentaElems(k->iz) + 1;
	}

	void rotaDer(Link & k2) {
		Link k1 = k2->iz;
		k2->iz = k1->dr;
		k2->cv.valor = cuentaElems(k1->dr) + 1;

		k1->dr = k2;
		k2->altura = max(this->altura(k2->iz), this->altura(k2->dr)) + 1;
		k1->altura = max(this->altura(k1->iz), this->altura(k1->dr)) + 1;
		k2 = k1;
	}

	void rotaIzq(Link & k1) {
		Link k2 = k1->dr;

		k2->cv.valor += k1->cv.valor;
		k1->dr = k2->iz;
		k2->iz = k1;
		k1->altura = max(this->altura(k1->iz), this->altura(k1->dr)) + 1;
		k2->altura = max(this->altura(k2->iz), this->altura(k2->dr)) + 1;
		k1 = k2;
	}

	void rotaIzqDer(Link & k3) {
		arbol_k::rotaIzq(k3->iz);
		arbol_k::rotaDer(k3);
	}

	void rotaDerIzq(Link & k1) {
		arbol_k::rotaDer(k1->dr);
		arbol_k::rotaIzq(k1);
	}

	void reequilibraIzq(Link & a) {
		if (this->altura(a->dr) - this->altura(a->iz) > 1) {
			if (this->altura(a->dr->iz) > this->altura(a->dr->dr))
				arbol_k::rotaDerIzq(a);
			else arbol_k::rotaIzq(a);
		}
		else a->altura = max(this->altura(a->iz), this->altura(a->dr)) + 1;
	}

	void reequilibraDer(Link & a) {
		if (this->altura(a->iz) - this->altura(a->dr) > 1) {
			if (this->altura(a->iz->dr) > this->altura(a->iz->iz))
				arbol_k::rotaIzqDer(a);
			else arbol_k::rotaDer(a);
		}
		else a->altura = max(this->altura(a->iz), this->altura(a->dr)) + 1;
	}

	Clave buscaKesimo(int k, Link &l, int accumulated) {
		int aux = l->cv.valor + accumulated;
		if (aux == k) {
			return l->cv.clave;
		}
		else if (aux < k) {
			return buscaKesimo(k, l->dr, aux);
		}
		else { //aux > k
			return buscaKesimo(k, l->iz, accumulated);
		}
	}

	Link busca(Clave const &c, Link &l) {
		if (l == nullptr)
			return nullptr;
		else if (this->menor(l->cv.clave, c))
			return  busca(c, l->dr);
		else if (this->menor(c, l->cv.clave))
			return busca(c, l->iz);
		else //cv.clave < c
			return l;
	}

	void inserta(clave_valor const& cv, Link & a) {
		if (a == nullptr) {
			a = new TreeNode(cv);
			this->nelems++;
		}
		else if (this->menor(cv.clave, a->cv.clave)) {
			a->cv.valor = a->cv.valor+1;
			inserta(cv, a->iz);
			arbol_k::reequilibraDer(a);
		}
		else if (this->menor(a->cv.clave, cv.clave)) {
			inserta(cv, a->dr);
			arbol_k::reequilibraIzq(a);
		}
		else { // la clave ya está, se actualiza el valor asociado
			a->cv.valor = cv.valor;
		}
	}

public:

	//Insertar, borrar, buscar k-ésimo
	void insert(Clave const& c) {
		if (busca(c, this->raiz) == nullptr) {
			arbol_k::inserta(clave_valor(c,1), this->raiz);
		}
	}

	Clave buscaK(int k) {
		if (k > (int)this->nelems) return NULL;
		else {
			return buscaKesimo(k, this->raiz, 0);
		}
	}
};

bool solve() {
	int n;

	cin >> n;
	if (n == 0) return false;

	arbol_k<int> ak;
	int aux;


	for (int i = 0; i < n; ++i) {
		cin >> aux;
		ak.insert(aux);
	}

	//Consultas
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aux;

		aux = ak.buscaK(aux);
		if (aux == NULL) cout << "??\n";
		else cout << aux << '\n';
	}

	cout << "----\n";
	return true;
}

int main() {
	while (solve());
}