#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(int i, int j, vector<int> &cubes, vector<vector<int>> &v){
	if (i >= v.size() || j < 0) return 0;
	else if (v[i][j] != -1) return v[i][j];
	else if (j < i) v[i][j] = 0;
	else if (j - i == 0) v[i][j] = cubes[i];
	else {
		int M = -1;
		if (cubes[i+1] >= cubes[j]) M = max(M, cubes[i] + dp(i + 2, j, cubes, v));
		else M =  max(M,cubes[i] + dp(i + 1, j - 1, cubes, v));

		//SOLO PUEDE COMER DE LOS EXTREMOS

		if (cubes[j - 1] >= cubes[i]) M = max(M, cubes[j] + dp(i,j-2,cubes,v));
		else M = max(M, cubes[j] + dp(i + 1, j - 1, cubes, v));
		v[i][j] = M;
	}
	return v[i][j];
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<int> cubos(n);
	vector<vector<int>> m(n,vector<int>(n,-1));
	for (int i = 0; i < n; ++i)cin >> cubos[i];
	cout << dp(0, n - 1, cubos, m) << '\n';

	return true;
}

int main() {
	while (solve());
}