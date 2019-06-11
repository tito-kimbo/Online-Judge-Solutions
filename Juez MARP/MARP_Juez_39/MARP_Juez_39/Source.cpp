#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct edge {
	int to;
	long long int cost;
};

bool operator<(edge e1, edge e2) {
	return e2.cost < e1.cost;
}

vector<long long int> dijkstra(int o, vector<vector<edge>> &g) {
	vector<long long int> distTo(g.size(), INT_MAX);
	priority_queue<edge> pq;
	distTo[o] = 0;
	pq.push({ o,distTo[o] });
	while (!pq.empty()) {
		int v = pq.top().to;
		//We discard redundant elements
		if (pq.top().cost != distTo[v]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (auto e : g[v]) {
			//relax the edge
			int w = e.to;
			if (distTo[w] > distTo[v] + e.cost) {
				distTo[w] = distTo[v] + e.cost;
				pq.push({ w,distTo[w] });
			}
		}
	}
	return distTo;
}

bool solve() {
	int N,C,P;
	cin >> N;
	if (!cin) return false;
	cin >> C;

	vector<vector<edge>> fromGraph(N+1), toGraph(N+1);
	int from, to, cost, origin;
	for (int i = 0; i < C; ++i) {
		//read
		cin >> from >> to >> cost;
		fromGraph[to].push_back({ from,cost });
		toGraph[from].push_back({ to,cost });
	}
	cin >> origin >> P;
	vector<int> v(P);
	for (int i = 0; i < P; ++i) cin >> v[i];

	vector<long long int> costTo, costFrom;
	costTo = dijkstra(origin, toGraph);
	costFrom = dijkstra(origin, fromGraph);

	long long int accum = 0;
	bool possible = true;
	for (int i = 0; i < P && possible; ++i) {
		possible = (costTo[v[i]] != INT_MAX && costFrom[v[i]] != INT_MAX);
		accum += costTo[v[i]] + costFrom[v[i]];
	}

	if (possible) cout << accum << '\n';
	else cout << "Imposible\n";

	return true;
}

int main() {
	while (solve());
}