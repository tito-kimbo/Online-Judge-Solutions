#include <iostream>
using namespace std;

void solve() {
	long long int v1, v2;

	cin >> v1 >> v2;

	long long int x, y, aux;

	x = (v1 + v2) / 2;
	y = v1 - x;

	if (y > x) {
		aux = x;
		x = y;
		y = aux;
	}
	if (x < 0 || y < 0 || v2 < 0 || v1 < 0 || (v1+v2)%2 != 0) {
		cout << "impossible\n";
	}
	else {
		cout << x << ' ' << y << '\n';
	}

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}