#include <iostream>
using namespace std;

int resolver() {
	int n, max = 0, aux;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		if (aux > max) max = aux;
	}
	return max;
}

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i) {
		cout << "Case " << i+1 << ": " << resolver() << '\n';
	}
}