#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	long long int a1, a2;
	a1 = (long long int)v[n - 1] * (long long int)v[n - 2];
	a2 = (long long int)v[0] * (long long int)v[1];
	cout << max(a1, a2) << '\n';

	return true;
}

int main() {
	while (solve());
}