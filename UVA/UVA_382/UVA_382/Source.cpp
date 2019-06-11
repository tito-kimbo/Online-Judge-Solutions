#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool solve() {
	int n, sum;
	cin >> n;
	if (n == 0) return false;

	sum = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}

	cout << setw(5) << n;
	cout << "  ";

	if (sum < n) {
		cout << "DEFICIENT\n";
	}
	else if (sum == n) {
		cout << "PERFECT\n";
	}
	else { //sum > n
		cout << "ABUNDANT\n";
	}

	return true;
}

int main() {
	cout << "PERFECTION OUTPUT\n";
	while (solve());
	cout << "END OF OUTPUT\n";
}