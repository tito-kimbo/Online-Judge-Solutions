#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double PI = 2 * acos(0.0);

bool solve() {
	double l;
	cin >> l;
	if (!cin) return false;

	double A_sq = l*l, A = PI*A_sq;
	double A1, A2, A3;

	//The length of the chord and the area of the segment
	double sq_l, area_seg;
	//The sector has 30º
	sq_l = sqrt(2*A_sq*(1-cos(30.0*PI/180.0)));
	//A_sector - A_isoscTriangle
	area_seg = 30/360.0 * A - 0.5*sq_l*sqrt(A_sq - 0.25*sq_l*sq_l);

	A1 = sq_l*sq_l + 4*area_seg;
	A2 = (A - 2 * A_sq) - 2*A1;
	A3 = A_sq - (A1 + A2);

	cout << setprecision(3) << fixed << A1 << ' ' << A2 << ' ' << A3 << '\n';

	return true;
}

int main() {
	while (solve());
}