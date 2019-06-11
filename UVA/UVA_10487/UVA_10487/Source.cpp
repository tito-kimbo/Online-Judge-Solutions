#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

void solve(int n) {
	int queries, closestSum, obj, minDist, aux;
	vector<int> set;

	for(int i=0;i<n;++i){
		cin >> aux;
		set.push_back(aux);
	}

	cin >> queries;
	for (int i = 0; i < queries; ++i) {
		cin >> obj;
		minDist = INT_MAX;
		for (int j = 0; j < set.size() - 1; ++j) {
			for (int k = j + 1; k < set.size(); ++k) {
				aux = set[j] + set[k];
				if (abs(obj - aux) < minDist) {
					minDist = abs(obj - aux);
					closestSum = aux;
				}
			}
		}
		cout << "Closest sum to " << obj << " is " << closestSum << ".\n";
	}
}

int main() {
	int c, n;

	c = 1;
	cin >> n;
	while (n != 0) {
		cout << "Case " << c << ":\n";
		solve(n);
		cin >> n;
		c++;
	}
}