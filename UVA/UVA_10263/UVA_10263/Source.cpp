#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPS = 0.000000001;

struct point {
	double x, y;
	point() { x = y = 0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

ostream &operator<<(ostream &out, point p) {
	out << p.x << '\n';
	out << p.y << '\n';
	return out;
}

struct vec {
	double x, y;
	vec() { x = y = 0; }
	vec(double _x, double _y) : x(_x), y(_y) {}
	vec(point p1, point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {};

	double norm_sq() { return x*x + y*y; }
};

double dot_product(vec v1, vec v2) {
	return (v1.x*v2.x + v1.y*v2.y);
}

//Scale a vector by d
vec scale(vec v, double d) {
	return vec(v.x*d, v.y*d);
}

double distance(const point &p1, const point &p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

//Distance from P to the line AB
double distance(const point &p, const point &a, const point &b, point &c) {
	//c = a + u*ab;
	vec ap(a, p), ab(a, b);
	double u = dot_product(ap, ab) / ab.norm_sq();
	if (u < EPS) u = 0.0;
	else if (fabs(1.0 - u) > EPS && u > 1.0) u = 1.0;
	c = translate(a, scale(ab,u));
	return distance(p, c);
}

bool solve() {
	point M;

	cin >> M.x;
	if (!cin) return false;
	cin >> M.y;
	int n;
	cin >> n;
	point A, B, C, minPoint;
	double minDistance;
	
	cin >> A.x >> A.y;
	if (n == 0) minPoint = A;
	else {
		cin >> B.x >> B.y;
		minDistance = distance(M, A, B, C);
		minPoint = C;
		double d;
		for (int i = 0; i < n - 1; ++i) {
			A.x = B.x;
			A.y = B.y;
			cin >> B.x >> B.y;
			d = distance(M, A, B, C);
			if (fabs(d - minDistance) > EPS && d < minDistance) {
				minDistance = d;
				minPoint = C;
			}
		}
	}
	cout << setprecision(4) << fixed << minPoint;
	

	return true;
}

int main() {
	while (solve());
}