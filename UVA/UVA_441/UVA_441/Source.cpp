#include <iostream>
#include <vector>
using namespace std;

/*
void loop(int times, const int &n, const vector<int> &v, vector<bool> &bitmask, vector<int> &sol) {
	vector<int> changed;
	for (int i = 0; i < n; ++i) {
		if (!bitmask[i]) {
			bitmask[i] = true;
			sol[6 - times] = v[i];
			if (times > 1) {
				loop(times - 1, n, v, bitmask, sol);
			} else { //Show solution
				for (int i = 0; i < 6; ++i){
					cout << sol[i];
					if (i != 5) cout << ' ';
				}
				cout << '\n';
			}
			bitmask[i] = false;
		} 
	}
} 
This code does give all possible permumations but does not solve problem
*/

bool solve(bool &first) {
	int n;
	
	cin >> n;
	if (n == 0) return false;
	if(!first && n != 0) cout << '\n';

	vector<int> v(n), sol(6);
	vector<bool> used(n, false);
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	

	for (int i1 = 0; i1 < n - 5; ++i1) {
		for (int i2 = i1 + 1; i2 < n - 4; ++i2) {
			for (int i3 = i2 + 1; i3 < n - 3; ++i3) {
				for (int i4 = i3 + 1; i4 < n - 2; ++i4) {
					for (int i5 = i4 + 1; i5 < n - 1; ++i5) {
						for (int i6 = i5 + 1; i6 < n; ++i6) {
							cout << v[i1] << ' ' << v[i2] << ' ' << v[i3];
							cout << ' ' << v[i4] << ' ' << v[i5] << ' ';
							cout << v[i6] << '\n';
						}
					}
				}
			}
		}
	}
	first = false;
	return true;
}

int main() {
	bool f = true;
	while (solve(f));
}