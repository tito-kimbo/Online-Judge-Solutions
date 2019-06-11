#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

bool solve() {
	long long int a, b;
	cin >> a;
	if (!cin) return false;
	cin >> b;
	cout << abs(a - b) << '\n';
	return true;
}

int main() {
	while (solve());
}