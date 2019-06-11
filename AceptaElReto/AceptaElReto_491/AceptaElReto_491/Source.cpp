#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long int ways(int c, int n, int w, int &P, vector<int> &v) {
	if (n == 12 && w <= P) return 1;
	else {
		int nw = 0;
		for (int i = c; i < v.size() - 11 + n; ++i) {
			if(w + v[i] <= P) nw += ways(i+1, n + 1, w + v[i], P, v);
		}
		return nw;
	}
}

bool solve() {
	int P, N;
	cin >> P >> N;
	if (N == 0 && P == 0) return false;
	vector<int> v(N);
	vector<bool> marks(N, false);
	for (int i = 0; i < N; ++i) cin >> v[i];

	sort(v.begin(), v.end(), greater<int>());
	cout << ways(0, 0, 0, P, v) << '\n';

	return true;
}

int main() {
	while (solve());
}