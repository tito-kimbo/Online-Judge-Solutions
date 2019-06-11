#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = 10000000;

int floyd(vector<vector<int>> & matrix, map<int,int> &invMagic) {

	for (int k = 0; k < matrix.size(); ++k) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix.size(); ++j) {
				int dt = matrix[i][k] + matrix[k][j];
				if (matrix[i][j] > dt) matrix[i][j] = dt;
			}
		}
	}

	//Devuelve el indice magico utilizando el mapa mágico
	int magic_index = -1, sum = 0, min_sum = INT_MAX;
	for (int i = 0; i < matrix.size(); ++i) {
		sum = 0;
		for (int j = 0; j < matrix.size(); ++j) {
			sum += matrix[i][j];
		}
		if (sum < min_sum || (sum==min_sum && invMagic[magic_index]>invMagic[i])) { //Esto no va con infinitos
			magic_index = i;
			min_sum = sum;
		}
	}

	return invMagic[magic_index];
}

void resuelveCaso(int N, int L) {
	vector<vector<int>> lineas(L, vector<int>());
	map<int, int> principales, principalesInv;
	map<int, int> m;
	bool noCero = true;
	int estacionLeida, nPrincipales = 0;
	for (int i = 0; i < L; i++) {
		noCero = true;
		while (noCero) {
			std::cin >> estacionLeida;
			if (estacionLeida) {
				lineas[i].push_back(estacionLeida);
				m[estacionLeida]++;
				if (m[estacionLeida] == 2) { 
					principales[estacionLeida] = nPrincipales;
					principalesInv[nPrincipales] = estacionLeida;
					++nPrincipales; 
				}

			}
			else noCero = false;
		}
	}

	//GENERAR DIRECTAMENTE LA MATRIZ ES MEJOR
	vector<vector<int>> mFloyd(nPrincipales, vector<int>(nPrincipales, INF));
	for (int i = 0; i < nPrincipales; ++i) mFloyd[i][i] = 0;

	int len = 1, princ1 = -1, aux;
	for (int i = 0; i < L; ++i) {
		princ1 = -1;
		len = 1;
		for (int j = 0; j < lineas[i].size(); ++j) {
			//Encuentras una estacion principal
			if (m[lineas[i][j]] >= 2) {
				//Si ya tienes una, añades una arista
				//Si no, la guardas como estación principal
				if (princ1 == -1) {
					princ1 = principales[lineas[i][j]];
					len = 1;
				}
				else {
					aux = mFloyd[princ1][principales[lineas[i][j]]];
					mFloyd[princ1][principales[lineas[i][j]]] = min(len, aux);
					mFloyd[principales[lineas[i][j]]][princ1] = mFloyd[princ1][principales[lineas[i][j]]];

					princ1 = principales[lineas[i][j]];
					len = 1;
				}
			}
			else ++len;
			//Si no es principal, incrementas el contador de len
		}
	}

	int magia = floyd(mFloyd, principalesInv);
	cout << magia << '\n';
}

int main() {
	int N, L;
	std::cin >> N >> L;
	while (N != 0 && L != 0) {
		resuelveCaso(N, L);
		std::cin >> N >> L;
	}
}