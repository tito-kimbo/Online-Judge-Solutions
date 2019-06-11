#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long int lli;

/* WA -> Some numbers are not generated (some error in the recursion,
first error occurs at ~[10^9, 10^10]

int binSize(lli n) {
	int i = 0;
	while (n > 0) {
		n /= 2;
		++i;
	}
	return i;
}

//We can generate all and use a map, then iterate
bool solve() {
	lli X, Y, count;
	cin >> X >> Y;
	if (!cin) return false;
	if (X == 0) X++;

	if (X > Y) {
		cout << 0 << '\n';
	}
	else {
		count = 0;
		lli generated1 = 0;
		int sX = binSize(X), sY = binSize(Y);
		for (int size = sX; size <= sY; size++) {
			for (lli a = 1; a < size; ++a) {
				for (lli b = size - a; b >= 0; --b) {
					for (lli k = 0; k < size;) {
						if (b == 0 && a != 1) break;
						lli kVal = k;
						for (lli j = kVal; j - kVal < a; ++j, ++k) {
							generated1 += 1 << (size - j - 1);
						}
						if (k < size) {
							kVal = k;
							for (lli j = kVal; j - kVal < b; ++j, ++k) {}
						}
						if (k > size) {
							generated1 = -1;
						}
					}
					if (X <= generated1 && generated1 <= Y)++count;
					//cout << "Generated 1 is " << generated1 << '\n';
					generated1 = 0;
				}
			}
		}
		if (X <= 1 && 1 <= Y) count++;
		cout << count << '\n';
	}

	return true;
}*/

vector<lli> v;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	streambuf *coutbuf = cout.rdbuf();
	streambuf *cinbuf = cin.rdbuf();

	//cout.rdbuf(out.rdbuf());
	//cin.rdbuf(in.rdbuf());

	//WE GENERATE ALL NUMBERS - 64 bit rep size
	lli aux = 0;
	for (lli N = 1; N <= 64; ++N) {
		aux = aux << 1 | 1;
		for (int M = 1; M <= 64; ++M) {
			lli number = aux;
			for (int i = N; i <= 64; ++i) {
				v.push_back(number);
				number = number << M;
				number = number << N | aux;
			}
			number = aux << M;
			for (int i = N + M; i <= 64; i += N + M) {
				v.push_back(number);
				number = number << N | aux;
				number = number << M;
			}
		}
	}
	sort(v.begin(),v.end());
	//cout << v.size() << '\n';
	v.resize(unique(v.begin(),v.end()) - v.begin());
	lli X, Y;
	cin >> X >> Y;
	while (cin) {
		int count = 0;
		for (auto val : v) {
			if (X <= val && val <= Y) {
				++count;
			}
		}
		cout << count << '\n';
		cin >> X >> Y;
	}

	cout.rdbuf(coutbuf);
	cin.rdbuf(cinbuf);
}