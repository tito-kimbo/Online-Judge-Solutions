#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool solve() {
	string line;

	getline(cin, line);
	if (!cin) return false;

	for (int i = 0; i < line.size(); ++i) {
		if (!('A' <= line[i] && 'Z' >= line[i]) && !('a' <= line[i] && 'z' >= line[i])) {
			line[i] = ' ';
		}
	}

	long long int count = 0;
	stringstream s(line);

	while (s) {
		s >> line;
		count++;
	}
	count--;

	cout << count << '\n';
	return true;
}

int main() {
	while (solve());
}