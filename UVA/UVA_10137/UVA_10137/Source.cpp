#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPS = 0.00000001;

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;
	double avg = 0.0;
	vector<double> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		avg += v[i];
	}
	avg = round(100*avg/n)/100.0;

	double total = 0.0, total2 = 0.0, aux;
	int i = 0;
	for (int i = 0; i < n; ++i) {
		aux = v[i]-avg;
		if (aux > EPS) {
			total += aux;
		}
		else if(aux < -EPS){
			total2 += -aux;
		}
	}
	total = min(total,total2);

	cout << setprecision(2) << fixed << '$' << total << '\n';
	return true;
}

int main() {
	while (solve());
}