#include <iostream>
#include <string>
using namespace std;

bool solve() {
	string s;

	cin >> s;
	if (s == ".") return false;

	int N = 0, G = 0;
	while (s != ".") {
		if (s == "N") {
			if (N == 0) N++;
			else N--;
		}
		else if (s == "G") {
			if (G == 0) G++;
			else G--;
		}
		cin >> s;
	}

	if (N == 0 && G == 0) cout << "EMPAREJADOS\n";
	else if (N == 1 && G == 0) cout << "NEGRO SOLITARIO\n";
	else if (N == 0 && G == 1) cout << "GRIS SOLITARIO\n";
	else cout << "PAREJA MIXTA\n";

	return true;
}


int main() {
	while (solve());
}