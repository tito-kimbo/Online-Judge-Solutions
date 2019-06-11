#include <iostream>
#include <vector>
using namespace std;

bool isBipartite(int current, vector<vector<int>> const & graph, vector<int> &colors, vector<bool> &marks) {
	marks[current] = true;
	int newColor = -1 * colors[current];
	for (int i = 0; i < graph[current].size(); ++i) {
		if (colors[graph[current][i]] != 0 && colors[graph[current][i]] != newColor) {
			return false;
		} else {
			colors[graph[current][i]] = newColor;
		}
	}
	for (int i = 0; i < graph[current].size(); ++i) {
		if (!marks[graph[current][i]] && !isBipartite(graph[current][i], graph, colors, marks)) return false;
	}
	return true;
}

bool solve() {
	int V, E;

	cin >> V;
	if (!cin) return false;
	cin >> E;
	int aux1, aux2;
	vector<bool> marks(V, false);
	vector<int> colors(V,0);
	vector<vector<int>> graph(V, vector<int>());
	for (int i = 0; i < E; ++i) {
		cin >> aux1 >> aux2;
		graph[aux1].push_back(aux2);
		graph[aux2].push_back(aux1);
	}
	
	if (V == 0) {
		cout << "SI\n";
	}
	else {
		//WE NEED TO CHECK FOR EVERY STARTING VERTEX, in case it is not a connected graph
		bool bipartite = true;
		for (int i = 0; i < V && bipartite; ++i) {
			if(!marks[i]){
				colors[i] = 1;
				bipartite = bipartite && isBipartite(i, graph, colors, marks);
			}
		}
		if (bipartite) {
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