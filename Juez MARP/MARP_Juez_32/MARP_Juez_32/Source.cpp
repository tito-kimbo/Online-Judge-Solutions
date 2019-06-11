#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int n, steps;
	point() : n(0), steps(0) {}
	point(int _n, int _steps) : n(_n), steps(_steps) {}
};

bool win(point p, point goal) {
	return p.n == goal.n;
}

bool solve() {
	int N, K, S, E;
	cin >> N >> K >> S >> E;
	if (N == 0 && K == 0 && S == 0 && E == 0) return false;
	vector<vector<int>> graph(N*N, vector<int>());
	vector<int> serpientesYEscaleras(N*N);
	vector<bool> visit(N*N, false);

	for (int i = 0; i < N*N; ++i) {
		serpientesYEscaleras[i] = i;
		for (int j = 1; j <= K; ++j) {
			if(i+j<N*N)graph[i].push_back(i+j);
		}
	}

	int orig, dest;
	for (int i = 0; i < S+E; ++i) {
		cin >> orig >> dest;
		serpientesYEscaleras[orig-1] = (dest-1);
	}

	//APLICAMOS DFS
	point w(N*N-1, -1), pAux;
	deque<point> bfs;
	bfs.emplace_back(point());
	visit[0] = true;
	pAux = bfs.front();
	bool found = win(pAux,w);
	while (!found) {
		int index = bfs.front().n, steps = bfs.front().steps + 1;
		for (int i = 0; i < graph[index].size() && !found; ++i) {
			if (!visit[graph[index][i]]) {
				int aux = graph[index][i]; 
				pAux = point(serpientesYEscaleras[aux], steps);
				visit[aux] = true;
				visit[serpientesYEscaleras[aux]] = true;
				bfs.emplace_back(pAux);
			}
		}
		bfs.pop_front();
		found = win(pAux, w);
	}

	cout << pAux.steps << '\n';

	return true;
}

int main() {
	while (solve());
}