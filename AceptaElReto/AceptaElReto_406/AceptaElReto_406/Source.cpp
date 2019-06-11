#include <string>
#include <iostream>
using namespace std;

const char EMPTY = '.';
const char TRAFFIC_LIGHT = '|';

void move(int i, int j, string &s) {
	if(j != s.size()) s[j] = s[i];
	if(i != j) s[i] = EMPTY;
}

//Linear solution O(n)
bool solve() {
	string street;

	getline(cin, street);
	if (!cin) return false;

	int lastAvailable = street.size();
	//Process movement
	for (int i = lastAvailable-1; i >= 0; --i) {
		if (street[i] == TRAFFIC_LIGHT) {
			lastAvailable = i - 1;
		} else if(street[i] != EMPTY) {
			move(i, lastAvailable, street);
			lastAvailable = (lastAvailable == street.size()) ? lastAvailable : lastAvailable-1;
		}
	}

	int n,aux;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		if (i != 0) cout << ' ';
		cout << street[aux-1];
	}
	cout << '\n';
	cin.get();
	return true;
}

int main() {
	while (solve());
}