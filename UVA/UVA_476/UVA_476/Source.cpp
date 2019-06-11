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

istream & operator >> (istream &in, point &p) {
	in >> p.x >> p.y;
	return in;
}

struct quad {
	point lower, upper;
	quad() {}
	quad(point low, point up) : lower(low), upper(up) {}
};

bool inQuad(point p, quad q){
	return p.x > q.lower.x && p.x < q.upper.x &&
		p.y > q.lower.y && p.y < q.upper.y; 
}

int main() {
	string s = "", aux;
	quad q;
	point p1, p2;
	vector<quad> v;

	getline(cin, s);
	while (s != "*") {
		//READ
		istringstream myStream(s);
		myStream >> aux;
		myStream >> p1 >> p2;
		v.push_back(quad(point(min(p1.x,p2.x), min(p1.y,p2.y)), point(max(p1.x,p2.x), max(p1.y,p2.y))));
		getline(cin, s);
	}

	cin >> p1;
	int point = 1;
	while (p1.x != 9999.9 || p1.y != 9999.9) {
		int count = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (inQuad(p1, v[i])) {
				cout << "Point " << point << " is contained in figure " << i + 1 << '\n';
				count++;
			}
		}
		
		if (count == 0) cout << "Point " << point << " is not contained in any figure\n";
		point++;
		cin >> p1;
	}
}