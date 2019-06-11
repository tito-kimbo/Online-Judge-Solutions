#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <set>
using namespace std;

const int INF = 10000000;

//We solve coin change and rebuild the solution
int dp(int amt, vector<int> &C, vector<int> &Q, vector<vector<int>> &m) {
	int counter;

	for (int i = 1; i < C.size(); ++i) {
		for (int j = amt; j >= 0; --j) {
			if (m[i-1][j] != INF) {
				counter = 0;
				while (counter <= Q[i] &&
					j + counter*(C[i]) <= amt &&
					m[i][j + counter*C[i]] >= m[i - 1][j] + counter){
					m[i][j + counter*C[i]] = m[i - 1][j] + counter;
					++counter;
				}
			}
		}
	}

	return m[m.size()-1][amt];
}

bool rebuildSolution(int i, int j, int cnt, int total, const int &n, const vector<vector<int>> &m, 
	const vector<int>&Q, const vector<int> &coins, vector<int> &sol) {
	if (i == 0) return false;
	else if (j == 0) return total == m[n][m[0].size()-1];
	else {
		if (total > m[n][m[0].size() - 1]) return false;
		bool validLeft = false, validDown = false;
		if (j >= coins[i] && cnt < Q[i] && m[i][j-coins[i]]+1 == m[i][j]) {
			validLeft = rebuildSolution(i, j - coins[i], cnt+1, total+1, n, m, Q, coins, sol);
		}
		if (!validLeft && m[i][j] == m[i - 1][j]) { 
			//If validleft then there is a solution with more of the previous coins
			validDown = rebuildSolution(i - 1, j, 0, total, n, m, Q, coins, sol);
		}

		if (validLeft) sol[n - i + 1]++;
		return validLeft || validDown;
	}
}


bool solve() {
	int n, price;
	cin >> n;
	//n = 1 + (rand() % 50);
	if (!cin) return false;

	vector<int> coins(n + 1), amount(n + 1);

	int myaux;
	//set<int> s;
	for (int i = 1; i <= n; ++i) cin >> coins[n-i+1];
	/*for (int i = 1; i <= n; ++i) {
		do {
			myaux = 1 + (rand() % 1000);
		} while (s.count(myaux));
		coins[n - i + 1] = myaux;
		s.insert(myaux);
	}*/
	for (int i = 1; i <= n; ++i) cin >> amount[n-i+1];
	//for (int i = 1; i <= n; ++i) amount[n - i + 1] = 1 + (rand() % 50);
	cin >> price;
	//price = 1 + (rand() % 10000);

	vector<vector<int>> m(n + 1, vector<int>(price + 1, INF));
	vector<int> solution(n + 1, 0);

	for (int i = 0; i <= n; ++i) m[i][0] = 0;
	int sol = dp(price, coins, amount, m);

	if (sol >= INF) cout << "NO\n";
	else {
		cout << "SI";
		rebuildSolution(n, price, 0, 0, n, m, amount, coins, solution);

		int checksum = 0, checkcount = 0;;
		for (int i = 1; i <= n; ++i) {
			checkcount += solution[i];
			checksum += solution[i] * coins[n - i + 1];
		}
		if (checkcount != sol) {
			cerr << "ERROR: number of coins is not optimal.\n";
			system("pause");
		}
		else if (checksum != price) {
			cerr << "ERROR: it is not a solution.\n";
			system("pause");
		}
		for (int i = 1; i <= n; ++i) cout << ' ' << solution[i];
		cout << '\n';
	}

	return true;
}

int main() {
	while (solve());
}