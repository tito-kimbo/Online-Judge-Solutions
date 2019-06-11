#include <iostream>
#include <math.h>
using namespace std;

bool solve() {
	long long int v, t;
	
	cin >> v >> t;
	if (!cin) return false;

	cout << v*2*t << '\n';

	return true;
}

int main() {
	while (solve());
}