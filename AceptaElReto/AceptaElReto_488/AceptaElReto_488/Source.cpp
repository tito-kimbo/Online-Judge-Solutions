#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int nG, period;
	cin >> nG >> period;

	vector<int> v(nG);
	for (int i = 0; i < nG; ++i) cin >> v[i];

	int sessions = 0,index=0, time = 0;

	while (index < v.size()) {
		++sessions;
		while(index < v.size() && v[index] <= time+period) ++index;
		time = v[index-1];
	}
	cout << sessions << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)solve();
}