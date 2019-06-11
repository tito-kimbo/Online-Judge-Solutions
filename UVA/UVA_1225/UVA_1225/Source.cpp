#include <iostream>
#include <unordered_map>
using namespace std;

void solve() {
	int n, aux, digit;
	unordered_map<int, int> digits;

	for (int i = 0; i < 10; ++i) digits[i];
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		aux = i;
		while (aux != 0) {
			digit = aux % 10;
			digits[digit]++;
			aux = (aux - digit) / 10;
		}
	}
	
	bool first = true;
	for (int i = 0; i < 10; ++i) {
		if (!first) cout << ' ';
		cout << digits[i];

		first = false;
	}
	cout << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}