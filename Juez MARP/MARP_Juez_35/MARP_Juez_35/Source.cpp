#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include "ConjuntosDisjuntos.h"
using namespace std;

double EPS = 0.00000001;

double distance(pair<int, int> p1, pair<int, int> p2) {
	return hypot(p2.first-p1.first, p2.second-p1.second);
}

bool connected(pair<int,int> p1, pair<int,int> p2, const int K) {
	return distance(p1, p2) - K < EPS;
}

long long int index(pair<int,int> p, const int M) {
	return p.first*M + p.second;
}

bool isValid(const int &x, const int &y, int limX, int limY) {
	return x >= 0 && y >= 0 && x < limX && y < limY;
}

bool solve() {
	int N, M, K, n;
	cin >> N >> M >> K >> n;
	if (!cin) return false;
	vector<pair<int, int>> trees(n);
	pair<int, int> start, goal;
	start = make_pair(0, 0);
	goal = make_pair(N,M);
	int x, y;

	ConjuntosDisjuntos comp((N+1)*(M+1));
	vector<vector<bool>> marks((N+1), vector<bool>(M+1, false));
	marks[0][0] = true;
	marks[N][M] = true;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		trees[i] = make_pair(x, y);
	}

	//Añadimos los árboles uno a uno desde el final (y paramos si hemos conseguido unir los extremos)
	bool joined = false;
	pair<int, int> current;
	for (int k = trees.size() - 1; k >= 0 && !joined; --k) {
		current = trees[k];
		marks[current.first][current.second] = true;
		for (int i = current.first-K; i <= current.first+K; ++i) {
			for (int j = current.second-K; j <= current.second+K; ++j) {
				if (isValid(i, j, N + 1, M + 1) && marks[i][j] && connected(current, make_pair(i,j), K))
					comp.unir(comp.buscar(index(current, M + 1)), comp.buscar(index(make_pair(i, j), M + 1)));
			}
		}

		//cout << "BUSQUEDA(0,0): " << comp.buscar(index(make_pair(0, 0), M + 1)) << '\n';
		//cout << "BUSQUEDA(N,M): " << comp.buscar(index(make_pair(N, M), M + 1)) << '\n';
		//Comprobamos si el primer y el último elemento están unidos.
		if (comp.buscar(0) == comp.buscar((N+1)*(M+1)-1)) {
			joined = true;
		}
	}

	if (joined) {
		cout << current.first << ' ' << current.second << '\n';
	}
	else {
		cout << "NUNCA SE PUDO\n";
	}

	return true;
}

int main() {
	while (solve());
}