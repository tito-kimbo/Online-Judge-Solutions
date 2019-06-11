#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int dfs(int current, vector<vector<int>> const & graph, vector<bool> &mark) {
	mark[current] = true;
	int count = 1;
	for (int i = 0; i < graph[current].size(); ++i) {
		if(!mark[graph[current][i]]) count += dfs(graph[current][i], graph, mark);
	}
	return count;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> mark(n,false);
	vector<vector<int>> graph(n, vector<int>());
	int aux1, aux2;
	for (int i = 0; i < n; ++i) { graph[i] = {}; }
	for (int i = 0; i < m; ++i) {
		cin >> aux1 >> aux2;
		aux1--;
		aux2--;
		graph[aux1].push_back(aux2);
		graph[aux2].push_back(aux1);
	}

	int maximum = 0;
	int count;
	//Do dfs with count
	for (int i = 0; i < n; ++i) {
		if(!mark[i]) count = dfs(i, graph, mark);
		maximum = max(count, maximum);
	}
	cout << maximum << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}