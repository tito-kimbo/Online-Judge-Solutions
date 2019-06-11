#include <iostream>
using namespace std;

bool resolver(int H, int U, int D, int F, int &day) {
	//H: height, U: can climb, D: drop at night, F: fatigue %
	float gain, currentHeight;

	gain = U;
	currentHeight = 0;
	day = 0;
	while (currentHeight <= (float)H && currentHeight >= 0.0f) {
		currentHeight += gain;
		if(currentHeight <= (float)H) currentHeight -= D;

		gain -= (float)U*((float)F / 100.0f);
		if(gain < 0) gain = 0;
		day++;
	}
	return currentHeight >= H;
}

int main() {
	int H, U, D, F, day;

	cin >> H >> U >> D >> F;
	while (H != 0) {
		if (resolver(H, U, D, F, day)) {
			cout << "success";
		}
		else {
			cout << "failure";
		}
		cout << " on day " << day << '\n';
		cin >> H >> U >> D >> F;
	}
}