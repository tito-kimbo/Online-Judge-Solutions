#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double PI = 2 * acos(0.0);

bool solve() {
	int l, w, h, theta;

	cin >> l >> w >> h >> theta;
	if (!cin) return false;

	double angle = (double)theta*PI / 180.0;
	double volume = l*w*h; //to get mL
	double limitAngle = PI/2 - atan((double)l / (double)h);

	//cout << "LIMIT ANGLE: " << limitAngle * 180 / PI << '\n';
	if (angle <= limitAngle) {
		double m = l*tan(angle);
		volume -= 0.5*l*m*w;
	} else { //theta > 45 deg
		double triangL;
		angle = PI / 2.0 - angle;

		//cout << "New angle: " << angle*180/PI << '\n';
		triangL = h*tan(angle);
		//cout << "Angle tangent: " << tan(angle) << '\n';
		//cout << "TriangL: " << triangL << '\n';
		volume = (0.5*triangL*h)*w;
	}

	cout << setprecision(3) << fixed << volume << " mL\n";
	return true;
}

int main() {
	while (solve());
}