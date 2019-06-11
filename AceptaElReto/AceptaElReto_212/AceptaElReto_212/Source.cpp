#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

//TEOREMA 1: Un multigrafo tiene un camino (=>No circular) euleriano sii 
//todos sus vértices tienen orden par salvo 2

//TEOREMA 2: Un multigrafo tiene un circuito (ciclo) euleriano sii
//todos sus vértices tienen grado par
bool resolver(int edges) {
	int from, to, nodes, odd;

	cin >> nodes;
	VI v(nodes); //Mantiene los grados de los vertices

	for (int i = 0; i < edges; ++i){
		cin >> from;
		cin >> to;

		v[from-1]++;
		v[to-1]++;
	}

	odd = 0;
	for (int i = 0; i < nodes; ++i) {
		if (v[i] % 2 != 0) {
			odd++;
		}
	}
	return odd == 2 || odd == 0;
}

int main() {
	int n;

	cin >> n;
	while (n != 0) {
		if (resolver(n)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
		cin >> n;
	}
}