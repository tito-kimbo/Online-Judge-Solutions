#include <iostream>
#include <string>
#include <set>
using namespace std;

const string WIN_MESSAGE = "You win.";
const string LOSE_MESSAGE = "You lose.";
const string CHICKENED_MESSAGE = "You chickened out.";

int solve() {
	set<char> wordChars, guessed, missed;
	string word, guess;
	int misses = 0;

	//cin >> word;
	cin.get();
	getline(cin, word);
	cin >> guess;

	for (int i = 0; i < word.size(); ++i) {
		if (word[i] != ' ') {
			wordChars.insert(word[i]);
		}
	}

	for (int i = 0; i < guess.size(); ++i) {
		if (wordChars.count(guess[i]) == 1 
			&& guessed.count(guess[i]) == 0) {
			guessed.insert(guess[i]);
		}else if(guessed.count(guess[i]) == 0 
			&& missed.count(guess[i])==0) {
			misses++;
			missed.insert(guess[i]);
		}

		if (misses == 7) {
			return -1;
		}
		else if (guessed.size() == wordChars.size()) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n, ans;

	cin >> n;
	while (n != -1) {
		ans = solve();

		cout << "Round " << n << '\n';
		if (ans == 1) {
			cout << WIN_MESSAGE;
		}
		else if (ans == 0) {
			cout << CHICKENED_MESSAGE;
		}
		else { //ans = -1
			cout << LOSE_MESSAGE;
		}
		cout << '\n';
		cin >> n;
	}
}