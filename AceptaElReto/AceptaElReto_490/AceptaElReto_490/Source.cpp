#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve() {
	int N, K;
	cin >> N >> K;
	if (!cin) return false;

	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];

	int i1, i2;
	long long int sum, M;
	i1 = 0;
	i2 = 1;
	sum = 0;

	while (i2 < K) {
		sum += v[i2]-v[i2-1];
		++i2;
	}
	M = max(sum,-sum);
	while (i2 < N) {
		sum -= v[i1+1]-v[i1];
		sum += v[i2]-v[i2-1];
		++i1;
		++i2;
		M = max(M, sum);
		M = max(M, -sum);
	}

	cout << M << '\n';
	return true;
}

int main() {
	while (solve());
}