#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct point_i {
	int x, y, z;
	point_i(){}
	point_i(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

struct quadrilateral {
	point_i p;
	int OX, OY, OZ; //Extension towards each axis in units

	quadrilateral() {}
	quadrilateral(point_i _p, int _OX, int _OY, int _OZ) : p(_p), OX(_OX), OY(_OY), OZ(_OZ) {}
	quadrilateral(point_i low, point_i high) : p(low), OX(high.x-low.x), OY(high.y-low.y), OZ(high.z-low.z) {}
};

bool inside(point_i p, quadrilateral &q) {
	return abs(p.x - q.p.x) <= q.OX && abs(p.y - q.p.y) <= q.OY && abs(p.z - q.p.z) <= q.OZ;
}

quadrilateral intersect(quadrilateral &q1, quadrilateral &q2) {
	//Now intersect the two quadrilaterals
	point_i upper = point_i(q2.p.x+q2.OX, q2.p.y+q2.OY, q2.p.z+q2.OZ);
	if (q2.p.x-q1.p.x >= q1.OX || q2.p.y-q1.p.y >= q1.OY || q2.p.z-q1.p.z >= q1.OZ ||
		upper.x-q1.p.x <= 0 || upper.y-q1.p.y <= 0 || upper.z-q1.p.z <= 0)
			return quadrilateral(point_i(0, 0, 0), 0, 0, 0);

	point_i newLower(0,0,0), newUpper(0,0,0);
	//Find the new lower point
	//They indicate whether to keep x,y,z coordinates of q1.p
	bool keepX, keepY, keepZ;
	keepX = q2.p.x <= q1.p.x;
	keepY = q2.p.y <= q1.p.y;
	keepZ = q2.p.z <= q1.p.z;

	newLower.x = (keepX) ? q1.p.x : q2.p.x;
	newLower.y = (keepY) ? q1.p.y : q2.p.y;
	newLower.z = (keepZ) ? q1.p.z : q2.p.z;

	//Find the new upper point
	//They indicate whether to keep x,y,z coordinates of p1.p + (p1.OX, p1.OY, p1.OZ)
	keepX = upper.x >= q1.p.x+q1.OX;
	keepY = upper.y >= q1.p.y+q1.OY;
	keepZ = upper.z >= q1.p.z+q1.OZ;

	newUpper.x = (keepX) ? q1.p.x + q1.OX : upper.x;
	newUpper.y = (keepY) ? q1.p.y + q1.OY : upper.y;
	newUpper.z = (keepZ) ? q1.p.z + q1.OZ : upper.z;

	return quadrilateral(newLower, newUpper.x-newLower.x, newUpper.y-newLower.y, newUpper.z-newLower.z);
}

long long int area(quadrilateral &q) {
	return q.OX*q.OY*q.OZ;
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;
	int x, y, z, l;

	vector<quadrilateral> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z >> l;
		v[i] = quadrilateral(point_i(x,y,z), l, l, l);
	}

	quadrilateral intersection = v[0];

	for (int i = 1; i < n; ++i) {
		intersection = intersect(intersection, v[i]);
	}
	cout << area(intersection) << '\n';

	return true;
}

int main() {
	while (solve());
}