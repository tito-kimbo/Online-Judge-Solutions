#include "queue_eda.h"
#include <iostream>

template<class T>
class extendable_queue : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
	public:
		void add(int pos, extendable_queue & q) {
			if (pos == 0) {
				q.ult->sig = queue<T>::prim;
				queue<T>::prim = q.prim;
			}
			else {
				Nodo *n = queue<T>::prim;

				for (int i = 1; i < pos; ++i) {
					n = n->sig;
				}
				q.ult->sig = n->sig;
				n->sig = q.prim;
			}

			if (pos == queue<T>::nelems) queue<T>::ult = q.ult;
			queue<T>::nelems += q.nelems;

			//We discard the added queue
			q.prim = nullptr;
			q.ult = nullptr;
			q.nelems = 0;
		}
};

extendable_queue<int> readQueue(int size) {
	int aux;
	extendable_queue<int> q = extendable_queue<int>();

	for (int i = 0; i < size; ++i) {
		std::cin >> aux;
		q.push(aux);
	}
	return q;
}

void show(extendable_queue<int> & q) {
	bool first = true;
	while (!q.empty()) {
		if (!first) std::cout<< ' ';
		std::cout << q.front();
		q.pop();
		first = false;
	}
}

bool solve() {
	int origSize, pos, addedSize;
	extendable_queue<int> orig, added;

	std::cin >> origSize;
	if (!std::cin) return false;

	orig = readQueue(origSize);
	std::cin >> addedSize >> pos;
	added = readQueue(addedSize);

	orig.add(pos, added);
	show(orig);
	std::cout << '\n';

	//How to avoid 2 destructor calls? -> Destroy object on add
	return true;
}

int main() {
	while (solve());
}