#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

const double EPS = 0.000000001;
const double PI = 2 * acos(0.0);

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

bool operator==(point a, point b) {
	return fabs(b.x - a.x) < EPS && fabs(b.y - a.y) < EPS;
}

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { return vec(b.x-a.x, b.y-a.y); }
vec scale(vec v, double a) { return vec(v.x*a, v.y*a); }
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }
double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }
double norm_sq(vec a) { return a.x*a.x + a.y*a.y; }
double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }
//ccw rotation with angle in radians
vec rotate(vec v, double a) { return vec(v.x*cos(a) - v.y*sin(a), v.x*sin(a) + v.y*cos(a)); }

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < 0;
}

double dist(point p1, point p2) {
	return hypot(p2.x-p1.x, p2.y-p1.y);
}

struct square {
	double width, height;
	double angle;
	point p;
	square(double x, double y, double w, double h, double a) : p(x,y), width(w), height(h), angle(a) {}
};

int area(square &sq) {
	return sq.width*sq.height;
}

double area(vector<point> const &v) {
	//Area of (convex) polygon
	double result = 0.0;
	for (int i = 0; i < (int)v.size() - 1; ++i) {
		result += (v[i].x*v[i+1].y-v[i+1].x*v[i].y);
	}
	return fabs(result)/2.0;
}

double toRad(double a) {
	return PI*a / 180.0;
}

void addPoints(vector<point> &v, square const &s) {
	//Calculate the four points and add them to v
	vec horiz = scale(rotate(vec(0,1), -1*toRad(s.angle) - 0.5*PI), 0.5*s.width);
	vec vert = scale(rotate(vec(0,1), -1*toRad(s.angle)), 0.5*s.height);

	v.push_back(translate(translate(s.p, vert), horiz));
	v.push_back(translate(translate(s.p, vert), scale(horiz,-1)));
	v.push_back(translate(translate(s.p, scale(vert,-1)), horiz));
	v.push_back(translate(translate(s.p, scale(vert,-1)), scale(horiz,-1)));
}

point pivot;
bool angleCmp(point a, point b) {
	if (collinear(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> convexHull(vector<point> p) {
	//Return convex hull of p
	int i, j, n = p.size();
	if (n <= 3) {
		if (!(p[0] == p[n - 1])) p.push_back(p[0]);
		return p;
	}

	int P0 = 0;
	for (i = 1; i < n; i++) {
		if (p[i].y < p[P0].y || (p[i].y == p[P0].y && p[i].x > p[P0].x))
			P0 = i;
	}
	point temp = p[0]; p[0] = p[P0]; p[P0] = temp;
	pivot = p[0];
	sort(++p.begin(), p.end(), angleCmp);
	vector<point> S;
	S.push_back(p[n - 1]);
	S.push_back(p[0]);
	S.push_back(p[1]);
	i = 2;
	while (i < n) {
		j = (int)S.size() - 1;
		if (ccw(S[j - 1], S[j], p[i])) S.push_back(p[i++]);
		else S.pop_back();
	}
	return S;
}

void solve() {
	int n;
	double portion, boxArea;
	vector<square> boxes;
	vector<point> poly;

	double x, y, width, height, angle;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> width >> height >> angle;
		boxes.push_back(square(x, y, width, height, angle));
		addPoints(poly, boxes[i]);
	}

	boxArea = 0;
	for (square s : boxes) boxArea += area(s);
	poly = convexHull(poly);

	cout << setprecision(1) << fixed << 100*boxArea/area(poly) << " %\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}
