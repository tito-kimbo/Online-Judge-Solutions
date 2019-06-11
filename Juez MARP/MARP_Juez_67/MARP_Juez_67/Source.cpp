#include <iostream>
#include <vector>
using namespace std;

const int INF = 10000000;

//Resolvemos problema del cambio y reconstruimos
int dp(int amt, vector<int> &C, vector<int> &Q, vector<int> &m) {
	int counter;

	for (int i = 1; i < C.size(); ++i) {
		for (int j = amt; j >= 0; --j) {
			if (m[j] != INF) {
				counter = 0;
				while (counter <= Q[i] &&
					j + counter*(C[i]) <= amt && 
					m[j + counter*C[i]] >= m[j] + counter) {
					m[j + counter*C[i]] = m[j] + counter;
					++counter;
				}
			}
		}
	}

	return m[amt];
}

bool solve() {
	int n, precio;
	cin >> n;
	if (!cin) return false;
	vector<int> coins(n+1), amount(n+1), solution(n+1, 0);
	for (int i = 1; i <= n; ++i) cin >> coins[i];
	for (int i = 1; i <= n; ++i) cin >> amount[i];
	cin >> precio;
	vector<int> m(precio+1, INF);
	m[0] = 0;
	int sol = dp(precio, coins, amount, m);
	if (sol >= INF) cout << "NO\n";
	else cout << "SI " << sol << '\n';

	return true;
}

int main() {
	while (solve());
}