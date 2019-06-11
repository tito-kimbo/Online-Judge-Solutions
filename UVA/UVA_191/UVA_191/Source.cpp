#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct point {
	int x, y;
	point() {}
	point(int _x, int _y) : x(_x), y(_y) {}
};

bool operator== (point a, point b) {
	return a.x == b.x && a.y == b.y;
}

istream &operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

struct vec {
	int x, y;
	vec(int _x, int _y) : x(_x), y(_y) {}
	vec(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};

int cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

int assignValue(point p, point a, point b) {
	vec ab(a, b);
	vec ap(a, p);
	int val = cross(ab, ap);
	if (val > 0) {
		//Point is LEFT of the line ab
		return 1;
	}
	else if (val < 0) {
		//Point is RIGHT of the line ab
		return -1;
	}
	else {
		return 0; //Point in the line ab
	}
}

void solve() {
	point a, b, aux1,aux2,topL, botR;
	cin >> a >> b >> aux1 >> aux2;
	topL = point(min(aux1.x,aux2.x), max(aux1.y,aux2.y));
	botR = point(max(aux1.x,aux2.x), min(aux1.y,aux2.y));
	//FIND REAL TOP LEFT AND BOTTOM RIGHT
	int v1 = assignValue(topL, a, b), v2 = assignValue(botR,a,b);
	int v3 = assignValue(point(topL.x, botR.y), a,b), v4 = assignValue(point(botR.x, topL.y), a,b);

	bool cantIntersect = (topL.x > max(a.x,b.x) || topL.y < min(a.y,b.y)) || (botR.x < min(a.x,b.x) || botR.y > max(a.y,b.y));

	if (!cantIntersect & (v1 == 0 || v2 == 0 || v3 == 0 || v4 == 0 || abs(v1+v2+v3+v4)<4)) {
		cout << "T\n";
	}
	else {
		cout << "F\n";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}