#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ignorePunctuationAndToLowerCase(const string &s) {
	string aux="";

	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i]!=' ' && s[i] != '.' && s[i] != ',' 
			&& s[i] != '!' && s[i] != '?' && s[i]!='\'') {
			aux += tolower(s[i]);
		}
	}

	return aux;
}

string reverse(const string &s) {
	string aux = "";

	for (int i = s.size() - 1; i >= 0; --i) {
		aux += s[i];
	}
	return aux;
}

bool isPalindrome(const string &s) {
	return s == reverse(s);
}

bool solve() {
	string aux;
	
	getline(cin, aux);
	if (aux == "DONE") {
		return false;
	}

	if (isPalindrome(ignorePunctuationAndToLowerCase(aux))) {
		cout << "You won't be eaten!" << '\n';
	}
	else {
		cout << "Uh oh..\n";
	}
		
	return true;
}

int main() {
	while (solve()) {}
}