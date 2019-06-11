#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 0.000000001;

struct point {
	double x, y;
	point() { x = y = 0; }
	point(double _x, double _y) : x(_x), y(_y) {};
	
	double distance(point p) {
		return hypot(x-p.x, y-p.y);
	}

	bool operator<(const point & p) {
		if (fabs(p.x - x) > EPS) {
			return x < p.x;
		};
		return y < p.y;
	}
};

struct line {
	double a, b, c;
	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};
	line(point p1, point p2) { //Lines guaranteed not to be 
		a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		b = 1.0;
		c = -(double)(a*p1.x) - p1.y;
	}

	bool areParallel(line l) {
		return (fabs(a - l.a) < EPS) && (fabs(b - l.b) < EPS);
	}

	bool intersect(line l, point &p) {
		if (areParallel(l)) return false;
		//OBS: NO VERTICAL LINES ALLOWED
		p.x = (l.b*c-b*l.c) / (l.a*b - a*l.b);
		p.y = -(a*p.x+c);
		return true;
	}
};

int maxHeightIndex(vector<point> &v, int init=0) {
	double max = -1.0;
	int ind = init;
	for (int i = init; i < v.size(); ++i) {
		if (fabs(v[i].y-max) > EPS && v[i].y > max) {
			max = v[i].y;
			ind = i;
		}
	}
	return ind;
}

void solve() {
	double x, y, sum;
	int n, maxIndex;
	cin >> n;
	vector<point> v(n);

	sum = 0.0;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		v[i] = point(x, y);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n-1; ++i) {
		maxIndex = maxHeightIndex(v, i + 1);
		y = v[maxIndex].y;
		//cout << "Current " << v[i].y << " - Max afterwards " << y << '\n';
		if (fabs(v[i].y-y) > EPS && v[i].y > y) { 
			//cout << "Line from points " << v[i].x << ' ' << v[i].y;
			//cout << " and " << v[i + 1].x << ' ' << v[i + 1].y << '\n';
			//system("pause");
			point aux;
			line(v[i], v[i + 1]).intersect(line(0, 1, -v[maxIndex].y), aux);

			sum += v[i].distance(aux);
		}
	}

	cout << setprecision(2) << fixed << sum << '\n';
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; ++i) {
		solve();
	}
}