#include <iostream>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	if (!cin) return false;

	int aux, k;
	aux = 0;
	k = 0;

	while (aux < n) {
		k++;
		aux += k;
	}
	//Now find actual term
	int row, column;

	if (k % 2 == 0) {
		row = k-(aux-n);
		column = aux-n+1;
	}else{
		row = aux-n+1;
		column = k-(aux-n);
	}

	cout << "TERM " << n << " IS " << row << '/' << column << '\n';
	return true;
}

int main() {
	while (solve());
}