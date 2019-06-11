#include <iostream>
#include "checkML.h"
#include "operable_queue.h"

void resolver(int & aux) {
	operable_queue<int> q;

	while (aux != 0) {
		q.push(aux);
		std::cin >> aux;
	}

	q.reverse();
	while (!q.empty()) {
		std::cout << q.front();
		q.pop();
		if (!q.empty()) {
			std::cout << ' ';
		}
	}
	std::cout << '\n';
}

int main() {
#ifndef DOMJUDGE
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	int aux;

	std::cin >> aux;
	while (std::cin) {
		resolver(aux);
		std::cin >> aux;
	}
}