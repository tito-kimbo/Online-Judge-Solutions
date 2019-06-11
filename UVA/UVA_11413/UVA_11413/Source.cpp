//UVA 11413
#include <iostream>
#include <vector>
using namespace std;

const long long int UPPER_LIMIT = 1000000000; //vessels*max_capacity

//Is the current cap feasible?
bool feasibleCap(long long int cap, const int &n, const int &m, 
	vector<int> &v) {
	int current=0, i=0, currentVal= 0;
	while( i < n && current < m) {
		if (currentVal + v[i] <= cap) {
			currentVal += v[i];
			++i;
		} else {
			currentVal = 0;
			++current;
		}
	}
	return i == n;
}

bool solve() {
	int n, m;

	cin >> n >> m;
	if (!cin) return false;
	vector<int> vessels(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> vessels[i];
	}

	//Binary search for the minimum cap
	long long int low, high;
	low = 0;
	high = UPPER_LIMIT;
	while (low < high) {
		if (feasibleCap((low + high) / 2, n, m, vessels)) {
			high = (low + high) / 2;
		}
		else {
			low = (low + high + 1) / 2;
		}
	}
	cout << low << '\n';
	return true;
}

int main() {
	while (solve());
}