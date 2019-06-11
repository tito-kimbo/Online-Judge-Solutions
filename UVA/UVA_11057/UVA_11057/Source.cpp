#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool solve(bool &f) {
	int n, obj, i,j, solI, solJ;
	vector<int> v;

	if (!f) {
		string aux;
		f = false;
		getline(cin, aux);
	}
	cin >> n;
	if (!cin) return false;

	for (int i = 0; i < n; ++i) {
		cin >> obj;
		v.push_back(obj);
	}
	cin >> obj;

	
	solI = i = 0;
	solJ = j = v.size() - 1;
	int sum = v[i] + v[j];

	sort(v.begin(), v.end());
	while (i < j) {
		if (sum < obj) {
			++i;
		} else if(sum > obj) {
			--j;
		}
		else {
			solI = i;
			solJ = j;
			++i;
		}

		sum = v[i] + v[j];
	}

	cout << "Peter should buy books whose prices are " << v[solI];
	cout << " and " << v[solJ] << ".\n\n";

	return true;
}

int main() {
	bool first = true;
	while (solve(first));
}