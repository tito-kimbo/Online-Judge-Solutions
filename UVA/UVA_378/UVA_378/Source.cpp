#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

const double EPS = 0.000000001;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

istream & operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

ostream & operator << (ostream &out, point &p) {
	out << fixed << setprecision(2) << p.x << ' ' << p.y;
	return out;
}

struct line {
	double a, b, c;
	line(point p1, point p2) {
		if (fabs(p1.x - p2.x) < EPS) {
			a = 1.0; b = 0.0; c = -p1.x;
		}
		else {
			a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
			b = 1.0;
			c = -(double)(a*p1.x) - p1.y;
		}
	}
};

bool areParallel(line l1, line l2) {
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c-l2.c)<EPS);
}

bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;
	p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x+l1.c);
	else p.y = -(l2.a*p.x + l2.c);
	return true;
}

void solve() {
	point p1, p2, p3, p4,intersect;

	cin >> p1 >> p2 >> p3 >> p4;
	line l1(p1, p2), l2(p3, p4);

	if (areSame(l1,l2)) {
		cout << "LINE\n";
	} else if(areIntersect(l1,l2,intersect)) {
		cout << "POINT " << intersect << '\n';
	} else {
		cout << "NONE\n";
	}
}

int main() {
	int n;
	cin >> n;
	cout << "INTERSECTING LINES OUTPUT\n";
	for (int i = 0; i < n; ++i) {
		solve();
	}
	cout << "END OF OUTPUT\n";
}