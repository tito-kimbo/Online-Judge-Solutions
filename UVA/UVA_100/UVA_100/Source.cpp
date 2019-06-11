#include <iostream>
#include <algorithm>
using namespace std;

int cicleLength(int n) {
	int i = 1;
	while (n != 1) {
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
		++i;
	}
	return i;
}

bool solve() {
	long long int i, j;
	cin >> i >> j;
	if (!cin) return false;
	int m = 0;
	for (long long int k = min(i,j); k <= max(i,j); ++k) {
		m = max(m, cicleLength(k));
	}
	cout << i << ' ' << j << ' ' << m << '\n';
	return true;
}

int main() {
	while (solve());
}