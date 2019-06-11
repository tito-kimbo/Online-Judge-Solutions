#include <iostream>
#include <stack>
#include <deque>
using namespace std;

const int NUMBER_OF_CARDS = 52;
const int CARDS_TO_TAKE = 25;
const int REPETITIONS = 3;
const int DEFAULT_VALUE = 10;

struct card {
	char value, suit;
};

istream &operator >> (istream& in, card &read) {
	char v, c;

	in >> v >> c;
	read = { v,c };

	return in;
}

ostream &operator<<(ostream& out, card &write) {
	out << write.value << write.suit;
	return out;
}

int value(const card &c) {
	return ('2' <= c.value && c.value <= '9') ? c.value - '0' : DEFAULT_VALUE;
}

void solve(int n) {
	stack<card> pile;
	deque<card> auxQueue;
	card aux;

	for (int i = 0; i < NUMBER_OF_CARDS; ++i) {
		cin >> aux;
		cin.get();
		pile.push(aux);
	}

	//Execute the operations
	int yValue = 0, removed = 0;
	for (int i = 0; i < REPETITIONS; ++i) {
		for (int j = 0; j < CARDS_TO_TAKE; ++j) {
			auxQueue.push_back(pile.top());
			pile.pop();
		}

		int currentValue = value(pile.top());
		yValue += currentValue;
		//Remove the card and 10-X cards from pile
		pile.pop();
		removed++;
		for (int j = 0; j < 10-currentValue; ++j) {
			pile.pop();
			removed++;
		}

		//Place back
		while (!auxQueue.empty()) {
			pile.push(auxQueue.back());
			auxQueue.pop_back();
		}
	}

	for (int i = 0; i < (NUMBER_OF_CARDS-removed)-yValue; ++i) {
		pile.pop();
	}
	cout << "Case " << n << ": "  << pile.top() << '\n';
}

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i) {
		solve(i+1);
	}
}