#include <iostream>
#include <fstream>
using namespace std;

struct point_i {
	int x, y;
	point_i() {}
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

bool operator==(point_i p1, point_i p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

//Special case, same rectangle
bool overlap(point_i l1, point_i u1, point_i l2, point_i u2, bool & same) {
	bool xOverlap, yOverlap;
	
	same = (l1 == l2) && (u1 == u2);
	xOverlap = (l1.x <= l2.x && l2.x < u1.x) ||
			   (l1.x < u2.x && u2.x <= u1.x) ||
			   (l2.x <= l1.x && l1.x < u2.x) ||
			   (l2.x < u1.x && u1.x <= u2.x); 

	yOverlap = (l1.y <= l2.y && l2.y < u1.y) ||
			   (l1.y < u2.y && u2.y <= u1.y) ||
			   (l2.y <= l1.y && l1.y < u2.y) ||
			   (l2.y < u1.y && u1.y <= u2.y);

	return same || (xOverlap && yOverlap);
}

void solve(bool last) {
	point_i lower1, upper1, lower2, upper2;
	int x, y;

	//First rectangle
	cin >> x >> y;
	lower1 = point_i(x, y);
	cin >> x >> y;
	upper1 = point_i(x, y);

	//Second rectangle
	cin >> x >> y;
	lower2 = point_i(x, y);
	cin >> x >> y;
	upper2 = point_i(x, y);

	bool same;
	//Check for overlap
	if (overlap(lower1, upper1, lower2, upper2, same)) {
		//Calculate intersection
		//First we calculate lower left
		point_i intLower, intUpper;

		//cout << "SAME: " << same << '\n';
		if (same) {
			intLower = lower1;
			intUpper = upper1;
		}
		else {
			if (lower1.x <= lower2.x && lower1.y <= lower2.y) {
				intLower = lower2;
			}
			else if (lower1.x <= lower2.x) {
				intLower = point_i(lower2.x, lower1.y);
			}
			else { //lower2.x < lower1.x
				if (lower1.y <= lower2.y) {
					intLower = point_i(lower1.x, lower2.y);
				}
				else {
					intLower = lower1;
				}
			}

			//Now we calculate lower right
			//Only 2 candidates -> upper1 OR upper2
			if (upper2.x <= upper1.x && upper2.y <= upper1.y) {
				intUpper = upper2;
			}
			else if (upper2.x <= upper1.x) {
				intUpper = point_i(upper2.x, upper1.y);
			}
			else { //upper1.x < upper2.x
				if (upper2.y <= upper1.y) {
					intUpper = point_i(upper1.x, upper2.y);
				}
				else {
					intUpper = upper1;
				}
			}
		}

		cout << intLower.x << ' ' << intLower.y << ' ';
		cout << intUpper.x << ' ' << intUpper.y << '\n';
	}
	else {
		cout << "No Overlap\n";
	}
	if(!last) cout << '\n';
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve(i==(n-1));
	}
}