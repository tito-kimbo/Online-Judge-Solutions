#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;

const double EPS = 0.000000001;
const double INF = INT_MAX;

struct point_i {
	int x, y;
	point_i() {}
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

double distance(point_i &p1, point_i &p2) {
	return hypot(p2.x-p1.x, p2.y-p1.y);
}

bool operator==(point_i const& p1, point_i const& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

struct vec_i {
	int x, y;
	vec_i(point_i &p1, point_i &p2) {
		x = p2.x - p1.x;
		y = p2.y - p1.y;
	}
};

double cross(vec_i a, vec_i b) {
	return a.x*b.y - a.y*b.x;
}

struct point {
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
	point(point_i p) {
		x = p.x;
		y = p.y;
	}
};

double distance(point &p1, point &p2) {
	return hypot(p2.x-p1.x, p2.y-p1.y);
}

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
	vec(point p1, point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}
};


double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }
double norm_sq(vec v) { return (v.x*v.x + v.y*v.y); }
vec scale(vec v, double s) { return vec(v.x*s, v.y*s); }
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }

//Point to line 
double distance(point p, point a, point b) {
	vec ap(a, p), ab(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	point c = translate(a, scale(ab,u));
	return distance(p, c);
}

point_i pivot = point_i();
bool collinear(point_i &p1, point_i &p2, point_i &p3) {
	return fabs(cross(vec_i(p1,p2), vec_i(p1,p3)))<EPS;
}

int ccw(point_i &p1, point_i &p2, point_i &p3) {
	double d = cross(vec_i(p1, p2), vec_i(p1, p3));
	if(d > EPS) return 2;
	else if(fabs(d) < EPS) return 1;
	else return 0;
}

bool angleCmp(point_i &p1, point_i &p2) {
	if (collinear(pivot, p1, p2)) {
		return distance(pivot, p1) < distance(pivot, p2);
	}
	double d1x = p1.x - pivot.x, d1y = p1.y - pivot.y;
	double d2x = p2.x - pivot.x, d2y = p2.y - pivot.y;
	return (atan2(d1y,d1x)-atan2(d2y,d2x)) < 0;
}

vector<point_i> chGrahamScan(vector<point_i> & p) {
	pivot = p[0];
	int n = (int)p.size();
	if (n <= 3) {
		if (!(p[0] == p[n - 1])) p.push_back(p[0]);
		return p;
	}

	int pIndex = 0;
	for (int i = 1; i < n; ++i) {
		if (p[i].y < p[pIndex].y || (p[i].y == p[pIndex].y && p[i].x > p[pIndex].y)) pIndex = i;
	}

	point_i temp = p[0];
	p[0] = p[pIndex]; //Put pivot in first place
	p[pIndex] = temp;

	//Now sort points by angle with respect to pivot
	pivot = p[0];
	sort(++p.begin(), p.end(), angleCmp);

	vector<point_i> s;
	int indicator;
	s.push_back(p[n - 1]); 
	s.push_back(p[0]); 
	s.push_back(p[1]);
	int i = 2, j;
	while (i < n) {
		j = (int)s.size()-1;
		//cout << "Index i: " << i << " - Index j: " << j << '\n';
		indicator = ccw(s[j - 1], s[j], p[i]);
		if (indicator == 2) s.push_back(p[i++]);
		else if(indicator == 0) s.pop_back();	
		else {
			//The point is collinear
			j--;
			s.pop_back();
			while (j > 0 && ccw(s[j - 1], s[j], p[i]) == 1) {
				s.pop_back();
				j--;
			}
			s.push_back(p[i]);
			i++;
		}
	}
	return s;
}

bool solve(int &c) {
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<point_i> v(n);

	int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		v[i] = point_i(x,y);
	}

	vector<point_i> convexHull = chGrahamScan(v);
	double minDistance = INF;

	int s = convexHull.size();
	for (int i = 0; i < s-1; ++i) {
		int i2 = (i + 1) % s;
		double maxHeight = 0.0;
		for (int k = 0; k < s-1; ++k) {
			maxHeight = max(maxHeight, distance(point(convexHull[k]), point(convexHull[i]), point(convexHull[i2])));
		}
		minDistance = min(minDistance, maxHeight);
	}

	cout << setprecision(2) << fixed << "Case " << c << ": " << minDistance << '\n';
	c++;
	return true;
}

int main() {

	//ofstream out("out.txt");
	//streambuf *coutbuf = cout.rdbuf();
	//cout.rdbuf(out.rdbuf());

	int c = 1;
	while (solve(c));

	//cout.rdbuf(coutbuf);
}