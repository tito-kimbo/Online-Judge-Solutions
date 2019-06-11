#include <iostream>
#include <string>
using namespace std;

//When?
bool swapSign(string const& currentDir, string const& newDir) {
	if (currentDir[1] == 'x' && newDir[0] == '-'
		|| currentDir[1] == 'y' && newDir == "+y"
		|| currentDir[1] == 'z' && newDir == "+z")
	{
		return true;
	}
	else {
		return false;
	}
}

void solve(int n) {
	string currentDir;
	string aux;

	cin >> currentDir;
	if (currentDir == "No") currentDir = "+x";
	for (int i = 1; i < n-1; ++i) {
		cin >> aux;
		if (aux != "No") {
			//New sign
			if (swapSign(currentDir, aux)) {
				currentDir[0] == '+' ? currentDir[0] = '-' : currentDir[0] = '+';
			}
			//New value
			if (currentDir[1] == 'x') {
				currentDir[1] = aux[1];
			}
			else if (currentDir[1] == aux[1]) {
				currentDir[1] = 'x';
			}
		}
	}

	cout << currentDir << '\n';
}

int main() {
	int n;
	
	cin >> n;
	while (n != 0) {
		solve(n);
		cin >> n;
	}
}