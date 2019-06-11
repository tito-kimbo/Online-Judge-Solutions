#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int getPoints(const char &c) {
	if (c == '/' || c == 'X') {
		return 10;
	}
	else {
		return c - '0';
	}
}


bool solve() {
	int roll = 0, frame = 0, count = 0, extra = 0;
	int points[24] = { 0 }, bonus[24] = { 0 };
	bool strikes[22] = { false }, spares[22] = { false };
	char current;
	string line;

	getline(cin, line);
	if (line == "Game Over") return false;
	istringstream ss(line);


	while (frame < 10) {
		ss >> current;

		points[roll] = getPoints(current);
		count++;
		if (count == 2 || current == 'X' || current == '/') {
			if (current == 'X') strikes[roll] = true;
			if (current == '/') spares[roll] = true;
			frame++;
			count = 0;
		}
		roll++;
	}
	if (current == 'X') extra = 2;
	if (current == '/') extra = 1;
	for (int i = 0; i < extra; ++i) {
		ss >> current;
		points[roll + i] = getPoints(current);
		if (current == 'X') strikes[roll+i] = true;
		if (current == '/') spares[roll+i] = true;
	}

	//Calculate scores for strikes and spares
	int score = 0;
	for (int i = 0; i < roll; ++i) {
		if (spares[i]) {
			score -= points[i-1];
			bonus[i] += points[i + 1];
		}
	}

	for (int i = 0; i<roll; ++i) {
		if (strikes[i]) {
			if(!spares[i+2]) bonus[i] += points[i + 1];
			bonus[i] += points[i + 2];
		}
	}
	for (int i = 0; i < roll; ++i) {
		score += points[i] + bonus[i];
	}
	
	cout << score << '\n';
	return true;
}

int main() {
	while(solve());
}