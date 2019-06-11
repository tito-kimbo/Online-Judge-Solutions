#include <iostream>
#include <algorithm>
using namespace std;

//Linear solution O(n)
bool solve() {
	int n;
	
	cin >> n;
	if (n == 0) return false;
	long long int sum, next, maximum;

	sum = maximum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> next;
		sum += next;
		maximum = max(maximum, sum);
	}


	cout << sum << ' ' << maximum << '\n';

	return true;
}

int main() {
	while (solve());
}