#include <iostream>
#include <string>
#include <stack>
#include <set>

std::set<char> COMMANDS = { '-', '+', '*', '3'};

bool resolver() {
	std::string input;
	std::stack<char> st, aux;

	std::getline(std::cin, input);
	if (!std::cin) return false;

	for (int i = 0; i < input.size(); i++) {
		if (COMMANDS.count(input[i]) == 1) {
			switch (input[i]) {
				case '-':
				{
					while (st.size() > 0) {
						aux.push(st.top());
						st.pop();
					}
				}break;
				case '+':
				{
					while (aux.size() > 0) {
						st.push(aux.top());
						aux.pop();
					}
				}break;
				case '*':
				{
					if (aux.size() > 0) {
						st.push(aux.top());
						aux.pop();
					}
				}break;
				case '3':
				{
					if (aux.size() != 0) {
						aux.pop();
					}
				}break;
			}
		}
		else {
			st.push(input[i]);
		}
	}

	while (st.size() > 0) {
		aux.push(st.top());
		st.pop();
	}

	while (aux.size() > 0) {
		std::cout << aux.top();
		aux.pop();
	}
	std::cout << '\n';
	
	return true;
}

int main() {
	while (resolver());
}