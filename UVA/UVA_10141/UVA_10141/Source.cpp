#include <iostream>
#include <string>
using namespace std;

string solve(int const&n, int const&p) {
	string optimalRFP;
	int optimalRequirements = -1;
	float optimalCost = -1;
	string aux;

	cin.get();
	for (int i = 0; i < n; ++i) {
		getline(cin, aux);
	}

	int reqMet;
	float price;
	for (int i = 0; i < p; ++i) {
		getline(cin, aux);
		cin >> price >> reqMet;

		if (reqMet > optimalRequirements || (reqMet == optimalRequirements && (price < optimalCost || optimalCost == -1))) {
			optimalRFP = aux;
			optimalRequirements = reqMet;
			optimalCost = price;
		}
		cin.get();
		for (int j = 0; j < reqMet; ++j) getline(cin, aux);
	}

	return optimalRFP;
}

int main() {
	bool first = true;
	int rfp = 1;
	int n, p;

	cin >> n >> p;
	while (n != 0 || p != 0) {
		string str = solve(n, p);
		if(!first)cout << '\n';
		cout << "RFP #" << rfp << '\n';
		cout << str << '\n';
		rfp++;
		cin >> n >> p;
		first = false;
	}
	
}