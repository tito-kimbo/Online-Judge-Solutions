#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n) {
	long long int a, b, c;

	cin >> a >> b >> c;
	cout << "Case " << n << ": ";
	vector<long long int> v = { a,b,c };
	sort(v.begin(), v.end());
	if (v[0] + v[1] <= v[2]) {
		cout << "Invalid\n";
	}
	else {
		if (v[0] == v[1] && v[0] == v[2]) {
			cout << "Equilateral\n";
		}
		else if (v[0] == v[1] || v[0] == v[2] || v[1] == v[2]) {
			cout << "Isosceles\n";
		}else{
			cout << "Scalene\n";
		}
	}

}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; ++i) {
		solve(i);
	}
}