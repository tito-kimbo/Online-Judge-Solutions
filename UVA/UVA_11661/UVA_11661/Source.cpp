//UVA 11661

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const char RESTAURANT = 'R';
const char DRUGSTORE = 'D';
const char R_AND_D = 'Z';
const char EMPTY = '.';

int getDistance(const int & posD, const int & posR, const int &n) {
	if (posD == -1 || posR == -1) {
		return n;
	}
	else {
		return abs(posD - posR);
	}
}

bool solve() {
	string s;
	char c;
	int n;

	cin >> n;
	cin.get();
	if (n == 0) return false;
	int distance = n, lastDrugStore = -1, lastRestaurant = -1, current = 0;

	cin >> c;
	while (c == EMPTY) {
		cin >> c;
		current++;
	}

	for (int i = current; i < n; ++i) {

		if (c == RESTAURANT) {
			distance = min(distance, getDistance(lastDrugStore, i, n));
			lastRestaurant = i;
		}
		else if (c == DRUGSTORE) {
			distance = min(distance, getDistance(i, lastRestaurant, n));
			lastDrugStore = i;
		}

		if (c == R_AND_D) {
			distance = 0;
			getline(cin, s);
			break;
		}

		if (i != n - 1) cin >> c;
	}

	cout << distance << '\n';
	return true;
}

int main() {
	while (solve());
}