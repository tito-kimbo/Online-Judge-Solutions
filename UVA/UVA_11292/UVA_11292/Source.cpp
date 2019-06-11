#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Greedy solution
bool solve() {
	int n, m;

	cin >> n >> m;
	if (n == 0 && m == 0) return false;
	vector<int> dragon(n), knight(m);
	long long int price = 0;

	for (int i = 0; i < n; ++i) {
		cin >> dragon[i];
	}
	for (int j = 0; j < m; ++j) {
		cin >> knight[j];
	}
	sort(dragon.begin(), dragon.end());
	sort(knight.begin(), knight.end());

	int k = 0, i = 0;
	while( i < n && k < m) {
		if (knight[k] >= dragon[i]) {
			++i;
			price += knight[k];
		}
		++k;
	}

	if (i < n) {
		cout << "Loowater is doomed!\n";
	} else {
		cout << price << '\n';
	}
	return true;
}

int main() {
	while (solve());
}