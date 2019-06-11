#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <fstream>
#include <queue>
using namespace std;

using lli = long long int;

struct receta {
	string nombre;
	int coste, prestigio;
	receta() {}
	receta(string n, int c, int p)
		: nombre(n), coste(c), prestigio(p) {}
};

struct par {
	lli x, y;
	par(lli _x, lli _y) : x(_x), y(_y) {}
};

void maxPrestigeKnapSack01(lli const& b, vector<vector<par>> &table,
	vector<receta> const& rec, int i, int j) {

	if (table[i][j].x == -1)
	{
		maxPrestigeKnapSack01(b, table, rec, i + 1, j);
		if (j + rec[i].coste <= b) {
			maxPrestigeKnapSack01(b, table, rec, i + 1, j + rec[i].coste);
			if (table[i + 1][j + rec[i].coste].x + rec[i].prestigio > table[i + 1][j].x)
			{
				table[i][j] = table[i + 1][j + rec[i].coste];
				table[i][j].x += rec[i].prestigio;
				table[i][j].y += rec[i].coste;
				return;
			}
		}
		table[i][j] = table[i + 1][j];
	}
}

void findBestTopo(unordered_map<string, vector<receta>> &graph,
	vector<string> & recetas) {
	unordered_map<string, int> inDeg;

	for (auto it = graph.begin(); it != graph.end(); it++) {
		inDeg[it->first];
	}

	for (auto it = graph.begin(); it != graph.end(); it++) {
		for (auto a : it->second) {
			inDeg[a.nombre]++;
		}
	}

	queue<string> q;
	for (auto it = inDeg.begin(); it != inDeg.end(); it++) {
		if (it->second == 0) q.push(it->first);
	}

	while (!q.empty()) {
		string s = q.front(); q.pop();
		recetas.push_back(s);
		for (auto it = graph[s].begin(); it != graph[s].end(); it++) {
			if (--inDeg[it->nombre] == 0) q.push(it->nombre);
		}
	}
}


bool solve() {
	int B;

	cin >> B;
	if (!cin) return false;
	int N;
	cin >> N;
	unordered_map<string, vector<receta>> graph, graphInverse;
	string nombre, previo, extra;
	int coste, prest;

	for (int i = 0; i<N; ++i) {
		cin >> nombre >> previo >> extra >> coste >> prest;
		graph[previo].emplace_back(receta(nombre, coste, prest));
		graph[nombre];
		graphInverse[nombre].emplace_back(receta(previo, coste, prest));
	}

	//Recorriendo m hallamos los nodos base
	//Hallamos las mejores formas de crear cada plato
	vector<string> topo;
	findBestTopo(graph, topo);
	graph.clear();

	vector<receta> recetas;
	unordered_map<string, int> index;
	for (auto e : topo) {
		if (graphInverse.count(e) == 1) {
			receta aux("", INT_MAX, -1);
			for (auto r : graphInverse[e]) {
				if (index.count(r.nombre) == 1)
				{
					int i = index[r.nombre];
					if (recetas[i].coste < aux.coste || (recetas[i].coste == aux.coste
						&& recetas[i].prestigio > aux.prestigio))
						aux = receta(e, recetas[i].coste + r.coste, recetas[i].prestigio + r.prestigio);
				}
				else
				{
					if (r.coste < aux.coste || (r.coste == aux.coste && r.prestigio > aux.prestigio))
						aux = receta(e, r.coste, r.prestigio);
				}
			}
			recetas.push_back(aux);
			index[aux.nombre] = recetas.size() - 1;
		}
	}

	index.clear();
	topo.clear();
	graphInverse.clear();
	//Creamos la tabla para DP,
	vector<vector<par>> tabla(recetas.size() + 1, vector<par>(B + 1, par(-1, -1)));
	tabla[recetas.size()] = vector<par>(B + 1, par(0, 0));

	maxPrestigeKnapSack01(B, tabla, recetas, 0, 0);
	cout << tabla[0][0].x << '\n';
	cout << tabla[0][0].y << '\n';

	return true;
}

int main() {
/*
#ifndef DOMJUDGE
	std::ifstream cin("datos.txt");
	auto cinbuf = std::cin.rdbuf(cin.rdbuf());
	std::ofstream cout("res.txt");
	auto coutbuf = std::cout.rdbuf(cout.rdbuf());
#endif
*/
	while (solve());

/*
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
#endif
*/
	return 0;
}
