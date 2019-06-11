#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
	int aux;
	vector<int> v;
	
	for (int i = 0; i < 3; ++i) {
		cin >> aux;
		v.push_back(aux);
	}
	sort(v.begin(), v.end());
	return v[1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << "Case " << i+1 << ": " << solve() << '\n';
	}
}
