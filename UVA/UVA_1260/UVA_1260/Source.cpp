#include <iostream>
#include <vector>
using namespace std;

int solve() {
	int n, aux, sum;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	sum = 0;
	for (int i = 1; i < v.size(); ++i) {
		aux = 0;
		for (int j = 0; j < i; ++j) {
			if (v[j] <= v[i]) aux++;
		}
		sum += aux;
	}
	return sum;
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << solve() << '\n';
	}
}