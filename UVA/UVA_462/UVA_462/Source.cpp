#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <istream>
#include <vector>
using namespace std;

const char SUITS[] = { 'S', 'H', 'D', 'C' };

bool solve() {
	string aux;

	getline(cin, aux);
	if (!cin) return false;

	unordered_map<char, int> suitInHand;
	unordered_map<char, bool> stopped;
	vector<string> cards;
	istringstream is(aux);
	int points = 0;
	for (int i = 0; i < 4; ++i) {
		suitInHand[SUITS[i]] = 0;
		stopped[SUITS[i]] = false;
	}

	is >> aux;
	while (is) {
		suitInHand[aux[1]]++;
		cards.push_back(aux);
		is >> aux;
	}

	//STOP?
	for (int i = 0; i < cards.size(); i++){
		if (cards[i][0] == 'A') {
			points += 4;
			stopped[cards[i][1]] = true;
		}
		else if (cards[i][0] == 'K') {
			points += 3;
			if (suitInHand[cards[i][1]] == 1) {
				points--;
			}
			else {
				stopped[cards[i][1]] = true;
			}
		}
		else if (cards[i][0] == 'Q') {
			points += 2;
			if (suitInHand[cards[i][1]] <= 2) {
				points--;
			}
			else {
				stopped[cards[i][1]] = true;
			}
		}
		else if (cards[i][0] == 'J') {
			points += 1;
			if (suitInHand[cards[i][1]] <= 3) {
				points--;
			}
		}
	}

	//cout << "POINTS: " << points << '\n';
	if (stopped[SUITS[0]] && stopped[SUITS[1]] && stopped[SUITS[2]] && stopped[SUITS[3]] && points >= 16) {
		cout << "BID NO-TRUMP\n";
	}
	else {
		for (int i = 0; i < 4; ++i) {
			if (suitInHand[SUITS[i]] == 2) {
				points += 1;
			}
			else if (suitInHand[SUITS[i]] == 1) {
				points += 2;
			}
			else if (suitInHand[SUITS[i]] == 0) {
				points += 2;
			}
		}

		if (points < 14) {
			cout << "PASS\n";
		}
		else {
			//Choose best
			char best = 'S';
			for (int i = 1; i < 4; ++i) {
				if (suitInHand[SUITS[i]] > suitInHand[best]) {
					best = SUITS[i];
				}
			}

			cout << "BID " << best << '\n';
		}
	}
	//cout << "POINTS: " << points << '\n';
	return true;
}

int main(){
	while (solve());
}