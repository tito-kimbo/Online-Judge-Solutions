#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 0 && b == 0 & c == 0) return false;

	vector<int> v = {a,b,c};
	sort(v.begin(), v.end());
	if (v[0]*v[0]+v[1]*v[1] == v[2]*v[2]) {
		cout << "right\n";
	}
	else {
		cout << "wrong\n";
	}

	return true;
}

int main() {
	while (solve());
}