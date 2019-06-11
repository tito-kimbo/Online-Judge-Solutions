#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//W1 es la palabra original y W2 la invertida
//Quitar de W1 es quitar de la izquierda
int dp(int i, int j,string &w1, string &w2, vector<vector<int>> &m) {
	if (i == w1.size() || j == w2.size()) return 0;
	else if (m[i][j] != -1) return m[i][j];
	else {
		if (w1[i] == w2[j]) m[i][j] = dp(i + 1, j + 1, w1, w2, m)+1;
		else m[i][j] = max(dp(i+1,j,w1,w2,m), dp(i,j+1,w1,w2,m));
	}
	return m[i][j];
}

string rebuild(string &w1, vector<vector<int>> &m) {
	string ans = "";
	int i, j, s;
	i = j = 0;
	s = w1.size();
	while (i < s && j < s) {
		if (w1[i] == w1[s - j - 1]) {
			ans.push_back(w1[i]);
			++i; 
			++j;
		}
		else if (i == s - 1 && j == s - 1) break;
		else if (i == s - 1) ++j;
		else if (j == s - 1) ++i;
		else if (m[i + 1][j] >= m[i][j + 1]) ++i;
		else ++j;
	}
	/*if (w1[i] == w1[s - j]) a1.push_back(w1[i]);
	else if (a1.size() < gSize) {

	}*/

	return ans;
}

bool solve() {
	string word, rev;
	getline(cin, word);
	if (!cin) return false;

	rev = word;
	reverse(rev.begin(), rev.end());
	vector<vector<int>> v(word.size(), vector<int>(word.size(), -1));
	int s = dp(0,0,word, rev, v);
	//cout << "SIZE: " << s << '\n';
	cout << rebuild(word, v) << '\n';

	return true;
}

int main() {
	//ifstream in("input.txt");
	//ofstream out("output.txt");
	//cin.rdbuf(in.rdbuf());
	//cout.rdbuf(out.rdbuf());
	while (solve());
}