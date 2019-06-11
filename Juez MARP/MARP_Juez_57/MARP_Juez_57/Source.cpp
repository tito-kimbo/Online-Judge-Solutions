#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct task {
	int start, end;
};

bool operator<(task t1, task t2) {
	return t2.start < t1.start || (t2.start == t1.start && t2.end > t1.end);
}

bool solve() {
	int C, F, n;

	cin >> C >> F >> n;
	if (C == 0 && F == 0 && n == 0) return false;

	priority_queue<task> pq;
	int start, end;
	for (int i = 0; i < n; ++i) {
		cin >> start >> end;
		if(end > C) pq.push({ start,end });
	}
	if (n == 0) {
		cout << "Imposible\n";
		return true;
	}
	task current;
	//Discard useless tasks
	if (!pq.empty()) {
		current = pq.top();
		pq.pop();
	}
	else {
		current = { -1,-1 };
	}
	//Try to find better candidates for first task
	while (!pq.empty() && pq.top().start <= C) {
		if (pq.top().end > current.end) current = pq.top();
		pq.pop();
	}
	//Now assign tasks 
	int toCover = current.end, tasks = 1;
	bool failed = current.start > C;

	while (toCover < F && !failed) {
		if (pq.empty() || pq.top().start > toCover) failed = true;
		else {
			//There are candidates -> process them
			tasks++;
			while(!pq.empty() && pq.top().start <= toCover){
				if (pq.top().end > current.end) {
					current = pq.top();

				}
				pq.pop();
			}
			toCover = current.end;

		}
	}

	if (failed) cout << "Imposible\n";
	else cout << tasks << '\n';

	return true;
}

int main() {
	while (solve());
}