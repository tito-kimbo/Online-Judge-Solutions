#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double PI = 2 * acos(0.0);

void solve() {
	int D, L;
	double a, b;

	cin >> D >> L;
	
	//Area of ellipse
	a = 0.5*L;
	b = 0.5*sqrt(L*L-D*D);

	cout << fixed << setprecision(3) << PI*a*b << '\n';
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		solve();
	}
}