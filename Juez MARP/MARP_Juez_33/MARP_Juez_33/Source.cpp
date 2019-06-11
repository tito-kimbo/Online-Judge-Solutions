#include <iostream>
#include <vector>
using namespace std;

vector<int> d1 = { -1, 0, 1, 0 };
vector<int> d2 = { 0, -1, 0, 1 };

void floodfill(vector<vector<bool>> &v, int p1, int p2, bool const& old, bool const& newV) {
	int newX, newY;
	for (int i = 0; i < 4; ++i) {
		newX = p1 + d1[i];
		newY = p2 + d2[i];
		v[p1][p2] = newV;
		if (newX >= 0 && newX < v.size() && newY >= 0 && newY < v[0].size() && v[newX][newY] == old) {
			floodfill(v, newX, newY, old, newV);
		}
	}
}

bool solve() {
	int M, N;
	cin >> M >> N;
	if (!cin) return false;
	vector<vector<bool>> photo(N, vector<bool>(M,false));

	char c;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> c;
			if (c == 'X') photo[i][j] = true;
		}
	}

	//We floodfill the graph's outer white space
	floodfill(photo, 0, 0, false, true);
	//We count the distinct white components
	/*for (auto v : photo) {
		for (auto e : v) {
			cout << e << ' ';
		}
		cout << '\n';
	}*/

	int n = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!photo[i][j]) {
				n++;
				floodfill(photo, i, j, false, true);
			}
		}
	}

	cout << n << '\n';
	return true;
}

int main() {
	while (solve());
}