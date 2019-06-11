#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

double EPS = 0.000000001;

struct point_i {
	int x, y;
	point_i() {}
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

double distance(point_i p1, point_i p2) {
	return hypot(p2.x-p1.x, p2.y-p1.y);
}

//Returns whether the given point is in the rectangle of lower left corner (0,0) 
bool inRectangle(double length, double height, point_i p) {
	return p.x >= 0 && p.x <= length && p.y >= 0 && p.y <= height;
}

bool solve() {
	int X, Y, R1, R2;

	cin >> X >> Y >> R1 >> R2;
	if (X == 0 && Y == 0 && R1 == 0 && R2 == 0) return false;

	point_i c1, c2;

	c1 = point_i(R1, Y-R1);
	c2 = point_i(X - R2, R2);

	if (inRectangle(X, Y, c1) && inRectangle(X, Y, c2) &&
		inRectangle(X, Y, point_i(c1.x + R1, c1.y)) && inRectangle(X, Y, point_i(c1.x, c1.y - R1)) &&
		inRectangle(X, Y, point_i(c2.x - R2, c2.y)) && inRectangle(X, Y, point_i(c2.x, c2.y + R2)) &&
		distance(c1,c2)-(R1+R2) > -EPS) {
		cout << "S\n";
	}
	else {
		cout << "N\n";
	}

	return true;
}

int main() {
	while (solve());
}