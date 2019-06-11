#include <iostream>
#include <string>
#include <set>
#include <stack>
#include <queue>

const std::set<char> VOCALES = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

std::string transform1(std::string & s) {
	std::stack<char> st;
	std::string aux = "";

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			aux += s[i];
		}
		else {
			st.push(s[i]);
		}
	}

	while (st.size() != 0) {
		aux += st.top();
		st.pop();
	}

	return aux;
}

std::string transform2(std::string & s) {
	std::stack<char> st;
	std::string aux;

	for (int i = 0; i < s.size(); i++) {
		if (VOCALES.count(s[i]) == 1) {
			aux += s[i];
		}
		else {
			//NECESITAMOS 
			int j = i+1;
			while (j < s.size() && VOCALES.count(s[j]) == 0) {
				j++;
			} //AQUI QUEDA EL SUBSTRING [...)
			while (i < j) {
				st.push(s[i]);
				i++;
			}
			i--; //AVOIDS SKIPPING
			while (st.size() > 0) {
				aux += st.top();
				st.pop();
			}
		}
	}

	return aux;
}

bool resolver() {
	std::string msg, plainText;
	
	std::getline(std::cin, msg);
	if (!std::cin) return false;

	plainText = transform1(msg);
	plainText = transform2(plainText);

	std::cout << msg << " => " << plainText << '\n';

	return true;
}

int main() {
	while (resolver()) {};
}