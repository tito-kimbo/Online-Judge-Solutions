#include <iostream>
#include <queue>
#include <istream>
using namespace std;

struct dep {
	int month;
	double val;
};

istream & operator >> (istream &is, dep & d) {
	is >> d.month;
	is >> d.val;
	return is;
}

bool solve() {
	int months, depreciations;
	double down_payment, amount, carVal;

	cin >> months >> down_payment >> amount;
	if (months < 0) return false;
	cin >> depreciations;
	carVal = amount + down_payment;
	
	int first = months;
	dep d;
	queue<dep> q;
	bool assigned = false;
	for (int i = 0; i < depreciations; ++i) {
		cin >> d;
		q.push(d);
	}
	double currentLoss;
	double toPay = amount / (double)months;
	for (int i = 0; i < months && !assigned; ++i) {
		if (!q.empty() && i == q.front().month) {
			currentLoss = q.front().val;
			q.pop();
		}
		carVal = (1-currentLoss)*carVal;
		if(i != 0) amount -= toPay;

		if (amount < carVal) {
			assigned = true;
			first = i;
		}
	}

	cout << first;
	if (first == 1) cout << " month";
	else cout << " months";
	cout << '\n';

	return true;
}

int main() {
	while (solve());
}