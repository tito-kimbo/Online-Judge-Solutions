#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
using namespace std;

void resolver(int n) {
	int line = 1;
	map<string, set<int>> m;
	string s, word;

	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		istringstream is(s);
		while (is) {
			is >> word;

			for (int i = 0; i < word.size(); ++i) {
				word[i] = tolower(word[i]);
			}
			if (word.size() > 2 && m[word].count(line) == 0) {
				m[word].insert(line);
			}
		}
		line++;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first;
		for (auto sit = it->second.begin(); sit != it->second.end(); sit++) {
			cout << ' ' << *sit;
		}
		cout << '\n';
	}
	cout << "----\n";
}

int main() {
	int n;

	cin >> n;
	while (n != 0) {
		cin.get();
		resolver(n);
		cin >> n;
	}
}