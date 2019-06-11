#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool solve() {
	int f, r, aux;
	vector<int> front, rear;
	vector<float> ratios;
	float spread, maxSpread = 0;

	cin >> f;
	if (f == 0) return false;
	cin >> r;

	for (int i = 0; i < f; ++i) {
		cin >> aux;
		front.push_back(aux);
	}
	for (int i = 0; i < r; ++i) {
		cin >> aux;
		rear.push_back(aux);
	}

	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < r; ++j) {
			ratios.push_back((float)rear[j] / (float)front[i]);
		}
	}

	sort(ratios.begin(), ratios.end());
	for (int i = 0; i < ratios.size()-1; ++i) {
		spread = ratios[i + 1] / ratios[i];
		if (spread > maxSpread) {
			maxSpread = spread;
		}
	}
	cout << fixed << setprecision(2) << maxSpread << '\n';

	return true;
}

int main() {
	while (solve());
}