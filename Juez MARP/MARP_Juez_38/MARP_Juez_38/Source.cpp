#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

struct auxStruct {
	int v, dist;
};

bool operator<(auxStruct a1, auxStruct a2) {
	return a2.dist < a1.dist; //for priority queue
}

bool solve() {
	int N;
	cin >> N;
	if (N == 0) return false;

	vector<int> load(N+1, 0);
	for (int i = 1; i <= N; ++i) cin >> load[i];

	int E;
	cin >> E;
	vector<vector<pair<int, int>>> graph(N+1);
	int from, to, cost;
	for (int i = 0; i < E; ++i) {
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}

	//Aplicamos Dijkstra (1-based)
	vector<int> distTo(N+1, INT_MAX);
	priority_queue<auxStruct> pq;
	distTo[1] = load[1];
	pq.push({ 1, distTo[1] });
	while (!pq.empty()) {
		int v = pq.top().v, w;
		if (pq.top().dist != distTo[v]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (auto e : graph[v]){
			//we relax the edge
			w = e.first;
			if (distTo[w] > distTo[v] + e.second + load[w]) {
				distTo[w] = distTo[v] + e.second + load[w];
				pq.push({ w, distTo[w] });
			}
		}
	}

	if (distTo[N] == INT_MAX) cout << "IMPOSIBLE\n";
	else cout << distTo[N] << '\n';
	return true;
}

int main() {
	while (solve());
}