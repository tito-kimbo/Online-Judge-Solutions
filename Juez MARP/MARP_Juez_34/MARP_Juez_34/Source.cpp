#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <fstream>
#include "ConjuntosDisjuntos.h" 
using namespace std;

typedef long long int lli;

size_t index(int i, int j, int nCols) {
	return i*nCols + j;
}

//Just need to look behind, on top and diagonals on top
lli checkMergePrev(int i, int j, const vector<vector<bool>> &g, ConjuntosDisjuntos &ds) {
	size_t id = index(i, j, g[0].size()), aux;
	if (j-1 >= 0 && g[i][j-1]) {
		aux = index(i, j - 1, g[0].size());
		ds.unir(id, aux);
	}
	if (i-1 >= 0){
		if (g[i - 1][j]) {
			aux = index(i - 1, j, g[0].size());
			ds.unir(id, aux);
		}
		if (j-1 >= 0 && g[i-1][j-1]) {
			aux = index(i - 1, j - 1, g[0].size());
			ds.unir(id, aux);
		}
		if (j+1 < g[0].size() && g[i-1][j+1]) {
			aux = index(i - 1, j + 1, g[0].size());
			ds.unir(id, aux);
		}
	}

	return ds.size(id);
}

//look to the right, below and diagonals below
lli checkMerge(int i, int j, const vector<vector<bool>> &g, ConjuntosDisjuntos &ds) {
	size_t id = index(i, j, g[0].size()), aux;
	checkMergePrev(i,j,g,ds);
	if (j + 1 < g[0].size() && g[i][j + 1]) {
		aux = index(i, j + 1, g[0].size());
		ds.unir(id, aux);
	}
	if (i + 1 < g.size()) {
		if (g[i + 1][j]) {
			aux = index(i + 1, j, g[0].size());
			ds.unir(id, aux);
		}
		if (j - 1 >= 0 && g[i + 1][j - 1]) {
			aux = index(i + 1, j - 1, g[0].size());
			ds.unir(id, aux);
		}
		if (j + 1 < g[0].size() && g[i + 1][j + 1]) {
			aux = index(i + 1, j + 1, g[0].size());
			ds.unir(id, aux);
		}
	}

	return ds.size(id);
}

bool solve() {
	int F, C;
	cin >> F >> C;
	if (!cin) return false;
	vector<vector<bool>> graph(F, vector<bool>(C, false));
	ConjuntosDisjuntos ds(F*C);

	char aux;
	lli maxSize = 0;
	cin.get();
	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < C; ++j) {
			cin.get(aux);
			if (aux == '#') {
				graph[i][j] = true;
				maxSize = max(maxSize, checkMergePrev(i, j, graph, ds));
			}
		}
		cin.get();
	}

	//GET MAXIMUM SIZE OF DISJOINT SET
	cout << maxSize << ' ';

	int n;
	cin >> n;
	int aux1, aux2;

	for (int i = 0; i < n; ++i) {
		cin >> aux1 >> aux2;
		graph[aux1 - 1][aux2 - 1] = true;
		//CHECK FOR POSSIBLE MERGES
		maxSize = max(maxSize, checkMerge(aux1-1, aux2-1, graph, ds));

		cout << maxSize;
		if (i != n - 1) cout << ' ';
		else cout << '\n';
	}

	return true;
}

int main(){

	/*ifstream input("input.txt");
	ofstream output("output.txt");

	cin.rdbuf(input.rdbuf());
	cout.rdbuf(output.rdbuf());*/
	while (solve());
}