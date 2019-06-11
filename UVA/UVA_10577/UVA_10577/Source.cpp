#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;

const double PI = 2 * acos(0.0);
const double EPS = 0.000000001;

struct point{
	double x, y;
	point() { x = y = 0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}

	void rotateCC(double angle) {
		//We suppose angle in radians
		double tempX = x*cos(angle) - y*sin(angle);
		double tempY = x*sin(angle) + y*cos(angle);
		x = tempX;
		y = tempY;
	}

	void rotate90DegCC() {
		double tempX, tempY;
		
		tempX = -y;
		tempY = x;

		x = tempX;
		y = tempY;
	}
};

double norm_sq(vec v){
	return v.x*v.x + v.y*v.y;
}

double distance(point p1, point p2) {
	return sqrt(norm_sq(vec(p2.x-p1.x, p2.y-p1.y)));
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
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
	line(point p, vec v) {
		point p2 = translate(p, v);
		line aux(p, p2);
		a = aux.a;
		b = aux.b;
		c = aux.c;
	}
};

bool areParallel(line l1, line l2) {
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool intersect(line l1, line l2, point &intersect) {
	if (areParallel(l1, l2)) return false;
	intersect.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
	if (fabs(l1.b) > EPS) intersect.y = -(l1.a*intersect.x + l1.c);
	else				  intersect.y = -(l2.a*intersect.x + l2.c);
	return true;
}

double length(double l1, double l2) {
	return sqrt(l1*l1 + l2*l2);
}

point midPoint(point p1, point p2) {
	return point(0.5*(p2.x + p1.x), 0.5*(p2.y + p1.y));
}

//Center is the same as circumcenter from triangle
point circle(point &p1, point &p2, point &p3) {
	vec v1(p2.x-p1.x, p2.y-p1.y),
		v2(p3.x-p1.x, p3.y-p1.y),
		v3(p3.x-p2.x, p3.y-p2.y);

	//THIS REMOVES A LOT OF PRECISION
	v1.rotate90DegCC();
	v2.rotate90DegCC();
	v3.rotate90DegCC();
	line l1(midPoint(p1,p2), v1), 
		 l2(midPoint(p1,p3), v2),
		 l3(midPoint(p2,p3), v3);

	point center;

	if (!intersect(l1, l2, center)) {
		if (!intersect(l1, l3,center)) {
			intersect(l2, l3, center);
		}
	}
	return center;
}

bool solve(int &j) {
	int n;
	cin >> n;
	if (n==0) return false;
	point p1, p2, p3;
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	point center = circle(p1,p2,p3);

	double rot = (2 * PI) / (double)n;
	double minX, maxX, minY, maxY;
	minX = maxX = p1.x;
	minY = maxY = p1.y;
	//Create vector that goes from center to p1
	vec dir(p1.x-center.x, p1.y-center.y);

	for (int i = 1; i < n; ++i) {
		//Rotate vector by rot
		vec aux = dir;
		dir.rotateCC(i*rot);
		
		double x = center.x + dir.x;
		double y = center.y + dir.y;
		minX = min(x, minX);
		maxX = max(x, maxX);
		minY = min(y, minY);
		maxY = max(y, maxY);
		dir = aux;
		//cout << "POINT " + i << ": " << x << ", " << y;
	}

	cout << "Polygon " << j << ": " << setprecision(3) << fixed << (maxX - minX)*(maxY - minY) << '\n';
	j++;
	return true;
}

int main() {
	int n = 1;
	while (solve(n));
}