#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//O(n) caso medio, O(n^2) caso peor
void solveQueue(int n) {
	unordered_map<int, int> chapterToTimes;
	queue<int> q;
	int aux, max;

	max = 0;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		q.push(aux);
		chapterToTimes[aux]++;
		if (chapterToTimes[aux] > 1) {
			while (q.front() != aux) {
				chapterToTimes[q.front()]--;
				q.pop();
			}
			q.pop();
			chapterToTimes[aux]--;
		}
		//std se incluye por cuestiones de ambiguedad
		max = std::max((int)q.size(), max);
	}
	cout << max << '\n';
}

/*
Se puede resolver con dos mapas, uno de posicion a capitulo y otro de capitulo a posicion,
siguiendo una idea similar a la anterior.
*/

int main() {
	int nCasos, capitulos;

	cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) {
		cin >> capitulos;
		solveQueue(capitulos);
	}
}
