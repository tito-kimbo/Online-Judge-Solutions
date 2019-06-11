#include <iostream>
#include <vector>

//REACH FROM v[n][0] to v[0][n]
int DPSolution(int n, std::vector<std::vector<char>> & m) {
	std::vector<std::vector<int>> calculation;
	int nextRow, nextCol;
	
	for (int i = 0; i < n; ++i) {
		std::vector<int> aux;
		for (int j = 0; j < n; ++j) {
			aux.push_back(0);
		}
		calculation.push_back(aux);
	}
	calculation[n-1][0] = 1;

	nextRow = n-1;
	nextCol = 1;

	while (nextRow >= 0) {
		while (nextCol < n) {
			if (nextCol != 0) {
				calculation[nextRow][nextCol] += calculation[nextRow][nextCol-1];
			}

			if (nextRow != n-1) {
				calculation[nextRow][nextCol] += calculation[nextRow+1][nextCol];
			}

			if (m[nextRow][nextCol] == 'X') {
				calculation[nextRow][nextCol] = 0;
			}
			nextCol++;
		}
		nextCol = 0;
		nextRow--;
	}
	return calculation[0][n-1];
}

bool resolver() {
	int n;
	char c;
	std::vector<std::vector<char>> matrix;

	std::cin >> n;
	if (n == 0) return false;

	for (int i = 0; i < n; ++i) {
		std::vector<char> aux;
		for (int j = 0; j < n; ++j) {
			std::cin >> c;
			aux.push_back(c);
		}
		matrix.push_back(aux);
	}

	std::cout << DPSolution(n, matrix) << '\n';

	return true;
}

int main() {
	while (resolver());
}