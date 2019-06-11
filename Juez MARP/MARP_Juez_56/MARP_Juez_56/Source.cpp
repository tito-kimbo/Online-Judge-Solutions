#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

bool solve() {
	int N;
	cin >> N;
	if (N == 0) return false;

	vector<pair<int, int>> tasks(N);
	int begin, end;
	for (int i = 0; i < N; ++i) {
		cin >> begin >> end;
		tasks[i] = make_pair(begin,end);
	}
	
	sort(tasks.begin(), tasks.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int people = 0;
	for (int i = 0; i < N; ++i) {
		if (pq.empty() || pq.top() > tasks[i].first) {
			people++;
		}
		else {
			pq.pop();
		}
		pq.push(tasks[i].second);
	}
	cout << people-1 << '\n';
	return true;
}

int main() {
	while (solve());
}