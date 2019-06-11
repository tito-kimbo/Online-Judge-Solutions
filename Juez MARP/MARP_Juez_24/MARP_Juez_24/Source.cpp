#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;

	int aux;
	priority_queue<int, vector<int>, greater<int>> pq2;
	priority_queue<int> pq1Inv;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int currentSize = 0;

	pq1Inv.push(v[0]);
	cout << 2*v[0] << ' ';
	for(int i=1;i<n;++i) {
		//Insertion
		if (v[i] > pq1Inv.top()) {
			pq2.push(v[i]);
		} else {
			pq1Inv.push(v[i]);
		}

		//Rebalancing
		if (pq1Inv.size() > pq2.size() + 1) {
			pq2.push(pq1Inv.top());
			pq1Inv.pop();
		}
		else if (pq2.size() > pq1Inv.size() + 1) {
			pq1Inv.push(pq2.top());
			pq2.pop();
		}

		if (i % 2 == 0) { //Odd size
			if (pq1Inv.size() > pq2.size()) {
				cout << 2 * pq1Inv.top();
			}
			else {
				cout << 2 * pq2.top();
			}
		}
		else { //Even size
			cout << pq1Inv.top() + pq2.top();
		}
		if (i < n - 1) {
			cout << ' ';
		}
		else {
			cout << '\n';
		}
	}

	return true;
}

int main() {
	while (solve());
}