#ifndef DUPLICATING_QUEUE
#define DUPLICATING_QUEUE
#include "queue_eda.h"
#include <iostream>

template <class T>
class duplicating_queue : public queue<T> {
	public:

		duplicating_queue(){}

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
};

#endif
