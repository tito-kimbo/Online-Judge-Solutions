#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(int i, int j, vector<vector<bool>> &marks, vector<vector<int>> &board) {
	if (i == 0 || marks[i][j]) return board[i][j]; 
	else {
		int A1, A2, A3;
		A1 = A2 = A3 = 0;
		if (j != 0) A1 = dp(i - 1, j - 1, marks, board);
		A2 = dp(i - 1, j, marks, board);
		if (j != board[0].size()-1) A3 = dp(i - 1, j + 1, marks, board);
		marks[i][j] = true;
		board[i][j] += max(A1, max(A2, A3));
		return board[i][j];
	}
}

bool solve() {
	int N;
	cin >> N;
	if (!cin) return false;

	vector<vector<bool>> v(N, vector<bool>(N, false));
	vector<vector<int>> board(N, vector<int>(N, -1));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	int M = -1, aux, idx = -1;
	for (int i = 0; i < N; ++i) {
		aux = dp(N - 1, i, v, board);
		if (aux > M) {
			M = aux;
			idx = i+1;
		}
	}
	cout << M << ' ' << idx << '\n';
	return true;
}

int main() {
	while (solve());
}