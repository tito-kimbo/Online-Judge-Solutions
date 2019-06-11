#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <tuple>
#include <fstream>
using namespace std;

const double EPS = 0.00000001;
const double PI = 2 * acos(0.0);

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

istream &operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

struct vec {
	double x, y;
	vec() {}
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point &a, point &b) {
	return vec(b.x - a.x, b.y - a.y);
}

bool operator<(point &a, point &b) {
	if(fabs(a.x-b.x)<EPS) return a.y<b.y;
	return a.x < b.x;
	//return tie(a.x, a.y) < tie(b.x, b.y);
}

double cross(vec a, vec b) {
	return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p,q), toVec(p,r)) > EPS;
}

vector<point> andrew(vector<point> &P) {
	int n = P.size(), k=0;
	vector<point> H(2 * n);

	sort(P.begin(), P.end());
	for (int i = 0; i < n; ++i) {
		while (k>=2 && !ccw(H[k-2],H[k-1],P[i])) k--;
		H[k++] = P[i];
	}

	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k>=t && !ccw(H[k-2],H[k-1],P[i])) k--;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

double dot(vec &a, vec &b) { return a.x*b.x + a.y*b.y; }
double norm_sq(vec &a) { return a.x*a.x + a.y*a.y; }

double angle(point &a, point &o, point &b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

double distance(point &a, point &b) { return hypot(b.x-a.x,b.y-a.y); }
point translate(point &a, vec v) { return point(a.x + v.x, a.y + v.y); }
vec scale(vec v, double u) { return vec(v.x*u, v.y*u); }
double distToLine(point &p, point &a, point &b) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	point c;
	c = translate(a,scale(ab,u));
	return distance(p,c);
}


bool isInsidePolygon(point &pt, vector<point> &P, int lower, int upper) {
	//WITH BINARY SEARCH
	if (upper <= lower) return false;
	//base at 0 ->
	int mid = (lower + upper - 1) / 2;
	double threshold = max(distance(P[0],P[mid]),distance(P[0],P[mid+1]));
	if(!ccw(P[0], pt, P[mid]) && !ccw(P[0], P[mid + 1], pt) && !ccw(P[mid + 1], P[mid], pt)
	  && threshold-distance(P[mid],pt) > -EPS){
		return true;
	} else if (ccw(P[0], pt, P[mid])) {
		return isInsidePolygon(pt, P, lower, mid);
	} else {
		return isInsidePolygon(pt, P, mid+1, upper);
	}
}

bool solve() {
	int L, S;
	cin >> L;
	if (!cin) return false;
	//Read large
	vector<point> large(L);
	for (int i = 0; i < L; ++i) cin >> large[i];
	//Read small
	cin >> S;
	vector<point> small(S);
	for (int i = 0; i < S; ++i) cin >> small[i];
	//CH and count
	int count = 0;
	large = andrew(large);
	double minX = 1e+60, maxX=-1, minY=1e+60, maxY=-1;
	for (int i = 0; i < large.size(); ++i) {
		minX = min(minX, large[i].x);
		maxX = max(maxX, large[i].x);
		minY = min(minY, large[i].y);
		maxY = max(maxY, large[i].y);
	}

	for (int i = 0; i < S; ++i) {
		if (small[i].x-minX>-EPS && maxX-small[i].x>-EPS &&
			small[i].y-minY>-EPS && maxY-small[i].y>-EPS &&
			isInsidePolygon(small[i], large, 1, large.size()-2)) 
				count++;
	}
	cout << count << '\n';
	return true;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	streambuf* coutbuf = cout.rdbuf();
	streambuf* cinbuf = cin.rdbuf();
	cout.rdbuf(out.rdbuf());
	cin.rdbuf(in.rdbuf());

	ios_base::sync_with_stdio(false);
	while (solve());
	cout.rdbuf(coutbuf);
	cin.rdbuf(cinbuf);
}