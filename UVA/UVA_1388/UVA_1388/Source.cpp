#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

const double INF = 999999999999999999.0;
const double EPS = 0.00000001;
const double PI = 2 * acos(0.0);
const int LENGTH = 10000;

bool solve() {
	int n, m;
	cin >> n >> m;
	if (!cin) return false;

	vector<double> positions;
	vector<double> newPositions;
	double origDisp = 10000.0 / (double)n, disp = 10000.0 / (double)(m + n);
	positions.push_back(0.0);
	newPositions.push_back(0.0);
	for (int i = 0; i < n-1; ++i) {
		positions.push_back(positions[i] + origDisp);
	}
	for (int i = 0; i < m + n - 1; ++i) {
		newPositions.push_back(newPositions[i] + disp);
	}

	double minimum = 0.0;
	for (int i = 0; i < n; ++i) {
		double aux = INF;
		for (int j = 0; j < m + n; ++j) {
			aux = min(aux, abs(positions[i] - newPositions[j]));
		}
		minimum += aux;
	}
	cout << fixed << setprecision(4) << minimum << '\n';

	return true;
}

int main() {
	while (solve());
}