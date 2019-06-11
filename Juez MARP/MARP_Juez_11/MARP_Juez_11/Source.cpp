//Eduardo Rivero Rodríguez
#include <iostream>
#include <climits>
#include <math.h>
#include <algorithm>
using namespace std;

//Once again, it is possible to code this without accumulator params but the code is somewhat messier.
//An option is creating a struct {int min, max, height; bool isAVL;}treeInfo; and returning it at isAVL
bool isAVL(int root, int &minimum, int &maximum, int &height) {
	if (root == -1) {
		maximum = 0;
		minimum = INT_MAX;
		height = 0;
		return true;
	}
	else {
		int rLeft, rRight;
		int minLeft, minRight;
		int maxLeft, maxRight;
		int hLeft, hRight;
		bool avlLeft, avlRight;

		//First left
		cin >> rLeft;
		avlLeft = isAVL(rLeft, minLeft, maxLeft, hLeft);
		//Then right
		cin >> rRight;
		avlRight = isAVL(rRight, minRight, maxRight, hRight);

		//Min/max assignment is only correct if tree is actually AVL
		minimum = min(root, minLeft);
		maximum = max(root, maxRight);
		height = max(hLeft, hRight) + 1;
		return avlLeft && avlRight && (abs(hLeft-hRight)<=1) && (maxLeft < root && minRight > root);
	}
}

void solve() {
	int root, min, max, height;
	cin >> root;
	if (isAVL(root, min, max, height)) {
		cout << "SI\n";
	} else {
		cout << "NO\n";
	}

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
}

