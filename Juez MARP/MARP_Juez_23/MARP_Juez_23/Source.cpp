#include <iostream>
#include <queue>
using namespace std;

struct periodic_task {
	int start,end,freq;
	periodic_task(int _s, int _e, int _f) : start(_s), end(_e),freq(_f) {}
};

bool operator<(periodic_task const& t1, periodic_task const& t2) {
	return t1.start > t2.start;
}

bool solve() {
	int N, T, M;
	cin >> N >> M >> T;
	if (!cin) return false;

	priority_queue<periodic_task> pq;
	int auxStart, auxEnd;
	for (int i = 0; i < N; ++i) {
		cin >> auxStart >> auxEnd;
		pq.push(periodic_task(auxStart, auxEnd, 0));
	}
	int auxFreq;
	for (int i = 0; i < M; ++i) {
		cin >> auxStart >> auxEnd >> auxFreq;
		pq.push(periodic_task(auxStart, auxEnd, auxFreq));
	}
	int timeElapsed = (pq.empty()) ? T : pq.top().start;
	bool noOverlap = true;

	while (noOverlap && timeElapsed < T && !pq.empty()) {
		periodic_task next = pq.top();
		pq.pop();
		timeElapsed = (pq.empty()) ? next.end : pq.top().start;
		if (timeElapsed < T) noOverlap = pq.empty() || next.end <= pq.top().start;
		if (next.freq != 0) pq.push(periodic_task(next.start + next.freq, next.end + next.freq, next.freq));
	}

	if (noOverlap) {
		cout << "NO\n";
	}
	else {
		cout << "SI\n";
	}

	return true;
}

int main() {
	while (solve());
}