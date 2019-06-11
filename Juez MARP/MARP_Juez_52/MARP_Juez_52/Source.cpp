#include <iostream>
#include <vector>
#include <math.h>
#include <functional>
#include <algorithm>
using namespace std;

bool solve() {
	int N;
	cin >> N;
	if (N == 0) return false;

	vector<int> v1(N), v2(N);
	for (int i = 0; i < N; ++i) cin >> v1[i];
	for (int j = 0; j < N; ++j) cin >> v2[j];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<int>());

	//Dados los limites el algoritmo es probablemente cuadrático
	//El caso de ejemplo es confuso - ¿es posible que se quieran minimizar los partidos perdidos?
	long long int sum = 0;
	for (int i = 0; i < N; ++i) {
		if(v1[i]<v2[i]) sum += v2[i]-v1[i];
	}
	cout << sum << '\n';
	return true;
}

int main() {
	while (solve());
}