#include <iostream>
#include <string>
using namespace std;

bool solve() {
	string s, aux = "";
	cin >> s;
	if (!cin) return false;

	int zeroes = 0, index = 0;

	while (index < s.size() && s[index] == '0') ++index;
	while (index < s.size() && s[index] != '.') {
		aux += s[index];
		++index;
	}

	while (index < s.size()) {
		if (s[index] == '0') zeroes++;
		else {
			for (int i = 0; i < zeroes; ++i) aux += '0';
			zeroes = 0;
			aux += s[index];
		}
		++index;
	}
	if (aux.size() != 0 && aux[aux.size() - 1] == '.') aux.pop_back();
	if (aux.size() == 0) aux = "0";

	if (aux[0] == '.') cout << '0';
	cout << aux << '\n';

	return true;
}

int main(){
	while (solve());
}