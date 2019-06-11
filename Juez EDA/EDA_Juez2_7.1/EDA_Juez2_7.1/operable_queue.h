#ifndef DUPLICATING_QUEUE
#define DUPLICATING_QUEUE

#include "queue_eda.h"
#include <iostream>
#include <fstream>

template <class T>
class operable_queue : public queue<T> {
	public:

		operable_queue(){}


		void duplicate() {
			//Para cada nodo, creamos otro y cambiamos los enlaces
			typename queue<T>::Nodo *actual, *nuevo;

			actual = queue<T>::prim;
			while (actual != nullptr) {
				nuevo = new (typename queue<T>::Nodo)();
				nuevo->elem = actual->elem;
				nuevo->sig = actual->sig;
				actual->sig = nuevo;
				actual = nuevo->sig;
				if (nuevo != nullptr)
				{
					this->ult = nuevo;
				}
			}

			queue<T>::nelems = 2 * queue<T>::nelems;
		}

		void reverse() {
			typename queue<T>::Nodo *actual, *aux, *next;

			aux = nullptr;
			next = nullptr;

			actual = queue<T>::prim;
			if (actual != nullptr)
			{
				next = actual->sig;
				actual->sig = nullptr;
			}
			while (actual != nullptr) {
				aux = next;
				if (aux != nullptr) {
					next = aux->sig;
					aux->sig = actual;
				}
				actual = aux;
			}
			aux = queue<T>::prim;
			queue<T>::prim = queue<T>::ult;
			queue<T>::ult = aux;
		}

		void removeEven() {

			int index, count;
			typename queue<T>::Nodo *current = nullptr, *next = nullptr;
			if (this->size() != 0) {
				current = this->prim;
				next = current->sig;
			}
			index = 2;
			count = 0;
			while (index <= (int)this->size()) {
				current->sig = next->sig;
				delete next;
				count++;
				current = current->sig;
				if (current != nullptr) next = current->sig;
				index += 2;
			}
			this->nelems -= count;
		}
};

template <class T>
inline std::ostream & operator<<(std::ostream & out, operable_queue<T> & q) {
	while (!q.empty()) {
		out << q.front();
		q.pop();
		if (!q.empty()) {
			out << ' ';
		}
	}

	return out;
}

#endif
