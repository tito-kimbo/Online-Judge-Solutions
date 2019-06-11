#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int kadane(vector<int> &v) {
	int maxEnding, maximum;

	maxEnding = -100000;
	maximum = -100000;
	for (int i = 0; i < v.size(); ++i) {
		maxEnding = max(v[i], maxEnding + v[i]);
		maximum = max(maximum, maxEnding);
	}
	return maximum;
}

bool solve() {
	int N, maxSum;

	cin >> N;
	if (N == 0) return false;
	vector<int> v(N);

	for (int i = 0; i < N; ++i) cin >> v[i];
	maxSum = kadane(v);

	if (maxSum <= 0) {
		cout << "Losing streak.\n";
	} else {
		cout << "The maximum winning streak is " << maxSum << ".\n";
	}

	return true;
}

int main() {
	while (solve());
}