#include <deque>
#include <iostream>
using namespace std;

bool solve() {
	long long int n;
	
	cin >> n;
	if (n == 0)return false;

	deque<int> dq;
	int sum = 0;
	long long int factor=1;
	
	cout << "The parity of ";
	//1,2,4,8,16,32...
	//Binary factorization
	while (2*factor <= n) {
		factor *= 2;
	}

	while (factor > 0){
		if (factor <= n) {
			n -= factor;
			cout << '1';
			sum++;
		}
		else {
			cout << '0';
		}

		factor /= 2;
	}

	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}
	cout << " is " << sum << " (mod 2).\n";

	return true;
}

int main() {
	while (solve());
}