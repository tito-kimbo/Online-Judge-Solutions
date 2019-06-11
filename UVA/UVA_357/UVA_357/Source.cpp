#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long int>> memo(30001, vector<long long int>(5));
const vector<int> COINS = {1,5,10,25,50};

void generateSol() {
	for (int i = 0; i < 30001; ++i) {
		memo[i][0] = 1; //Base case, using only 1 cent coins
		for (int j = 1; j < 5; ++j) {
			memo[i][j] = memo[i][j - 1];
			//If i > current coin we must add 
			if (i >= COINS[j]) {
				memo[i][j] += memo[i - COINS[j]][j];
			}
		}
	}
}

bool solve() {
	int n;
	cin >> n;
	if (!cin) return false;

	if (memo[n][4] == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
	else cout << "There are " << memo[n][4] << " ways to produce " << n << " cents change.\n";

	return true;
}

int main() {
	generateSol();
	while (solve());
}