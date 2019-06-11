#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool dfs(int current, const int &goal, const int &width, const vector<vector<pair<int,int>>> &g, vector<bool> &marks) {
	if (current == goal) return true;
	marks[current] = true;
	for (int i = 0; i < g[current].size(); ++i) {
		if (width <= g[current][i].second && 
			!marks[g[current][i].first] && 
			dfs(g[current][i].first, goal, width, g, marks)) return true;
	}
	return false;
}

bool solve() {
	int V,E;
	cin >> V;
	if (!cin) return false;
	cin >> E;

	vector<vector<pair<int,int>>> v(V+1);
	int from, to, width;
	for (int i = 0; i < E; ++i) {
		cin >> from >> to >> width;
		v[from].push_back(make_pair(to,width));
		v[to].push_back(make_pair(from,width));
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		vector<bool> marks(V + 1, false);
		cin >> from >> to >> width;
		if (dfs(from, to, width, v, marks)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return true;
}

int main() {
	while (solve());
}