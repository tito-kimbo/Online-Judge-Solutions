#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

struct auxStruct {
	int v, dist;
};

bool operator<(const auxStruct &a1, const auxStruct &a2) {
	return a2.dist < a1.dist; //for priority queue
}

bool solve() {
	int N;
	cin >> N;
	if (!cin) return false;

	vector<int> load(N, 0);
	for (int i = 1; i <= N; ++i) cin >> load[i - 1];

	int E;
	cin >> E;
	//Aquí suponemos que no es necesario almacenar el grafo (todas las aristas se proporcionan en orden)
	vector<vector<int>> graph(N, vector<int>(N,-1));
	int from, to, cost;
	for (int i = 0; i < E; ++i) {
		cin >> from >> to >> cost;
		graph[from-1][to-1] = cost;
	}

	//Aplicamos Dijkstra (1-based)
	vector<int> distTo(N, INT_MAX);
	priority_queue<auxStruct> pq;
	if (N != 0) {
		distTo[0] = load[0];
		pq.push({ 0, distTo[0] });
	}
	int v, w;
	while (!pq.empty()) {
		v = pq.top().v;
		if (pq.top().dist != distTo[v]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (int j = 0; j < N; ++j) {
			//we relax the edge
			if (graph[v][j] == -1) continue;
			w = j;
			if (distTo[w] > distTo[v] + graph[v][j] + load[w]) {
				distTo[w] = distTo[v] + graph[v][j] + load[w];
				pq.push({ w, distTo[w] });
			}
		}
		graph[v].clear();
	}

	if (N == 0 || distTo[N - 1] == INT_MAX) cout << "IMPOSIBLE\n";
	else cout << distTo[N - 1] << '\n';
	return true;
}

int main() {
	while (solve());
}