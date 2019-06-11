#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

vector<int> VOWELS = { 'a', 'e', 'i', 'o', 'u' };

void toInterval(char & c) {
	if (c > 'z') {
		c = 'a' + (c - 'z' - 1);
		toInterval(c);
	}
	else if (c < 'a') {
		c = 'z' - ('a'-c-1);
		toInterval(c);
	}
}

string encode(string s, char key) {
	for (int i = 0; i < s.size(); ++i) {
		if (isalpha(s[i])) {
			s[i] += key;
			while ('A' > s[i] || 'Z' < s[i]) {
				if ('A' > s[i]) {
					s[i] = 'Z' - ('A' - s[i] - 1);
				}
				else if ('Z' < s[i]) {
					s[i] = 'A' + (s[i] - 'Z' - 1);
				}
			}
		}

	}
	return s;
}

bool solve() {
	char key, aux;
	string line, token;
	set<char> transf_vowels;

	cin.get(key);
	getline(cin, line);

	key = key-'p';
	token = encode("FIN", key);
	if (line == token) return false;

	for (int i = 0; i < 5; ++i) {
		aux = VOWELS[i] + key;
		toInterval(aux);
		transf_vowels.insert(aux);
	}
	int count = 0;
	for (int i = 0; i < line.size(); ++i) {
		if (transf_vowels.count( tolower(line[i])) )count++;
	}

	cout << count << '\n';

	return true;
}

int main() {
	while (solve());
}