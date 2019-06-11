#include <iostream>
#include <vector>
using namespace std;

bool dp(int i, int j, int amount, vector<int> &c, vector<int> &q, vector<vector<int>> &m) {

}

bool solve() {
	int n;
	cin >> n;
	if (!cin) return false;
	vector<int> coins(n),amount(n);
	for (int i = 0; i < n; ++i) cin >> coins[i];
	for (int i = 0; i < n; ++i) cin >> amount[i];
	
	return true;
}

int main() {
	while (solve());
}