#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;

const double EPS = 0.000000001;
const double PI = 2*acos(0.0);

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

double distance(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

istream & operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

class figure {
public:
	string type;
	figure() {}
	figure(string t) : type(t) {}
	virtual bool inFigure(point p) { return false; }
};
class quad : public figure {
public:
	point lower, upper;
	quad() {};
	quad(point low, point up) : figure("quad"), lower(low), upper(up) {}
	bool inFigure(point p) {
		return p.x > lower.x && p.x < upper.x &&
			p.y > lower.y && p.y < upper.y;
	}
};

class circle : public figure {
public:
	point center;
	double radius;
	circle() {}
	circle(point c, double r) : figure("circle"), center(c), radius(r) {}
	bool inFigure(point p) {
		return distance(p, center) < radius;
	}
};

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
	return vec(b.x-a.x, b.y-a.y);
}

double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }
double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }
double norm_sq(vec a) { return a.x*a.x + a.y*a.y; }
bool ccw(point p, point q, point r) {
	return cross(toVec(p,q), toVec(p,r)) > 0;
}

double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa)*norm_sq(ob)));
}


class triangle : public figure {
public:
	vector<point> points;
	triangle() {}
	triangle(point p1, point p2, point p3) : figure("triangle") {
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(p3);
		points.push_back(p1);
	}
	bool inFigure(point p) {
		double sum = 0.0;
		for (int i = 0; i < 3; ++i) {
			if (ccw(p, points[i], points[i + 1])) {
				sum += angle(points[i], p, points[i + 1]);
			}
			else {
				sum -= angle(points[i], p, points[i + 1]);
			}
		}

		return fabs(fabs(sum) - 2 * PI) < EPS;
	}
};

int main() {
	string s = "", aux;
	point p1, p2;
	int sizeQuad, sizeCircle, sizeTriangle;
	vector<quad> auxQuad(10);
	vector<circle> auxCircle(10);
	vector<triangle> auxTriangle(10);
	vector<figure*> v;

	sizeQuad = sizeCircle = sizeTriangle = 0;
	getline(cin, s);
	while (s != "*") {
		//READ
		istringstream myStream(s);
		myStream >> aux;
		if (aux == "r") {
			myStream >> p1 >> p2;
			auxQuad[sizeQuad] = quad(point(min(p1.x, p2.x), min(p1.y, p2.y)), point(max(p1.x, p2.x), max(p1.y, p2.y)));
			v.push_back(&auxQuad[sizeQuad]);
			sizeQuad++;
		}
		else if (aux == "c") {
			double rad;
			myStream >> p1 >> rad;
			auxCircle[sizeCircle] = circle(p1, rad);
			v.push_back(&auxCircle[sizeCircle]);
			sizeCircle++;
		}
		else if (aux == "t") {
			point p3;
			myStream >> p1 >> p2 >> p3;
			auxTriangle[sizeTriangle] = triangle(p1, p2, p3);
			v.push_back(&auxTriangle[sizeTriangle]);
			sizeTriangle++;
		}
		getline(cin, s);
	}

	cin >> p1;
	int point = 1;
	while (p1.x != 9999.9 || p1.y != 9999.9) {
		int count = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i]->inFigure(p1)) {
				cout << "Point " << point << " is contained in figure " << i + 1 << '\n';
				count++;
			}
		}

		if (count == 0) cout << "Point " << point << " is not contained in any figure\n";
		point++;
		cin >> p1;
	}
}