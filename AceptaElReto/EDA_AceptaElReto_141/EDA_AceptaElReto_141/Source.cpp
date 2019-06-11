#include <string>
#include <set>
#include <stack>
#include <iostream>

const std::set<char> OPEN = { '(', '[', '{' };
const std::set<char> CLOSE = { ')', ']', '}' };

bool matches(char o, char c) {
	bool ret;

	if (o == '(') {
		ret = (c == ')');
	}
	else if (o == '[') {
		ret = (c == ']');
	}
	else { //o = '{'
		ret = (c == '}');
	}

	return ret;
}

int main() {
	std::string line;
	bool balanced;
	int i;

	std::getline(std::cin, line);
	while (std::cin) {
		std::stack<char> s;
		balanced = true;
		i = 0;

		while (balanced && i < line.size()) {
			if (OPEN.count(line[i]) == 1) {
				s.push(line[i]);
			}
			else if (CLOSE.count(line[i]) == 1) {
				if (s.size() != 0 && matches(s.top(), line[i])) {
					s.pop();
				}
				else {
					balanced = false;
				}
			}
			i++;
		}
		if (i == line.size() && s.size() != 0) {
			balanced = false;
		}

		if (balanced) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}

		std::getline(std::cin, line);
	}

}