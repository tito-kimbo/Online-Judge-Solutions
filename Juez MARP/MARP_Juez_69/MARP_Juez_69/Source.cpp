#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	//No necesitamos reconstruir la solución
	vector<bool> assigned;
	int t, tEstim, k;
};

bool operator<(const node &n1, const node &n2) {
	//Las colas de prioridad se ordenan de mayor a menor
	return n1.tEstim > n2.tEstim;
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;

	vector<vector<int>> taskTime(n,vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) cin >> taskTime[i][j];

	vector<int> fast(n), slow(n), opt(n+1, 0), pes(n+1, 0);
	//We precalculate row min/max
	for (int i = 0; i < n; ++i) {
		fast[i] = taskTime[i][0];
		slow[i] = taskTime[i][0];
		for (int j = 1; j < n; ++j) {
			fast[i] = min(fast[i], taskTime[i][j]);
			slow[i] = max(slow[i], taskTime[i][j]);
		}
	}

	//We precalculate optimistic/pessimistic estimates
	for (int i = n - 1; i >= 0; --i) {
		opt[i] = opt[i + 1] + fast[i];
		pes[i] = pes[i + 1] + slow[i];
	}

	//We create the root node, initialize variables and add the PQ
	node X,Y;
	X.assigned = vector<bool>(n, false);
	X.k = 0;
	X.t = 0;
	X.tEstim = opt[0];

	int bestTime = pes[0];
	//We process the PQ elements until it's empty
	priority_queue<node> pq;
	pq.push(X);

	while (!pq.empty()) {
		X = pq.top();
		pq.pop();
		Y.assigned = X.assigned;
		Y.k = X.k + 1;
		for (int i = 0; i < n; ++i) {
			if (!X.assigned[i]) {
				Y.assigned[i] = true;
				Y.t = X.t+taskTime[X.k][i];
				Y.tEstim = Y.t+opt[Y.k];

				if (Y.tEstim <= bestTime) {
					if (Y.k == n) bestTime = Y.t;
					else {
						pq.push(Y);
						bestTime = min(bestTime, Y.t+pes[Y.k]);
					}
				}
				Y.assigned[i] = false;
			}
		}
	}

	cout << bestTime << '\n';

	return true;
}

int main() {
	while (solve());
}