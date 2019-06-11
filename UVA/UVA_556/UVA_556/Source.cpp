#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//Directions: 0 (South) 1 (West) 2 (North) 3 (East) (mod4)
//Turn left: ++(mod4)

void move(int &i, int &j, int &dir, const vector<vector<int>> &m) {

	if (dir == 0) { //South
		if (m[i+1][j] != -1 && m[i + 1][j - 1] == -1) {
			i++;
		}
		else if (m[i + 1][j] != -1) {
			i++;
			dir++;
		}
		else {
			dir = 3;
			move(i, j, dir, m);
		}
	}
	else if (dir == 1) { //West
		if (m[i][j - 1] != -1 && m[i - 1][j - 1] == -1) {
			j--;
		}
		else if (m[i][j - 1] != -1) {
			j--;
			dir++;
		}
		else {
			dir--;
			move(i, j, dir, m);
		}
	}
	else if (dir == 2) { //North
		if (m[i-1][j] != -1 && m[i - 1][j + 1] == -1) {
			i--;
		}
		else if (m[i-1][j] != -1) {
			i--;
			dir++;
		}
		else {
			dir--;
			move(i, j, dir, m);
		}
	}
	else { //dir = 3 //East
		if (m[i][j + 1] != -1 && m[i + 1][j + 1] == -1) {
			j++;
		}
		else if (m[i][j + 1] != -1) {
			j++;
			dir = 0;
		}
		else {
			dir--;
			move(i, j, dir, m);
		}
	}
}

bool solve() {
	int b, w;

	cin >> b >> w;
	if (b == 0 && w == 0) return false;

	vector<vector<int>> maze(b + 2, vector<int>(w + 2, 0));
	char c;
	for (int i = 0; i < b + 2; ++i) {
		maze[i][0] = -1;
		maze[i][w + 1] = -1;
		for (int j = 1; j < w + 1; ++j) {
			if (i == 0 || i == b + 1) maze[i][j] = -1;
			else {
				cin >> c;
				if (c == '1') maze[i][j] = -1;
			}
		}
	}

	/*cout << "MAZE\n";
	for (int i = 0; i < b + 2; ++i) {
		for (int j = 0; j < w + 2; ++j) {
			cout << setw(2) << maze[i][j];
		}
		cout << '\n';
	}
	cout << '\n';*/

	bool cont = true;
	int x = b, y = 1, dir = 3;
	while (cont) {
		//cout << "Current Pos: (" << x << ", " << y << ")\n";
		move(x, y, dir, maze);
		maze[x][y]++;
		if (x == b && y == 1) {
			cont = false;
		}
	}

	//Now count relevant data
	int data[5] = { 0 };

	for (int i = 1; i < b + 1; ++i) {
		for (int j = 1; j < w + 1; ++j) {
			if (maze[i][j] != -1 && maze[i][j] < 5) {
				data[maze[i][j]]++;
			}
		}
	}

	for (int i = 0; i < 5; ++i) {
		cout << setw(3) << data[i];
	}
	cout << '\n';

	return true;
}

int main() {
	while (solve());
}