#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

const double EPS = 0.000000001;
const double PI = 2 * acos(0.0);

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

bool operator==(point p1, point p2) {
	return (fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS);
}

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
	return vec(b.x-a.x, b.y-a.y);
}

double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }
double norm_sq(vec a) { return a.x*a.x + a.y*a.y; }
double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o,b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

bool ccw(point p1, point p2, point p3) {
	return cross(toVec(p1, p2), toVec(p1, p3)) < EPS;
}

bool insidePoly(point p, vector<point> const& poly) {
	if ((int)poly.size() == 0) return false;
	double sum = 0;
	for (int i = 0; i < (int)poly.size() - 1; ++i) {
		if (ccw(p, poly[i], poly[i + 1])) sum += angle(poly[i], p, poly[i+1]);
		else sum -= angle(poly[i], p, poly[i + 1]);
	}
	return fabs(fabs(sum) - 2 * PI) < EPS;
}

double area(vector<point> &p) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)p.size()-1; ++i) {
		x1 = p[i].x, x2 = p[i+1].x;
		y1 = p[i].y, y2 = p[i + 1].y;
		result += (x1*y2-x2*y1);
	}
	return fabs(result)/2.0;
}

point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x*A.y - A.x*B.y;
	double u = fabs(a*p.x + b*p.y + c);
	double v = fabs(a*q.x + b*q.y + c);
	return point((p.x*v+q.x*u) / (u+v), (p.y*v+q.y*u)/(u+v));
}

vector<point> cutPolygon(point &a, point &b, vector<point> const& Q, point const& fountain) {
	vector<point> P;
	//WE MUST DECIDE WHETHER TO TAKE LEFT OR RIGHT POLYGON
	bool left = cross(toVec(a, b), toVec(a, fountain)) > -EPS;
	if (left) {
		//WE TAKE LEFT CUT
		for (int i = 0; i < (int)Q.size(); ++i) {
			double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
			if (i != Q.size() - 1) left2 = cross(toVec(a, b), toVec(a, Q[i + 1]));
			if (left1 > -EPS) P.push_back(Q[i]);
			if (left1 * left2 < -EPS) {
				P.push_back(lineIntersectSeg(Q[i],Q[i+1],a,b));
			}
		}
		if (!(P[0] == P[P.size() - 1])) P.push_back(P[0]);
		return P;
	}
	else {
		//WE TAKE RIGHT CUT
		/*for (int i = 0; i < (int)Q.size(); ++i) {
			double right1 = cross(toVec(Q[i],b), toVec(a,b)), right2 = 0;
			if (i != Q.size() - 1) right2 = cross(toVec(Q[i+1],b), toVec(a,b));
			if (right1 < EPS) P.push_back(Q[i]);
			if (right1 * right2 < -EPS) {
				P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
			}
		}*/
		return cutPolygon(b, a, Q, fountain);
	}
}

void solve(int &c) {
	int N, W, H, x, y;
	vector<point> p, nextPoly;

	cin >> N >> W >> H >> x >> y;
	point fountain(x, y);
	//Initialize poly
	p.emplace_back(point(0, 0));
	p.emplace_back(point(W,0));
	p.emplace_back(point(W, H));
	p.emplace_back(point(0, H));
	p.emplace_back(point(0, 0));

	point p1, p2;
	for (int i = 0; i < N; ++i) {
		//Cut polygon, find piece containing fountain and repeat
		cin >> x >> y;
		p1 = point(x, y);
		cin >> x >> y;
		p2 = point(x, y);
		//Find polygon with fountain
		p = cutPolygon(p1, p2, p, fountain);
	}

	cout << fixed << setprecision(3) << "Case #" << c << ": " << area(p) << '\n';
	c++;
}

int main() {
	int n = 1;
	
	/*
	ofstream redirect_file("output.txt");

	// save output buffer of cout
	streambuf * strm_buffer = cout.rdbuf();

	// redirect output into file
	cout.rdbuf(redirect_file.rdbuf());
	*/
	for (int i = 0; i < 500; ++i) {
		solve(n);
	}
	/*
	// restore old buffer
	cout.rdbuf(strm_buffer);
	*/
}