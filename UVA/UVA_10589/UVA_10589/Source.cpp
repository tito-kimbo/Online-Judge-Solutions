#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

const double EPS = 0.0;

struct point {
	double x, y;
	point() : x(0.0), y(0.0) {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

double distance(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct circle {
	point center;
	double radius;

	circle() : center(), radius(0.0) {}
	circle(point _p, double _r) : center(_p), radius(_r) {}
};

bool isInsideCircle(point p, circle c) {
	return c.radius - distance(p, c.center) > -EPS;
}

bool solve(){
	int N, a;

	cin >> N >> a;
	if (N == 0) return false;

	point center1(0.0,0.0), center2(0.0, a), center3(a,0.0), center4(a,a);
	circle c1(center1, a), c2(center2, a), c3(center3, a), c4(center4, a);
	int M = 0;

	double x, y;
	point p;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		p = point(x, y);
		if (isInsideCircle(p, c1) && isInsideCircle(p, c2) &&
			isInsideCircle(p, c3) && isInsideCircle(p, c4)) {
			M++;
		}
	}
	//approximate
	double area = (double)M*a*a / (double)N;
	cout << setprecision(5) << fixed << area << '\n';
	return true;
}

int main() {
	while (solve());
}