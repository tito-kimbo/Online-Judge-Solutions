#include <iostream>
using namespace std;

void solve(int n) {
	int a, b;
	cin >> a >> b;
	long long int sum = 0;
	for (int i = (a%2 == 1) ? a : a+1; i <= b; i+=2) {
		sum += i;

	}
	cout << "Case " << n << ": ";
	cout << sum << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve(i+1);
	}
}