#include <iostream>
#include <algorithm>
using namespace std;

int getKnights(int m, int n) {
	int result;

	if (m == 1) {
		result = n;
	}
	else if (m == 2 && n <= 2) {
		result = n*m;
	}
	else if (m == 2) {
		result = 4*(n / 4);
		if (n % 4 == 1) {
			result += 2;
		}
		else if (n%4 >=2){
			result += 4;
		}
	}
	else {
		result = (m*n + 1) / 2;
	}

	return result;
}

int main(){
	int m, n;

	cin >> m >> n;
	while (m != 0 || n != 0) {
		cout << getKnights(min(m,n), max(m,n)) << " knights may be placed on a ";
		cout << m << " row " << n << " column board.\n";
		cin >> m >> n;
	}
}