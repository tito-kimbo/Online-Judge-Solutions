#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int N, A, B;
		cin >> N >> A >> B;
		int uvas = 0;
		while (N > 0) {
			if (N <= A) {
				uvas += N;
				N = 0;
			}
			else { //N > A
				uvas += A;
				N -= B;
			}
		}
		cout << uvas << '\n';
	}
}