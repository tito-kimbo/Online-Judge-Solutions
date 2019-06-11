// Eduardo Rivero Rodríguez - DG24
#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <class T>
class InvierteSegmento : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	// imprime la lista enlazada sin usar push/pop
	void print(std::ostream & o = std::cout) const {
		bool first = true;

		auto current = this->prim;
		for (int i = 0; i < (int)this->size(); ++i) {
			if (!first) o << ' ';

			o << current->elem;
			current = current->sig;
			first = false;
		}
	}

	// invierte el segmento que comienza en la posición P y tiene longitud L
	void invierte(size_t P, size_t L) {
		int i;
		Nodo *prev, *first, *current, *aux;

		prev = first = current = aux = nullptr;
		P = P - 1; //Indice real
		first = this->prim;

		for (i = 0; i < (int)P-1; ++i) {
			first = first->sig;
		}
		if (i != (int)P) { //Entonces es P-1
			prev = first;
			first = first->sig;
		}
		current = first;
		
		/*	Esquema de la ejecución del bucle principal del algoritmo
			------------------------------------------	  ------------------------------------------
			| PREV -> FIRST -> CURRENT -> AUX -> *** | -> | PREV -> FIRST -> AUX -> CURRENT -> *** |
			------------------------------------------    ------------------------------------------
			Y en el paso final se ajustan (posiblemente) los punteros de PREV y el primer elemento de la lista
		=>	-------------------------------------------------  
		=>	| PREV -> AUX -> CURRENT -> ... -> FIRST -> *** | 
		=>	-------------------------------------------------  
															  
		*/

		/*Hacemos 'swap' en los punteros
												     
			first->current->aux->X se convierte en first<-current<-aux X
												     |				 A
													 |_______________|
		*/
		for (int i = 0; i < (int)L - 1; ++i) {
			aux = first->sig;
			first->sig = aux->sig;
			aux->sig = current;
			current = aux;
		}
		if(P != 0 && L != 1) prev->sig = aux; //Si no hay elemento previo o no se debe cambiar su puntero
		else if(L != 1) this->prim = aux; //Si la sublista empieza en el primer elemento de la lista
		//FALTA ACTUALIZAR EL ÚLTIMO SI APLICA
		if (first->sig == nullptr) this->ult = first;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InvierteSegmento<T> const&
	lista) {
	lista.print(o);
	return o;
}

bool resuelveCaso() {
	int N, P, L;
	cin >> N >> P >> L;
	if (!cin)
		return false;

	InvierteSegmento<int> lista;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		lista.push(num);
	}

	if(L > 0) lista.invierte(P, L);

	cout << lista << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}