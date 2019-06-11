#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <math.h>
using namespace std;

const int INF = 5000000;
const int MAX_N = 2004;

struct point {
	int x, y;
	point() {}
};

istream & operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

int distance(point a, point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}


/*
long long int solveAssignmentProblem(vector<vector<int>> const& a) {
	int n = a.size() - 1;
	int m = a[0].size() - 1;
	vector<int> u(n + 1), v(m + 1), p(m + 1), way(m+1);
	for (int i = 1; i <= n; ++i) {
		p[0] = i;
		int j0 = 0;
		vector<int> minv(m + 1, INF);
		vector<bool> used(m + 1);

		do {
			used[j0] = true;
			int i0 = p[j0];
			int delta = INF;
			int j1 = 0;
			for (int j = 1; j <= m; ++j)
				if (!used[j]) {
					int cur = a[i0][j] - u[i0] - v[j];
					if (cur < minv[j]) {
						minv[j] = cur;
						way[j] = j0;
					}
					if (minv[j] < delta) {
						delta = minv[j];
						j1 = j;
					}
				}
			for (int j = 0; j <= m; ++j)
				if (used[j]) {
					u[p[j]] += delta;
					v[j] -= delta;
				}
				else 
					minv[j] -= delta;
			j0 = j1;
		} while (p[j0] != 0);

		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
			//cout << (j0 != 0) << '\n';
		} while (j0 != 0);
	}

	return -v[0];
}*/

int solveAssignmentProblem(vector<vector<int>> const &a) {
	int n = a.size() - 1, m = a[0].size() - 1;
	vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
	for (int i = 1; i <= n; ++i) {
		p[0] = i;
		int j0 = 0;
		vector<int> minv(m + 1, INF);
		vector<bool> used(m + 1);
		do {
			used[j0] = true;
			int i0 = p[j0], delta = INF, j1 = 0;
			for (int j = 1; j <= m; ++j) {
				if (!used[j]) {
					int cur = a[i0][j] - u[i0] - v[j];
					if (cur < minv[j]) {
						minv[j] = cur;
						way[j] = j0;
					}
					if (minv[j] < delta) {
						delta = minv[j];
						j1 = j;
					}
				}
			}
			for (int j = 0; j <= m; ++j) {
				if (used[j]) {
					u[p[j]] += delta;
					v[j] -= delta;
				}
				else 
					minv[j] -= delta;
			}
			j0 = j1;
		} while (p[j0] != 0);

		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0 != 0);
	}
	return -v[0];
}

point bottles[MAX_N], couriers[2 * MAX_N];
bool solve() {
	int N,M;

	cin >> N >> M;
	if (N == 0 && M == 0) return false;
	//vector<point> bottles(N), couriers(N+(M-1));
	point restaurant;
	for (int i = 0; i < N; ++i) {
		cin >> bottles[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> couriers[i];
	}
	cin >> restaurant;
	for (int i = M; i < N + (M-1); ++i) {
		couriers[i] = restaurant;
	}
	
	int m = M+(N-1), n = N;
	vector<vector<int>> matrix(n+1, vector<int>(m+1, 0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (distance(bottles[j], restaurant) != 0) 
				matrix[j+1][i+1] = (distance(bottles[j], couriers[i])+distance(bottles[j],restaurant));
		}
	}

	//NOW HUNGARIAN ALGORITHM (KUHN-MUNKRES, O(n^3))
	//Extract answer
	cout << solveAssignmentProblem(matrix) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	while (solve());
}