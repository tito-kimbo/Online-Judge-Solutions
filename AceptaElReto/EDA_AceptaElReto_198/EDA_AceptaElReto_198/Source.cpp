#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <exception>
#include <stdexcept>

const std::set<char> OPERATORS = {'*', '+', '/', '-'};

long long int operate(char op, long long int op1, long long int op2) {
	switch (op) {
		case '+':
			return op1 + op2;
		case '*':
			return op1*op2;
		case '/':
			if (op2 == 0) {
				throw std::domain_error("Divide by 0");
			}
			return op1 / op2;
		case '-':
			return op1 - op2;
	}
}

bool resolver()
{
	std::stack<long long int> pila;
	std::queue<long long int> cola;
	std::string resPila, resCola, aux;
	int op1, op2;

	//Lectura datos
	std::getline(std::cin, aux);
	if (!std::cin) return false;

	//Evaluacion pila
	try {
		for (char c : aux) {
			if (OPERATORS.count(c)) {
				//EXTRAEMOS LOS OPERANDOS
				op2 = pila.top();
				pila.pop();
				op1 = pila.top();
				pila.pop();
				pila.push(operate(c, op1, op2));
			}
			else {
				pila.push(c - '0');
			}
		}
		resPila = std::to_string(pila.top());
	}
	catch (...) {
		resPila = "ERROR";
	}
	//Evaluacion cola
	try {
		for (char c : aux) {
			if (OPERATORS.count(c)) {
				//EXTRAEMOS LOS OPERANDOS
				op2 = cola.front();
				cola.pop();
				op1 = cola.front();
				cola.pop();
				cola.push(operate(c, op1, op2));
			}
			else {
				cola.push(c - '0');
			}
		}
		resCola = std::to_string(cola.front());
	}
	catch (...) {
		resCola = "ERROR";
	}


	if (resPila == resCola) {
		std::cout << resPila << " = " << resCola << '\n';
	}
	else {
		std::cout << resPila << " != " << resCola << '\n';
	}

	return true;
}

int main() {
	while (resolver()) {};
}