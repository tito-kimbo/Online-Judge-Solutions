#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <tuple>
#include <fstream>
#include <iomanip>
using namespace std;

const double EPS = 0.00000001;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

bool operator<(point a, point b) {
	return tie(a.x, a.y) < tie(b.x, b.y);
}

double distance(point p1, point p2) {
	return hypot(p2.x - p1.x, p2.y - p1.y);
}

struct vec {
	double x, y;
	vec() {}
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point p, point q) {
	return vec(q.x-p.x,q.y-p.y);
}

double dot(vec a, vec b) {
	return a.x*b.x + a.y*b.y;
}

double cross(vec a, vec b) {
	return a.x*b.y - a.y*b.x;
}

double norm_sq(vec a) {
	return a.x*a.x + a.y*a.y;
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

vec scale(vec v, double u) {
	return vec(v.x*u, v.y*u);
}

double distToLine(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return distance(p, c);
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > EPS;
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

vector<point> andrew(vector<point> &P) {
	int n = P.size(), k = 0;
	vector<point> H(2 * n);

	if (n <= 2) {
		for (int i = 0; i < n; ++i) {
			H[i] = P[i];
		}
		H[n] = P[0];
		H.resize(n+1);
		return H;
	}

	sort(P.begin(), P.end());
	//Lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k-2],H[k-1], P[i])) k--;
		H[k++] = P[i];
	}
	//Upper hull
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && !ccw(H[k - 2], H[k - 1], P[i])) k--;
		H[k++] = P[i];
	}
	H.resize(k);

	return H;
}

double cross(point o, point a, point b) {
	vec oa = toVec(o,a), ob = toVec(o,b);
	return cross(oa, ob);
}

//Applying rotating caliper algorithm
double width(vector<point> &P) {
	if (P.size() <= 3) {
		return 0;
	}
	point aux;
	double val = 1e+60;
	for (int i = 0, j = 0; i < P.size()-1; ++i) {
		while (cross(P[i], P[i + 1], P[j + 1]) >= cross(P[i], P[i + 1], P[j])) j = (j + 1) % (P.size()-1);
		double dist = distToLine(P[j],P[i],P[i+1],aux);
		val = min(val, dist);
	}
	return val;
}

bool solve() {
	int N, R;
	cin >> N >> R;
	if (!cin) return false;
	vector<point> v;

	long long int x, y;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		//scanf("%d %d", &x, &y);
		v.emplace_back(point(x, y));
	}
	v = andrew(v);

	double minW = width(v);
	/* TLE
	double minW = 100000000000000000000.0, aux;
	point paux;
	for (int i = 0; i < v.size() - 1; ++i) {
		aux = -1;
		for (int j = 0; j < v.size() - 1; ++j) {
			if (aux > minW) break;
			if(i != j && i != j+1 && !(i==0 && j==v.size()-2)) aux = max(aux, distToLine(v[i],v[j],v[j+1], paux));
		}
		minW = min(minW, aux);
	}*/
	
	cout << fixed << setprecision(16) << minW << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	streambuf *cinbuf = cin.rdbuf();
	ifstream in("input.txt");
	//cin.rdbuf(in.rdbuf());
	while (solve());
	//cin.rdbuf(in.rdbuf());
}