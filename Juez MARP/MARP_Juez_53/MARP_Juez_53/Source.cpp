#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int N, V;
	cin >> N >> V;
	vector<int> v;
	int cars = 0,aux;
	for (int i = 0; i < N; ++i) {
		/*cin >> aux;
		if (aux >= V) ++cars;
		else v.push_back(aux);*/
		cin >> aux;
		v.push_back(aux);
	}

	sort(v.begin(), v.end());
	int i = 0, j = v.size() - 1;
	while (i < j) {
		if (v[i] + v[j] >= V) {
			++i; --j; ++cars;
		} else {
			++i;
		}
	}
	cout << cars << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
}