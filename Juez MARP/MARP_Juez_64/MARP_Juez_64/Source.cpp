#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

const int INF = 10000000;

//Algoritmo de Floyd
void floyd(vector<vector<int>> &v) {
	for (int k = 0; k < v.size(); ++k)
		for (int i = 0; i < v.size(); ++i)
			for (int j = 0; j < v.size(); ++j)
				v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
}

bool solve() {
	int P, R;
	cin >> P >> R;
	if (!cin) return false;
	map<string, int> nameToNode;
	//map<int, string> nodeToName;

	int current = 0;
	vector<vector<int>> matrix(P, vector<int>(P, INF));
	string n1, n2;
	int from, to;
	for (int i = 0; i < R; ++i) {
		cin >> n1 >> n2;
		if (nameToNode.count(n1) == 0) {
			nameToNode[n1] = current;
			from = current;
			current++;
		}
		else from = nameToNode[n1];

		if (nameToNode.count(n2) == 0) {
			nameToNode[n2] = current;
			to = current;
			++current;
		}
		else to = nameToNode[n2];
		matrix[from][to] = 1;
		matrix[to][from] = 1;
	}
	for (int i = 0; i < P; ++i) matrix[i][i] = 0;
	floyd(matrix);
	//Calculamos la separación
	int sep = 0;
	for (int i = 0; i < P; ++i) {
		for (int j = 0; j < P; ++j) {
			sep = max(sep, matrix[i][j]);
		}
	}
	if (sep >= INF) cout << "DESCONECTADA\n";
	else cout << sep << '\n';

	return true;
}

int main() {
	while (solve());
}