#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 0.0000001;

struct point {
	double x, y;
	point() : x(0.0), y(0.0) {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

double distance(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

point midPoint(point p1, point p2) {
	return point(0.5*(p1.x + p2.x), 0.5*(p1.y + p2.y));
}

struct circle {
	point center;
	double radius;

	circle(point p1, double r) : center(p1), radius(r) {}
};

double distance(point p, circle c) {
	return distance(p, c.center);
}

bool isInCircle(point p, circle c) {
	return c.radius - distance(p, c) > -EPS;
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true;
} // to get the other center, reverse p1 and p2

bool isValid(point center, double radius, vector<point> points) {
	circle c(center, radius);

	for (int i = 0; i < points.size(); ++i) {
		if (!isInCircle(points[i], c)) return false;
	}

	return true;
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;

	vector<point> v(n);
	int x, y;
	double maxDist = 0.0;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		point p(x,y);
		v[i] = p;
	}
	double rad;
	cin >> rad;
	//Initialize centers
	bool valid = false;
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			point c;
			circle2PtsRad(v[i], v[j], rad, c);
			if (isValid(c, rad, v)) {
				valid = true;
				break;
			}
			circle2PtsRad(v[j], v[i], rad, c);
			if (isValid(c, rad, v)) {
				valid = true;
				break;
			}
		}
	}

	if (valid) {
		cout << "The polygon can be packed in the circle.\n";
	}
	else {
		cout << "There is no way of packing that polygon.\n";
	}


	return true;
}

int main() {
	while (solve());
}