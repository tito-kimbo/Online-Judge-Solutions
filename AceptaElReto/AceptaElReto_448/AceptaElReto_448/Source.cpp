#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<int> VI;

int valorRelativoDado(int n, VI const& dado, VI const& comp) {
	int val, i, j;
	val = i = j = 0;

	int compVal, count;
	while (i < n && j < n) {
		compVal = dado[i];
		count = 0;
		while (i < n && dado[i] == compVal) {
			++i;
			++count;
		}
		while (j < n && comp[j] < compVal) {
			++j;
		}
		val += j*count;
		while (j < n && comp[j] == compVal) {
			++j;
		}
	}
	if (i < n) val += n*(n - i);

	return val;
}

void resolver(int nCaras) {
	VI primer_dado, segundo_dado;
	int aux, score1, score2;

	//LECTURA
	for (int i = 0; i < nCaras; ++i) {
		cin >> aux;
		primer_dado.push_back(aux);
	}
	for (int i = 0; i < nCaras; ++i) {
		cin >> aux;
		segundo_dado.push_back(aux);
	}

	sort(primer_dado.begin(), primer_dado.end());
	sort(segundo_dado.begin(), segundo_dado.end());

	score1 = valorRelativoDado(nCaras, primer_dado, segundo_dado);
	score2 = valorRelativoDado(nCaras, segundo_dado, primer_dado);

	if (score1 > score2) {
		cout << "PRIMERO\n";
	}
	else if (score1 == score2) {
		cout << "NO HAY DIFERENCIA\n";
	}
	else {
		cout << "SEGUNDO\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;

	cin >> n;
	while (n != 0) {
		resolver(n);
		cin >> n;
	}
}