#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

const double PI = 2*acos(0.0);

struct triangle {
	double a, b, c; //side lengths
	triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

	double area() {
		double s = 0.5*(a + b + c);

		return sqrt(s*(s - a)*(s - b)*(s - c));
	}

	double radiusCircumcircle() {
		return a*b*c / (4*area());
	}

	double radiusInscribedCircle() {
		double ar = area();

		return (2 * ar) / (a + b + c);
	}
};

double areaCircle(double radius) {
	return PI*radius*radius;
}

bool solve() {
	double a, b, c;

	cin >> a;
	if (!cin) return false;
	cin >> b >> c;

	triangle t(a, b, c);
	double a1, a2, a3;

	a1 = areaCircle(t.radiusCircumcircle());
	a2 = t.area();
	a3 = areaCircle(t.radiusInscribedCircle());
	
	cout << setprecision(4) << fixed << a1-a2 << ' ' << a2-a3 << ' ' << a3 << '\n';
	return true;
}

int main() {
	while (solve());
}