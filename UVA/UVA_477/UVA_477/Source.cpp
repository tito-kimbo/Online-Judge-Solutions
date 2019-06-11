#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

double distance(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

istream & operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

class figure {
public:
	string type;
	figure() {}
	figure(string t) : type(t) {}
	virtual bool inFigure(point p) { return false; }
};
class quad : public figure {
public:
	point lower, upper;
	quad() {};
	quad(point low, point up) : figure("quad"), lower(low), upper(up) {}
	bool inFigure(point p) {
		return p.x > lower.x && p.x < upper.x &&
			p.y > lower.y && p.y < upper.y;
	}
};

class circle : public figure {
public:
	point center;
	double radius;
	circle() {}
	circle(point c, double r) :  figure("circle"), center(c), radius(r) {}
	bool inFigure(point p) {
		return distance(p, center) < radius;
	}
};


int main() {
	string s = "", aux;
	point p1, p2;
	int sizeQuad, sizeCircle;
	vector<quad> auxQuad(10);
	vector<circle> auxCircle(10);

	vector<figure*> v;

	sizeQuad = sizeCircle = 0;
	getline(cin, s);
	while (s != "*") {
		//READ
		istringstream myStream(s);
		myStream >> aux;
		if (aux == "r") {
			myStream >> p1 >> p2;
			auxQuad[sizeQuad] = quad(point(min(p1.x, p2.x), min(p1.y, p2.y)), point(max(p1.x, p2.x), max(p1.y, p2.y)));
			v.push_back(&auxQuad[sizeQuad]);
			sizeQuad++;
		}else if (aux == "c") {
			double rad;
			myStream >> p1 >> rad;
			auxCircle[sizeCircle] = circle(p1, rad);
			v.push_back(&auxCircle[sizeCircle]);
			sizeCircle++;
		}
		getline(cin, s);
	}

	cin >> p1;
	int point = 1;
	while (p1.x != 9999.9 || p1.y != 9999.9) {
		int count = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i]->inFigure(p1)) {
				cout << "Point " << point << " is contained in figure " << i + 1 << '\n';
				count++;
			}
		}

		if (count == 0) cout << "Point " << point << " is not contained in any figure\n";
		point++;
		cin >> p1;
	}
}