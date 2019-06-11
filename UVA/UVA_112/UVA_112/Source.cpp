#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

struct comp {
	bool operator()(char &c1, char &c2) {
		return (tolower(c1) < tolower(c2)) || (tolower(c1) == tolower(c2) && c1 < c2);
	}
};

void solve() {
	string word, aux;

	cin >> word;
	sort(word.begin(), word.end(), comp());
	aux = word;
	do {
		cout << aux << '\n';
		next_permutation(aux.begin(), aux.end(), comp());
	} while (aux != word);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}