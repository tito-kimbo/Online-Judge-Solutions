#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	while (!(x == 0 && y == 0)) {

		if (x == 1) cout << 'h';
		else if (x == 2) cout << 'g';
		else if (x == 3) cout << 'f';
		else if (x == 4) cout << 'e';
		else if (x == 5) cout << 'd';
		else if (x == 6) cout << 'c';
		else if (x == 7) cout << 'b';
		else if (x == 8) cout << 'a';
		cout << y;
		cout << '\n';
		cin >> x >> y;
	}

}