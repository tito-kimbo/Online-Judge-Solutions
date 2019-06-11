#include <iostream>
#include <stack>
#include <queue>

bool resolver() {
	std::stack<int> tortitas;
	std::queue<int> aux;
	bool ret = false;
	int num, nTort;

	std::cin >> num;
	while (num != -1) {
		tortitas.push(num);
		std::cin >> num;
	}

	if (tortitas.size() != 0) {
		ret = true;
		std::cin >> num; //NUMERO DE VOLTEOS
		for (int i = 0; i < num; i++) {
			std::cin >> nTort;
			for (int j = 0; j < nTort; j++) {
				aux.push(tortitas.top());
				tortitas.pop();
			}
			for (int j = 0; j < nTort; j++) {
				tortitas.push(aux.front());
				aux.pop();
			}
		}

		std::cout << tortitas.top() << '\n';
	}
	
	return ret;
}

int main() {
	int trash;
	while (resolver());
	std::cin >> trash;
}