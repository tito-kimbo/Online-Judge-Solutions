#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct fract {
	long long int a, b;
};

istream & operator >> (istream &in, fract &f) {
	in >> f.a;
	in.get();
	in >> f.b;
	return in;
}

bool operator<(fract f1, fract f2) {
	return f1.b < f2.b;
}

long long int mcd(long long int a, long long int b) {
	if (b == 0) return a;
	else return mcd(b, a%b);
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;
	
	vector<fract> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	long long int mult = v[0].b;
	for (int i = 0; i < n; ++i) {
		if (mult%v[i].b != 0) mult *= (v[i].b/mcd(mult, v[i].b));
	}

	long long int tot = mult;
	for (int i = 0; i < n; ++i) {
		tot -= (mult/v[i].b)*v[i].a;
	}

	cout << tot << '\n';
	return true;
}

int main(){
	while (solve());
}