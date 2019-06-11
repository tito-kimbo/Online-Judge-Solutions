#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == b && a == c && a == d) {
		cout << "square\n";
	}
	else {
		vector<int> v = { a,b,c,d };
		sort(v.begin(), v.end());

		if (v[0] == v[1] && v[2] == v[3]) {
			cout << "rectangle\n";
		}
		else if (v[0]+v[1]+v[2] > v[3]) {
			cout << "quadrangle\n";
		}
		else {
			cout << "banana\n";
		}

	}
}

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		solve();
	}
}