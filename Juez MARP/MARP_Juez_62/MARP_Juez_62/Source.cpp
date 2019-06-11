#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp(int i, int j, string &w1, string &w2, vector<vector<bool>> &marks, vector<vector<int>> &v) {
	if (i == w1.size() || j == w2.size()) return 0;
	else if (marks[i][j]) return v[i][j];
	else if (w1[i] != w2[j]) {
		int l1, l2;
		l1 = dp(i, j + 1, w1, w2, marks, v);
		l2 = dp(i + 1, j, w1, w2, marks, v);
		v[i][j] = max(l1, l2);
		marks[i][j] = true;
	}
	else {
		v[i][j] = dp(i + 1, j + 1, w1, w2, marks, v) + 1;
		marks[i][j] = true;
	}
	return v[i][j];
}

bool solve() {
	string s1, s2;
	cin >> s1;
	if (!cin) return false;
	cin >> s2;
	int N = max(s1.size(), s2.size())+1;
	vector<vector<bool>> m(N, vector<bool>(N, false));
	vector<vector<int>> v(N, vector<int>(N, 0));
	if (N == s1.size()) cout << dp(0, 0, s1, s2, m, v);
	else cout << dp(0, 0, s2, s1, m, v);
	cout << '\n';

	return true;
}

int main() {
	while (solve());
}