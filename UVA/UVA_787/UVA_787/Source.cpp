#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
//NEEDS JAVA IMPLEMENTATION

const long long int FINAL = -999999;

//Kadane algorithm adaptation for max subsequence product
long long int KadaneProd(vector<long long int> &v) {
	long long int minimum, maximum, current, aux1, aux2;

	minimum = maximum = current = v[0];
	if (minimum > 0) minimum *= 0;
	if (maximum < 0) maximum *= 0;

	for (int i = 1; i < v.size(); ++i) {
		aux1 = v[i] * maximum;
		aux2 = v[i] * minimum;
		minimum = min(v[i], min(aux1, aux2));
		maximum = max(v[i], max(aux1, aux2));
		current = max(current, maximum);
	}

	return current;
}

bool solve() {
	long long int N, aux;
	vector< long long int> v;

	cin >> aux;
	if (!cin) return false;

	while (aux != FINAL) {
		v.push_back(aux);
		cin >> aux;
	}
	cout << KadaneProd(v) << '\n';

	return true;
}

int main() {
	while (solve());
}