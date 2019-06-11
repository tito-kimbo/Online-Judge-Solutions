#include <iostream>
#include <vector>
using namespace std;

bool solve(){
	int n, next;
	vector<int> seq;

	cin >> n;
	if (n == 0) return false;
	
	for (int i = 0; i < n; ++i) {
		cin >> next;
		if (next > 0) seq.push_back(next);
	}

	if (seq.empty()) {
		cout << "0\n";
	}
	else {
		for (int i = 0; i < seq.size()-1; ++i) {
			cout << seq[i] << ' ';
		}
		cout << seq[seq.size() - 1] << '\n';
	}

	return true;
}

int main() {
	while (solve());
}