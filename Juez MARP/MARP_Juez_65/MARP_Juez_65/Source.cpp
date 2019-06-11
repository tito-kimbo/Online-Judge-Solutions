#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Top-down
//Necesita optimización
int dp(int i, int j, int L, vector<int> &cuts, vector<vector<int>> &m) {
	int current = INT_MAX;
	if (m[i][j] != -1) return m[i][j];
	else if (i+1 == j) {
		m[i][j] = 0; return 0;
	}

	for (int k = i+1; k < j; ++k) {
		current = min(current, dp(i, k, cuts[k]-cuts[i], cuts, m) + dp(k, j, cuts[j]-cuts[k], cuts, m));
	}
	current += 2*L;
	m[i][j] = current;
	return m[i][j];
}


bool solve() {
	int L, N;
	cin >> L >> N;
	if (L == 0 && N == 0) return false;

	vector<int> places(N+2);
	vector<vector<int>> matrix(N + 2, vector<int>(N + 2, -1));
	vector<vector<int>> aux(N + 2, vector<int>(N + 2, -1));
	vector<int> sol(N+3, 0);
	places[0] = 0;
	places[N+1] = L;
	for (int i = 0; i < N; ++i) cin >> places[i+1];

	cout << dp(0, N + 1, L, places, matrix) << '\n';
	//cout << dp(0, N+1, L, N+2, places, sol) << '\n';

	return true;
}

int main() {
	while (solve());
}