#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void mark(char piece, int row, int col, bool threat[8][8], bool occupied[8][8]) {
	if (piece == 'P') {
		if (row - 1 >= 0) {
			if (col - 1 >= 0) threat[row-1][col - 1] = true;
			if (col + 1 < 8) threat[row-1][col + 1] = true;
		}
	}
	else if (piece == 'p') {
		if (row + 1 < 8) {
			if (col - 1 >= 0) threat[row + 1][col - 1] = true;
			if (col + 1 < 8) threat[row + 1][col + 1] = true;
		}
	}
	else if (piece == 'N' || piece == 'n') {
		if (row + 2 < 8) {
			if (col - 1 >= 0) threat[row + 2][col - 1] = true;
			if (col + 1 < 8) threat[row + 2][col + 1] = true;
		}
		if (row - 2 >= 0) {
			if (col - 1 >= 0) threat[row - 2][col - 1] = true;
			if (col + 1 < 8) threat[row - 2][col + 1] = true;
		}
		if (col + 2 < 8) {
			if (row - 1 >= 0) threat[row - 1][col + 2] = true;
			if (row + 1 < 8) threat[row + 1][col + 2] = true;
		}
		if (col - 2 >= 0) {
			if (row - 1 >= 0) threat[row - 1][col - 2] = true;
			if (row + 1 < 8) threat[row + 1][col - 2] = true;
		}
	}
	else if (piece == 'B' || piece == 'b') {
		int first, second;

		first = row+1;
		second = col+1;
		while (first < 8 && second < 8 && !occupied[first][second]) {
			threat[first][second] = true;
			first++;
			second++;
		}

		first = row-1;
		second = col-1;
		while (first >= 0 && second >= 0 && !occupied[first][second]) {
			threat[first][second] = true;
			first--;
			second--;
		}

		first = row-1;
		second = col+1;
		while (first >= 0 && second < 8 && !occupied[first][second]) {
			threat[first][second] = true;
			first--;
			second++;
		}
		
		first = row+1;
		second = col-1;
		while (first < 8 && second >= 0 && !occupied[first][second]) {
			threat[first][second] = true;
			first++;
			second--;
		}
	}
	else if (piece == 'R' || piece == 'r') {
		int first, second;

		first = row-1;
		second = col;
		while (first >= 0 && !occupied[first][second]) {
			threat[first][second] = true;
			first--;
		}
		first = row+1;
		second = col;
		while (first < 8 && !occupied[first][second]) {
			threat[first][second] = true;
			first++;
		}
		first = row;
		second = col-1;
		while (second >= 0 && !occupied[first][second]) {
			threat[first][second] = true;
			second--;
		}
		first = row;
		second = col+1;
		while (second < 8 && !occupied[first][second]) {
			threat[first][second] = true;
			second++;
		}
	}
	else if (piece == 'Q' || piece == 'q') {
		mark('r', row, col, threat, occupied);
		mark('b', row, col, threat, occupied);
	}
	else { //piece = 'K' or piece = 'k'
		if (row - 1 >= 0) threat[row - 1][col] = true;
		if (row + 1 < 8) threat[row + 1][col] = true;
		if (col - 1 >= 0) threat[row][col - 1] = true;
		if (col + 1 < 8) threat[row][col + 1] = true;

		if (row + 1 < 8 && col + 1 < 8) threat[row + 1][col + 1] = true;
		if (row - 1 >= 0 && col - 1 >= 0) threat[row - 1][col - 1] = true;
		if (row + 1 < 8 && col - 1 >= 0) threat[row + 1][col - 1] = true;
		if (row - 1 >= 0 && col + 1 < 8) threat[row - 1][col + 1] = true;
	}
}

bool solve() {
	string line;

	getline(cin, line);
	if (!cin) return false;

	bool threatened[8][8] = { false }, occupied[8][8] = { false };
	int row, col;

	row = col = 0;
	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == '/') {
			row++;
			col = 0;
		}
		else if ('0' <= line[i] && line[i] <= '8') col += line[i] - '0';
		else {
			occupied[row][col] = true;
			col++;
		}
	}
	row = col = 0;
	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == '/') {
			row++;
			col = 0;
		}
		else if ('0' <= line[i] && line[i] <= '8') col += line[i] - '0';
		else {
			mark(line[i], row, col, threatened, occupied);
			col++;
		}
	}

	int sum = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (!threatened[i][j] && !occupied[i][j]) sum++;
		}
	}
	cout << sum << '\n';
	return true;
}

int main() {
	while (solve());
}