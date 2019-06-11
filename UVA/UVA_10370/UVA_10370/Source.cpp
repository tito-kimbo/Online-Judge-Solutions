#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	double avg = 0.0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		avg += v[i];
	}
	avg /= (double)n;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] > avg) count++;
	}
	cout << fixed << setprecision(3) << 100 * (count / (double)n) << "%\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}