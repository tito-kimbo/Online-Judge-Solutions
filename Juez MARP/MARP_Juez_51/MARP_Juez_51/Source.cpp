#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool solve() {
	int N;
	cin >> N;
	if (N == 0) return false;
	
	vector<int> v1(N), v2(N);
	for (int i = 0; i < N; ++i)	cin >> v1[i];
	for (int i = 0; i < N; ++i)	cin >> v2[i];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	long long int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += abs(v1[i]-v2[i]);
	}
	cout << sum << '\n';

	return true;
}

int main() {
	while (solve());
}