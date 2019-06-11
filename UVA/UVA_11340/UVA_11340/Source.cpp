#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void solve() {
	int nChars, nLines, sum;
	unordered_map<char, int> value;

	cin >> nChars;
	char aux;
	int val;
	for (int i = 0; i < nChars; ++i) {
		cin >> aux >> val;
		value[aux] = val;
	}

	cin >> nLines;
	cin.get();
	
	string line;

	sum = 0;
	for (int i = 0; i < nLines; ++i) {
		getline(cin, line);
		for (int j = 0; j < line.size(); ++j) {
			sum += value[line[j]];
		}
	}

	int dollars, cents;
	
	dollars = sum / 100;
	cents = sum % 100;

	cout << dollars << '.';
	if (cents < 10) cout << '0';
	cout << cents << "$\n";
	
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}