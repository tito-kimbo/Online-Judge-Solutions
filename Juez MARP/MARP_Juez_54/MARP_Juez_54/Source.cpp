#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct building {
	int start, end;
};

bool operator<(building b1, building b2) {
	return b2.start < b1.start; //That way buildings which start earlier will have higher priority
}

istream & operator >> (istream &in, building &b) {
	in >> b.start >> b.end;
	return in;
}

bool solve() {
	int N;
	cin >> N;
	if (N == 0) return false;

	//IDEA: Get starting points and ending points
	priority_queue<building> pq;
	building b;
	for (int i = 0; i < N; ++i) {
		cin >> b;
		pq.push(b);
	}
	int tunnels, next;
	tunnels = 0;
	while (pq.size()>0) {
		next = pq.top().end;
		pq.pop();
		tunnels++;
		while (!pq.empty() && pq.top().start < next) {
			next = min(next, pq.top().end);
			pq.pop();
		}
	}
	cout << tunnels << '\n';
	return true;
}

int main() {
	while (solve());
}