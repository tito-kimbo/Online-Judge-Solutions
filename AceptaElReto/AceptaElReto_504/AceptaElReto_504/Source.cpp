#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

const int INF = 900000000;

struct edge {
	int to, weight;
};

struct aux {
	int dist, vert, to;
};

bool operator<(const aux &a1, const aux & a2) {
	return a1.dist > a2.dist || (a1.dist == a2.dist && a1.vert > a2.vert);
}

void dijkstra(int s, vector<vector<edge>> const &adjList, vector<int> &vertTo, vector<int> &distTo) {
	distTo.assign(adjList.size(), INF);
	vertTo.assign(adjList.size(), INF);
	priority_queue<aux, vector<aux>, less<aux>> pq;
	int v,d,n,from,to;

	pq.push({ 0, 0, s });
	distTo[s] = 0;
	vertTo[s] = 0;
	while (!pq.empty()) {
		v = pq.top().to;
		d = pq.top().dist;
		n = pq.top().vert;
		pq.pop();
		//Updating pqueue (by ignoring old data)
		if (d > distTo[v] || (d == distTo[v] && n > vertTo[v])) continue;
		//relax the edges
		for (auto e : adjList[v]) {
			from = v;
			to = e.to;
			if (distTo[to] > distTo[from] + e.weight ||
				(distTo[to] == distTo[from] + e.weight && vertTo[to] > vertTo[from] + 1)) {
				distTo[to] = distTo[from] + e.weight;
				vertTo[to] = vertTo[from] + 1;
				pq.push({distTo[to], vertTo[to], e.to });
			}
		}

	}
}

void bfs(int s, vector<vector<edge>> const & adjList, vector<int> &distances) {
	distances.assign(adjList.size(), INT_MAX);
	vector<bool> marks(adjList.size(), false);
	queue<int> q;

	q.push(s);
	q.push(0);
	int v, dist;
	while (!q.empty()) {
		//Remove marked items
		while (!q.empty() && marks[q.front()]) {
			q.pop();
			q.pop();
		}
		if (!q.empty()) {
			v = q.front();
			q.pop();
			dist = q.front();
			q.pop();

			distances[v] = dist;
			marks[v] = true;
			for (auto e : adjList[v]) {
				if (!marks[e.to]) {
					q.push(e.to);
					q.push(dist + 1);
				}
			}
		}
	}
}

bool solve(){
	int N, C;
	cin >> N;
	if (!cin) return false;
	cin >> C;
	vector<vector<edge>> v(N + 1,vector<edge>());

	int from, to, w;
	for (int i = 0; i < C; ++i) {
		cin >> from >> to >> w;
		v[from].push_back({ to,w });
		v[to].push_back({ from,w });
	}

	vector<int> vTo, dTo, bfsResult;
	//Process queries
	int prev = -2, nextF = -1, nextTo = -1;
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> nextF >> nextTo;
		bfs(nextF, v, bfsResult);
		if(bfsResult[nextTo] != INT_MAX) dijkstra(nextF, v, vTo, dTo);
		if (bfsResult[nextTo] == INT_MAX) cout << "SIN CAMINO\n";
		else {
			cout << dTo[nextTo] << ' ';
			if (bfsResult[nextTo] == vTo[nextTo]) cout << "SI\n";
			else cout << "NO\n";
		}
	}
	cout << "----\n";

	return true;
}

int main() {
	while (solve());
}