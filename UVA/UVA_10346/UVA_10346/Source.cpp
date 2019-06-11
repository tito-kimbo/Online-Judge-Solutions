#include <iostream>
using namespace std;

int canCraft(int n, int k) {
	int total = (n / k), aux = n%k+n/k;
	if (aux >= k) {
		total += canCraft(aux, k);
	}
	return total;
}

bool solve() {
	int n, k;

	cin >> n >> k;
	if (!cin) return false;
	cout << n+canCraft(n, k) << '\n';

	return true;
}

int main() {
	while (solve());
}