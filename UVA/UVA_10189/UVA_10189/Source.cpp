#include <iostream>
#include <vector>
using namespace std;

void addIfPossible(vector<vector<int>> & v, int x, int y, const int &m, const int &n) {
	if (x >= 0 && x < m && y >= 0 && y < n && v[x][y]!=-1) {
		v[x][y]++;
	}
}

bool solve(int counter) {
	int m, n;

	cin >> m >> n;
	if (m == 0 && n == 0) {
		return false;
	}
	if(counter!=1) 	cout << '\n';

	vector<vector<int>> v(m,vector<int>(n));
	char aux;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> aux;
			if (aux == '*') {
				v[i][j] = -1;
				for (int x = i - 1; x < i + 2; ++x) {
					for (int y = j - 1; y < j + 2; ++y) {
						addIfPossible(v, x, y, m, n);
					}
				}
			}
		}
	}

	cout << "Field #" << counter << ':' << '\n';
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == -1) {
				cout << '*';
			}
			else {
				cout << v[i][j];
			}
		}
		cout << '\n';
	}

	return true;
}

int main() {
	int counter=1;
	while (solve(counter)) {
		counter++;
	}
}