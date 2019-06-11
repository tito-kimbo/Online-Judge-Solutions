#include <iostream>
using namespace std;

bool solve() {
	int N, B, H, W;

	cin >> N >> B >> H >> W;
	if (!cin) return false;

	int minCost = -1;
	int perPerson;

	int aux, temp;
	for (int i = 0; i < H; ++i) {
		cin >> perPerson;
		for (int j = 0; j < W; ++j) {
			cin >> aux;

			temp = N*perPerson;
			if (aux >= N && temp < B) {
				if (minCost == -1 || temp < minCost) {
					minCost = temp;
				}
			}
		}
	}

	if (minCost == -1) {
		cout << "stay home\n";
	}
	else{
		cout << minCost << '\n';
	}

	return true;
}

int main() {
	while (solve());
}