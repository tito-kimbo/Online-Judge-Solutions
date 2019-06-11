#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

void factor(int &b, int &c) {
	while (b % 2 == 0 && c % 2 == 0) {
		b /= 2;
		c /= 2;
	}
	int aux = b;
	for (int i = 3; i <= aux; i+=2) {
		while (b % i == 0 && c%i == 0) {
			b /= i;
			c /= i;
		}
	}
}

void show(int &a, int &b, int &c, const bool neg) {
	int upper_lower_spaces, fraction_marker;

	//Factoring b and c
	factor(b, c);

	//Calculation of upper and lower spaces
	upper_lower_spaces = 0;
	fraction_marker = 0;
	
	int aux = a;
	while (aux != 0) {
		aux /= 10;
		upper_lower_spaces++;
	}

	//Calculation of fraction marker
	aux = c;
	while (aux != 0) {
		aux /= 10;
		fraction_marker++;
	}

	if (neg) {
		upper_lower_spaces+=2;
	}

	if (b != 0) {
		for (int i = 0; i < upper_lower_spaces; ++i) {
			cout << ' ';
		}
		cout << setw(fraction_marker) << b << '\n';
	}

	if (neg) cout << "- ";
	if (a != 0) cout << a;

	if (b != 0) for (int i = 0; i < fraction_marker; ++i) cout << '-';
	cout << '\n';

	if (b != 0) {
		for (int i = 0; i < upper_lower_spaces; ++i) {
			cout << ' ';
		}
		cout << c << '\n';
	}
}

bool solve(int i) {
	int n, aux, sum;

	cin >> n;
	if (n == 0) return false;

	cout << "Case " << i << ":\n";
	sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		sum += aux;
	}

	int a, b, c;


	a = abs(sum / n);
	b = abs(sum % n);
	c = n;

	//Now formatting occurs
	if (a == 0 && b == 0) cout << 0 << '\n';
	else	show(a, b, c, sum<0);

	return true;
}

int main() {
	int i = 1;
	while (solve(i)) {
		i++;
	}
}