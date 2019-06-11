#include <iostream>
using namespace std;

bool solve() {
	long long int a, b;

	cin >> a >> b;
	if (!cin) return false;

	cout << (long long int)(a ^ b) << '\n';

	return true;
}

int main() {
	while (solve());
}