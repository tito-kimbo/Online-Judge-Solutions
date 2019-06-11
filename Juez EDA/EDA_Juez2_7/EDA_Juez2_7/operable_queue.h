#ifndef DUPLICATING_QUEUE
#define DUPLICATING_QUEUE
#include "queue_eda.h"
#include <iostream>

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
};

#endif
