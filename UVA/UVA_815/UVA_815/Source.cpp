#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const long long int MULT = 100;
const double EPS = 0.000000001;

bool solve(int &val) {
	int m, n;
	cin >> m >> n;
	if (m == 0 && n == 0) return false;

	vector<int> v(m*n);
	long long int TOTAL_AREA = MULT*m*n;
	long long int currentArea, height;
	long long int water;
	for (int i = 0; i < n*m; ++i) {
		cin >> v[i];
	}
	cin >> water;
	sort(v.begin(), v.end());
	double water_level;
	double percentage;

	bool finished = false;
	int i, mult;
	if (water == 0) {
		mult = 0;
	}
	else {
		mult = 1;
	}
	height = v[0];
	for (i = 0; i < v.size() && !finished; ++i) {
		currentArea = (i+1)*MULT;
		if (i < v.size() - 1) {
			//Try to fill up to next level
			if (water >= currentArea*(v[i + 1] - v[i])) {
				water -= currentArea*(v[i + 1] - v[i]);
				height += v[i + 1] - v[i];
				water_level = height;
			}
			else { //Fill up everything we can
				water_level = height + (double)water / (double)currentArea;
				water = 0;
			}
		}
		else {
			//Fill up everything we can;
			water_level = height + (double)water / (double)currentArea;
			water = 0;
		}
		finished = water <= 0;
	}
	percentage = mult*100.0*((double)currentArea/(double)TOTAL_AREA);
	
	cout << "Region " << val << '\n';
	cout << "Water level is " << setprecision(2) << fixed << water_level << " meters.\n";
	cout << setprecision(2) << fixed <<  percentage << " percent of the region is under water.\n\n";

	++val;
	return true;
}

int main() {
	int i = 1;
	while (solve(i));
}