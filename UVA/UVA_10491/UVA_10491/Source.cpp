#include <iostream>
#include <iomanip>
using namespace std;

bool solve() {
	int NCOWS, NCARS, NSHOW;

	cin >> NCOWS >> NCARS >> NSHOW;
	if (!cin) return false;
	double prob;
	int TOTAL = NCOWS + NCARS;
	//P{win} = P{Car | Car,Swap} + P{Car | Cow,Swap}
	prob = ((NCARS-1)/(double)(TOTAL-NSHOW-1))*(NCARS/(double)TOTAL)+((NCARS)/(double)(TOTAL-NSHOW-1))*(NCOWS/(double)TOTAL);

	cout << fixed << setprecision(5) << prob  << '\n';
	return true;
}

int main(){
	while (solve());
}