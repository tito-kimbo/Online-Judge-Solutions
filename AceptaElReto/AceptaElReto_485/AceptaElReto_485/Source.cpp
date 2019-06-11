#include <queue>
#include <iostream>
using namespace std;

bool solve() {
	int n, l = 0,aux;
	queue<int> q;
	cin >> n;
	if (n == 0) return false;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		l += aux;
		q.push(aux);
	}
	bool first = true;
	while (!q.empty()) {
		if (!first) cout << ' ';
		first = false;
		cout << l;
		l -= q.front();
		q.pop();
	}
	cout << '\n';
	return true;
}

int main() {
	while (solve());
}