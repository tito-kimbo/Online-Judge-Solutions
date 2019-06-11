#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

double largestSide(long long int a, long long int b) {
	double side;

	if (a > b && 4*b <= a) {
		side = b;
	}
	else if (b > a && 4*a <= b) {
		side = a;
	} else {
		side = max(0.5*min(a, b), max(a,b)/4.0);
	}

	return side;
}

bool solve() {
	int n;

	cin >> n;
	if (n == 0) return false;

	long long int a, b;
	double max, aux;
	int maxPos;

	cin >> a >> b;
	max = largestSide(a,b);
	maxPos = 1;

	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		aux = largestSide(a, b);
		if (aux > max) {
			max = aux;
			maxPos = i + 1;
		}
	}

	cout << maxPos << '\n';
	return true;
}

int main() {
	while (solve());
}