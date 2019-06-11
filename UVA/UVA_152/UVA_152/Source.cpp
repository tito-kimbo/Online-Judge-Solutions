#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

const double INF = 1000000000000000;

struct point {
	int x, y, z;
	point() { x = y = z = 0; }
	point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

double distance(point &a, point &b) {
	int x, y, z;
	x = b.x - a.x;
	y = b.y - a.y;
	z = b.z - a.z;
	return sqrt(x*x+y*y+z*z);
}

bool operator == (point &a, point &b) {
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

bool operator != (point &a, point &b) {
	return !(a == b);
}

istream & operator >> (istream & in, point &p) {
	in >> p.x >> p.y >> p.z;
	return in;
}

void solve() {
	vector<int> hist(10,0);
	vector<point> trees;
	point aux;
	point zero;

	cin >> aux;
	while (aux != zero) {
		trees.push_back(aux);
		cin >> aux;
	}

	for (int i = 0; i < trees.size(); ++i) {
		double minDist = INF;
		int hValue;
		for (int j = 0; j < trees.size(); ++j) {
			if (j != i) {
				minDist = min(minDist, distance(trees[i],trees[j]));
			}
		}
		hValue = (int)minDist;
		if (0 <= hValue && hValue <= 9) hist[hValue]++;
	}

	for (int i = 0; i < 9; ++i) {
		cout << setw(4) << hist[i];
	}
	cout << setw(4) << hist[9];
	cout << '\n';
}

int main() {
	solve();
	//system("pause");
}