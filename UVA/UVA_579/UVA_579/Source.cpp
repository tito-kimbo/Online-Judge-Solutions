#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const static int TOTAL = 360;
const static float HOUR_ANGLE = TOTAL / 12.0f;
const static float MINUTE_ANGLE = TOTAL / 60.0f;

bool solve() {
	int hours, minutes;

	cin >> hours;
	cin.get();
	cin >> minutes;

	if (hours == 0 && minutes == 0) return false;

	float hoursAngle, minutesAngle;

	
	minutesAngle = (float) ((int)(minutes*MINUTE_ANGLE)%TOTAL);
	hoursAngle = (hours+(minutes/60.0f))*HOUR_ANGLE;
	if (hoursAngle >= 360) hoursAngle -= 360;

	float max, min, distance;

	if (hoursAngle >= minutesAngle) {
		max = hoursAngle;
		min = minutesAngle;
	} else {
		max = minutesAngle;
		min = hoursAngle;
	}
	
	if (max - min >= 360+min-max) {
		distance = 360+min-max;
	}
	else {
		distance = max - min;
	}

	cout << setprecision(3) << fixed << distance << '\n';

	return true;
}

int main() {
	while (solve());
}