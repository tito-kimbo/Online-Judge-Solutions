#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
	int a, b, c;

	cin >> a >> b >> c;
	vector<int> players(a, 1);
	unordered_map<int, int> board;

	for (int i = 1; i < 106; ++i) {
		board[i] = i;
		if (i > 100) {
			board[i] = 100;
		}
	}

	int from, to;
	for (int i = 0; i < b; ++i) {
		cin >> from >> to;
		board[from] = to;
	}

	int move;
	bool won = false;
	for (int i = 0; i < c; ++i) {
		cin >> move;
		if (!won) {
			players[i%a] = board[players[i%a] + move];
			if (players[i%a] == 100) won = true;
		}
	}

	for (int i = 0; i < a; ++i) {
		cout << "Position of player " << i+1 << " is " << players[i] << ".\n";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}