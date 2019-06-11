#include <iostream>
#include <vector>
using namespace std;

int solve() {
	int n,aux;
	vector<int> v;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}
	return v[n / 2];
}

int main() {
	int c = 1, n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "Case " << c << ": " << solve() << '\n';
		++c;
	}
}