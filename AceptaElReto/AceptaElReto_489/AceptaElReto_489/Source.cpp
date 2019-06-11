#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve() {
	int N, M;

	cin >> N >> M;
	if (!cin) return false;

	vector<int> grupos(N), aulas(M);

	for (int i = 0; i < N; ++i) cin >> grupos[i];
	for (int i = 0; i < M; ++i) cin >> aulas[i];
	if (N > M) { cout << "NO\n"; return true; }

	sort(grupos.begin(), grupos.end());
	sort(aulas.begin(), aulas.end());
	//Greedy
	int ig, ia;
	ig = ia = 0;

	while (ig < N && ia < M) {
		if (grupos[ig] <= aulas[ia]) {
			++ig;
			++ia;
		}
		else {
			++ia;
		}
	}

	if (ig == N) cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main(){
	while (solve());
}