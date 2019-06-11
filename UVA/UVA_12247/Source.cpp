#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool solve() {
	vector<int> princess(3), prince(2);
	unordered_map<int, bool> used;

	cin >> princess[0] >> princess[1] >> princess[2];
	cin >> prince[0] >> prince[1];

	used[princess[0]] = used[princess[1]] = used[princess[2]] =
		used[prince[0]] = used[prince[1]] = true;

	if (princess[0] == 0 && princess[1] == 0 && princess[2] == 0 &&
		prince[0] == 0 && prince[1] == 0) {
		return false;
	}

	sort(princess.begin(), princess.end());
	sort(prince.begin(), prince.end());

	int aux;
	if (prince[1] > princess[2]) {

		if (prince[0] > princess[2]) {
			aux = 1;
		}
		else if (prince[0] > princess[1]) {
			aux = princess[1] + 1;
		} else {
			aux = princess[2] + 1;
		}

	}
	else {
		if (prince[1] > princess[1] && prince[0] > princess[1]) {
			aux = princess[1] + 1;
		}
		else {
			aux = -1;
		}
	}
	while (used[aux]) {
		aux++;
	}
	if (aux > 52) aux = -1;
	cout << aux << '\n';

	return true;
}

int main() {
	while (solve());
}