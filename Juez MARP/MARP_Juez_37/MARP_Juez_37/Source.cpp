#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include "ConjuntosDisjuntos.h"
using namespace std;

struct edge {
	int from, to, cost;
	edge() {}
	edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}
};

bool operator<(edge e1, edge e2) {
	return e2.cost < e1.cost; //for priority queue sorting
}

bool solve() {
	int I,P;
	cin >> I;
	if (!cin) return false;
	cin >> P;

	priority_queue<edge> pq;
	int from, to, cost;
	for (int i = 0; i < P; ++i) {
		cin >> from >> to >> cost;
		pq.push({ from-1, to-1, cost });
	}

	//Apply Kruskal to find MST
	int added = 0;
	long long int totalCost = 0;
	ConjuntosDisjuntos comp(I);
	while (!pq.empty() && added < I - 1) {
		edge e = pq.top();
		pq.pop();
		int v = e.from, w = e.to;
		if (!(comp.buscar(v) == comp.buscar(w))) {
			comp.unir(v, w);
			totalCost += e.cost;
			added++;
		}
	}
	if (comp.count() <= 1) {
		cout << totalCost << '\n';
	}
	else {
		cout << "No hay puentes suficientes\n";
	}
	return true;
}

int main() {
	while (solve());
}