#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

const double EPS = 0.00000001;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

bool operator==(point &p1, point &p2) {
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

istream & operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

bool solve() {
	point p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	if (!cin) return false;

	point aux;
	if (p1 == p3) {
		aux = p2;
		p2 = p3;
		p3 = aux;
	}
	else if (p2 == p4) {
		aux = p3;
		p3 = p4;
		p4 = aux;
	}

	int side;
	double newX, newY;
	if (p1 == p2) {
		side = 1;
		//Parallel side is side 3
		newX = p4.x + (p3.x - p2.x);
		newY = p4.y + (p3.y - p2.y);
	}
	else if (p2 == p3) {
		side = 2;
		//Parallel side is side 4
		newX = p1.x + (p4.x - p3.x);
		newY = p1.y + (p4.y - p3.y);
	}
	else if (p3 == p4) {
		side = 3;
		//Parallel side is side 1
		newX = p2.x + (p1.x - p4.x);
		newY = p2.y + (p1.y - p4.y);
	}
	else { //p4 == p1
		side = 4;
		//Parallel side is side 2
		newX = p3.x + (p2.x - p1.x);
		newY = p3.y + (p2.y - p1.y);
	}

	cout << setprecision(3) << fixed << newX << ' ' << newY << '\n';
	return true;
}

int main() {
	while (solve());
}