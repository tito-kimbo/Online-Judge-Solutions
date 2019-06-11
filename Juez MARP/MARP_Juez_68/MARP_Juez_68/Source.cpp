#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int LIMIT = 24 * 60 + 10 + 1;

struct tPelicula {
	int inicio, duracion;
};

bool operator<(const tPelicula &t1, const tPelicula &t2) { return t1.inicio < t2.inicio ||
	(t1.inicio == t2.inicio && t1.duracion > t2.duracion); }
bool operator>(const tPelicula &t1, const tPelicula &t2) { return t1.inicio > t2.inicio ||
(t1.inicio == t2.inicio && t1.duracion < t2.duracion); }
istream &operator >> (istream &in, tPelicula &p) {
	int aux;
	in >> p.inicio;
	p.inicio *= 60;
	in.get();
	in >> aux;
	p.inicio += aux;
	in >> p.duracion;
	return in;
}

int dp(int i, int j, vector<tPelicula> &peliculas, vector<vector<int>> &m) {
	int a1, a2;
	a1 = a2 = 0;
	if (i >= peliculas.size() || j > peliculas[peliculas.size()-1].inicio) return 0;
	else if (m[i][j] != - 1) return m[i][j];
	else {
		//No veo la pelicula actual
		a1 = dp(i + 1, j, peliculas, m);
		int aux = peliculas[i].inicio + peliculas[i].duracion + 10;
		//Veo la pelicula actual
		if(j <= peliculas[i].inicio) a2 = dp(i + 1, aux, peliculas, m) + peliculas[i].duracion;
	}
	m[i][j] = max(a1, a2);
	return m[i][j];
}

int dpOptim(int i, vector<tPelicula> &peliculas, vector<int> &m) {
	int aux;
	while (i < peliculas.size()) {
		aux = peliculas[i].inicio + peliculas[i].duracion + 10;
		for (int k = m.size()-1; k >= aux; --k) {
			m[k] = max(m[k], m[peliculas[i].inicio]+peliculas[i].duracion);
		}
		++i;
	}
	return m[m.size()-1];
}

bool solve() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<tPelicula> peliculas(n);
	for (int i = 0; i < n; ++i) cin >> peliculas[i];
	sort(peliculas.begin(), peliculas.end());

	//LIMIT es la cota superior de la hora de fin
	vector<int> m(LIMIT,0);
	cout << dpOptim(0,peliculas, m) << '\n';

	return true;
}

int main() {
	while (solve());
}