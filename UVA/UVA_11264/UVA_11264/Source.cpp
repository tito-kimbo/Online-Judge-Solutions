#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve() {
	int n, aux, sum, max;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	sum = 1;
	if (v.size() == 1) {
		max = 1;
	}
	else {
		max = 2; //Always can get smallest and largest
	}
	for (int i = 0; i < n-1; ++i) {
		if (sum + v[i] < v[i + 1]) { //If sum is not i+1th coin we can get ith
			sum += v[i];
			max++;
		}
	}

	return max;
}

int main(){
	int N;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cout << solve() << '\n';
	}
}