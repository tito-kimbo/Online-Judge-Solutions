#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double EPS = 0.000000001;
const double PI = 2 * acos(0.0);

double volume(int const& D, double const& d) {
	double alpha = D*D - d*d;
	return (PI / 4.0)*(d*alpha+(D-d)*alpha/3.0);
}

bool solve() {
	int D, V;

	cin >> D >> V;
	if (D == 0 && V == 0) return false;

	//Binary search the answer
	double d = pow(D*D*D-6*V/PI , 1/3.0);

	cout << setprecision(3) << fixed << d << '\n';

	return true;
}

int main() {
	while (solve());
}