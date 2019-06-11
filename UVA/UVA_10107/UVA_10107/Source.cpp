#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lli;

bool solve(vector<lli> &v) {
	lli aux;

	cin >> aux;
	if (!cin) return false;
	v.push_back(aux);
	sort(v.begin(), v.end());
	aux = (v.size() - 1) / 2;

	if (v.size()%2 == 0) {
		cout << (v[aux] + v[aux + 1]) / 2 << '\n';
	}else {
		cout << v[aux] << '\n';
	}

	return true;
}

int main() {
	vector<lli> v;
	while (solve(v));
}