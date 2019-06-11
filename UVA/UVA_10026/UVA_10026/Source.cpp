#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sum(vector<int> &v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	return sum;
}

void solve(bool last) {
	int n;

	cin >> n;
	vector<int> days(n), fines(n);
	vector<bool> used(n, false);

	for (int i = 0; i < n; ++i) {
		cin >> days[i];
		cin >> fines[i];
	}

	bool first = true;
	float maxQuotient, aux;
	int maxQuotientIndex;
	maxQuotientIndex = -1;
	for (int i = 0; i < n; ++i) {
			maxQuotient = 0;
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				aux = (float)fines[j] / (float)days[j];
				if (aux > maxQuotient) {
					maxQuotientIndex = j;
					maxQuotient = aux;
				}
			}
		}
		used[maxQuotientIndex] = true;
		if (!first) cout << ' ';
		else first = false;
		cout << maxQuotientIndex+1;
	}
	cout << '\n';
	if(!last) cout << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)solve(i == n-1);
}