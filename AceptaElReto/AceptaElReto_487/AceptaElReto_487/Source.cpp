#include <iostream>
#include <vector>
using namespace std;

long long int extra(long long int n, long long int mod) {
	if (n < 3600) return 0;
	return n / 3600 + extra((mod + n / 3600), (mod + n / 3600) % 3600);
}

void solve() {
	long long int n, vueltas = 0;
	
	cin >> n;
	cout << n+extra(n,n%3600) << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)solve();
}