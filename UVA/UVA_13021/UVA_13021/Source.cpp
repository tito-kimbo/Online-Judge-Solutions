#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool solve() {
	int P, K;
	cin >> P >> K;
	if (!cin) return false;
	vector<long long int> sizes(P);

	int size,aux;
	for (int i = 0; i < P; ++i) {
		cin >> size;
		sizes[i] = size % (K+1);
		for (int j = 0; j < size; ++j) {
			cin >> aux;
		}
	}
	//THE GRUNDY NUMBERS NEED TO BE CALCULATED 
	//WE APPLY minimax WITH depth 1
	//APPLY SPRAGUE-GRUNDY THEOREM
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	streambuf *coutbuf = cout.rdbuf();
	streambuf *cinbuf = cin.rdbuf();

	cout.rdbuf(out.rdbuf());
	cin.rdbuf(in.rdbuf());
	while (solve());
	cout.rdbuf(coutbuf);
	cin.rdbuf(cinbuf);
}