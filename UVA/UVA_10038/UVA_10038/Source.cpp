#include <iostream>
#include <cmath>
using namespace std;

bool solve() {
	bool jolly = true;
	int n, current, next;

	cin >> n;
	if (!cin) return false;
	bool marks[3000 + 5] = { false };
	
	cin >> current;
	for (int i = 0; i < n - 1; ++i) {
		cin >> next;
		marks[abs(current - next)] = true;
		current = next;
	}

	for (int j = 1; j < n && jolly; ++j) {
		if (!marks[j]) jolly = false;
	}
	if (jolly) {
		cout << "Jolly\n";
	}
	else {
		cout << "Not jolly\n";
	}
	return true;
}

int main() {
	while (solve());
}