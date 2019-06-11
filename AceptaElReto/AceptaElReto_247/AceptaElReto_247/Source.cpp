#include <iostream>
using namespace std;

bool resolver(int n) {
	int last, next;
	bool isTrue;

	cin >> last;
	isTrue = true;
	for (int i = 1; i < n; ++i) {
		cin >> next;

		isTrue = isTrue && next > last;

		last = next;
	}

	return isTrue;
}

int main() {
	int n;

	cin >> n;
	while (n != 0) {
		if (resolver(n)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}

		cin >> n;
	}
}