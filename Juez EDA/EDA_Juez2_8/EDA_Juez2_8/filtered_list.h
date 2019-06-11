#ifndef FILTERED_LIST_H
#define FILTERED_LIST_H
#include "list_eda.h"

template <class T>
class filtered_list : public list<T> {

public:

	template <class Predicate>
	void remove_if(Predicate pred) {
		auto it = list<T>::begin(), aux = it;

		for (int i = 0; i < (int)this->nelems; i++) {
			it = aux;
			aux++;
			if (!pred(*it)) {
				list<T>::erase(it);
				i--;
			}
			
		}
	}
};

#endif