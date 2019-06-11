#include <iostream>
#include <vector>
using namespace std;

bool solve() {
	int N, L;
	cin >> N >> L;
	if (!cin) return false;

	vector<int> v(N);
	int firstUncovered = 0, patches = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];

		//Covered all patches up to currentlyCovered
		if (v[i] > firstUncovered) {
			patches++;
			firstUncovered = v[i] + L;
		}
	}
	cout << patches << '\n';

	return true;
}

int main() {
	while (solve());
}