#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef vector<int> VI;

//POR QUE NO FUNCIONA?
void resolver(int n) {
	int aux;
	VI v;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	int i;
	bool modified = false;
	for (i = n - 1; i > 0 && !modified; --i) {
		if (v[i] == v[i - 1]) {
			v[i]++;
			modified = true;
		}
	}
	if (!modified) {
		v[0]++;
		cout << v[0];
		for (int i = 1; i < n; ++i) {
			cout << ' ' << v[0];
		}
	}
	else {
		for (i = i+1; i < n-1; ++i) {
			v[i + 1] = v[i];
		}
		cout << v[0];
		for (int i = 1; i < n; ++i) {
			cout << ' ' << v[i];
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int n;

	cin >> n;
	while (n != 0) {
		resolver(n);
		cin >> n;
	}
}