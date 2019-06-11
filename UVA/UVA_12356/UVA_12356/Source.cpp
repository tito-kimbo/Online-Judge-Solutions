#include <iostream>
using namespace std;


//More efficient: use a static array
int leftBuddies[100009], rightBuddies[100009];

bool solve() {
	//memset(leftBuddies,-1,10009);
	//memset(rightBuddies, -1, 10009);
	int B, S;
	cin >> S >> B;
	if (S == 0 && B == 0) return false;
	leftBuddies[1] = -1;
	rightBuddies[1] = 2;
	rightBuddies[S] = -1;
	if(S != 1) leftBuddies[S] = S - 1;
	for (int i = 2; i < S; ++i) {
		leftBuddies[i] = i - 1;
		rightBuddies[i] = i + 1;
	}

	int l, r;
	for (int i = 0; i < B; ++i) {
		cin >> l >> r;

		//Update left
		leftBuddies[rightBuddies[r]] = leftBuddies[l];
		if (leftBuddies[l] == -1) cout << "* ";
		else cout << leftBuddies[l] << ' ';

		//Update right
		rightBuddies[leftBuddies[l]] = rightBuddies[r];
		if (rightBuddies[r] == -1) cout << "*\n";
		else cout << rightBuddies[r] << '\n';

	}
	cout << "-\n";
	return true;
}

int main(){

	

	while (solve());
}