#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solve(bool &first) {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

	int maxFreq = 0;
	map<int, int> freq;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			freq[(i + 1) + (j + 1)]++;
			maxFreq = max(maxFreq, freq[(i + 1) + (j + 1)]);
		}
	}

	if (!first) cout << '\n';
	else first = false;
	for (auto it = freq.begin(); it != freq.end(); it++) {
		if (it->second == maxFreq) {
			cout << it->first << '\n';
		}
	}

	return true;
}

int main() {
	bool first = true;
	while (solve(first));
}