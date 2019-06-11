#include <iostream>
#include <cstring>
using namespace std;

//mem table
long long int arr[66][66][2];

//DP solution
/*
BASE CASES
- 1 drawer cases, nSecured > nDrawers case, nSecured = nDrawers and topSecured = 0

RECURSIVE CASES
- Whether top drawer is or isn't locked
- Check memo table for already calculated solutions
*/
long long int solveDP(int nDrawers, int nSecured, int topSecured) {
	//Base cases
	if (nDrawers == 1) {
		if (nSecured == 1 && topSecured == 1) return 1;
		else if (nSecured == 0 && topSecured == 0) return 2;
		else if (nSecured == 0 && topSecured == 1) return 1;
		return 0;
	} else if (nSecured > nDrawers) {
		return 0;
	} else if (nSecured == nDrawers && topSecured == 0) {
		return 0;
	}
	else { 	//Recursive cases
		if (arr[nDrawers][nSecured][topSecured] != -1) {
			return arr[nDrawers][nSecured][topSecured];
		}
		else if (topSecured == 0) {
			arr[nDrawers][nSecured][topSecured] = solveDP(nDrawers - 1, nSecured, 1) +
				solveDP(nDrawers - 1, nSecured, 0);
		}
		else {
			arr[nDrawers][nSecured][topSecured] = solveDP(nDrawers - 1, nSecured - 1, 1) +
				solveDP(nDrawers - 1, nSecured, 0);
		}
		return arr[nDrawers][nSecured][topSecured];
	}
}

bool solve() {
	int n, s;

	cin >> n >> s;
	if (n < 0 && s < 0) return false;

	cout << solveDP(n, s, 1) << '\n';

	return true;
}

int main() {
	memset(arr, -1, sizeof(arr));
	while (solve());
}