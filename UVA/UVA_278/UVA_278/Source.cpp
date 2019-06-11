#include <iostream>
#include <algorithm>
using namespace std;

int nPieces(char p, int m, int n) {
	if (p == 'r' || p == 'Q') {
		return min(m, n);
	}
	else if (p == 'k') {
		return (m*n+1) / 2;
	} else {
		return ((m+1) / 2)*((n+1) / 2);
	}
}

int main() {
	int cases, m,n;
	char p;
	cin >> cases;
	for (int i = 0; i < cases; ++i) {
		cin >> p >> m >> n;
		cout << nPieces(p, m, n) << '\n';
	}
}