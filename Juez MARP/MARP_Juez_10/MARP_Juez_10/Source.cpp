//Eduardo Rivero Rodríguez - MARP21
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

//Could be done without accumulator param by using struct, but gives slightly more tedious code
bool isBalanced(char root, int &height) {
	if (root == '.') {
		return true;
	}
	else { //root = R
		int hRight, hLeft;
		bool bRight, bLeft;
		char aux;
		hRight = hLeft = 0;
		
		//Read left first
		cin >> aux;
		bLeft = isBalanced(aux, hLeft);
		//Read right next
		cin >> aux;
		bRight = isBalanced(aux, hRight);

		height = max(hLeft, hRight) + 1;
		return bRight && bLeft && (abs(hLeft - hRight) <= 1);
	}
}

void solve() {
	int height = 0;
	char root;

	cin >> root;
	if (isBalanced(root, height)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
}