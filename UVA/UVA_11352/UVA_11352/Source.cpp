#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void setTrue(int i, int j, const int &m, const int &n, vector<vector<bool>> &memo) {
	if (i >= 0 && i < m && j >= 0 && j < n) {
		memo[i][j] = true;
	}
}

void mark(int i, int j, const int &m, const int &n, vector<vector<bool>> &memo) {
	memo[i][j] = true;
	setTrue(i + 2, j + 1, m, n, memo);
	setTrue(i + 2, j - 1, m, n, memo);
	setTrue(i - 2, j + 1, m, n, memo);
	setTrue(i - 2, j - 1, m, n, memo);
	setTrue(i + 1, j + 2, m, n, memo);
	setTrue(i - 1, j + 2, m, n, memo);
	setTrue(i + 1, j - 2, m, n, memo);
	setTrue(i - 1, j - 2, m, n, memo);
}

void add(int i, int j, int &dist, queue<int> &q, const int &m, const int &n, vector<vector<bool>> &memo) {
	if (i >= 0 && j >= 0 && i < m && j < n && !memo[i][j]) {
		q.push(i);
		q.push(j);
		q.push(dist + 1);
		memo[i][j] = true;
	}
}

bool busquedaAnchura(int i, int j, int goalI, int goalJ, int & totalD, 
	const int &m, const int &n, vector<vector<bool>> &memo) {

	bool reached = false;
	queue<int> next; //3 coordinates every time

	int currentI, currentJ, distance;
	
	next.push(i);
	next.push(j);
	next.push(0);

	while (!next.empty()) {
		currentI = next.front();
		next.pop();
		currentJ = next.front();
		next.pop();
		distance = next.front();
		next.pop();
		//Check for ending condition
		if (currentI == goalI && currentJ == goalJ) {
			reached = true;
			break;
		}
		//Push all of the coordinates around if possible
		add(currentI + 1, currentJ, distance, next, m, n, memo);
		add(currentI + 1, currentJ + 1, distance, next, m, n, memo);
		add(currentI + 1, currentJ - 1, distance, next, m, n, memo);
		add(currentI, currentJ + 1, distance, next, m, n, memo);
		add(currentI, currentJ - 1, distance, next, m, n, memo);
		add(currentI - 1, currentJ, distance, next, m, n, memo);
		add(currentI - 1, currentJ + 1, distance, next, m, n, memo);
		add(currentI - 1, currentJ - 1, distance, next, m, n, memo);
	}
	totalD = distance;

	return reached;
}

void solve() {
	int m, n;

	cin >> m >> n;
	cin.get();

	int initI, initJ, goalI, goalJ, distance;
	char aux;
	vector<vector<bool>> memo(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> aux;
			if (aux == 'Z') mark(i, j, m, n, memo);
			else if (aux == 'A') {
				initI = i;
				initJ = j;
			}
			else if (aux == 'B') {
				goalI = i;
				goalJ = j;
			}
		}
	}
	memo[initI][initJ] = true;
	memo[goalI][goalJ] = false;
	if (busquedaAnchura(initI, initJ, goalI, goalJ, distance, m,n, memo)) {
		cout << "Minimal possible length of a trip is " << distance << '\n';
	} else {
		cout << "King Peter, you can't go now!\n";
	};

}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}