#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

void solve() {
	int total = 0;
	string aux;
	map<string, int> species;

	getline(cin, aux);
	while (cin && aux != "") {
		total++;
		species[aux]++;
		getline(cin, aux);
	}

	for (auto it = species.begin(); it != species.end(); it++) {
		cout << it->first << ' ' << setprecision(4) << fixed 
			<< (it->second / (float)total)*100.0f << '\n';
	}
}

int main() {
	int n;
	cin >> n;
	cin.get();
	cin.get();
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << '\n';
		solve();
	}
	system("pause");
}