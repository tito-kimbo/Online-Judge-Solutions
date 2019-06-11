#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

bool solve() {
	int n;

	cin >> n;
	if (n == 0) return false;

	long long int aux, sum,a, b;
	priority_queue<long long int, vector<long long int>, std::greater<long long int>> pq;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		pq.push(aux);
	}

	if (n == 1) sum = 0;
	else {
		sum = 0;
		while (!pq.empty()) {
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			sum += a+b;
			if(!pq.empty()) pq.push(a + b);
		}
	}

	cout << sum << '\n';

	return true;
}

int main() {
	while (solve());
}