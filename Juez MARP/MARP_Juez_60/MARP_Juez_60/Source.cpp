#include <iostream>
#include <vector>
using namespace std;

struct info {
	int gold, depth;	
};

struct ans {
	int nChests;
	long long int maxGold;
};
bool operator == (ans &a1, ans & a2) { return a1.nChests == a2.nChests && a1.maxGold == a2.maxGold; }
const ans NONE = { 0,0 };

//TLE, should check
//Probably optimizing space should suffice
ans dp(int n, int T, vector<info> &c, vector<vector<ans>> &m) {
	if (m[n][T].nChests != 0) return m[n][T];
	if (T == 0 || n<1) m[n][T] = NONE;
	else {
		if (T < 3*c[n].depth) {
			if (n == 0) return NONE; //could not choose any
			else m[n][T] = dp(n-1,T,c,m);
		}
		else { //T >= 3*c[n].depth (down and up)
			ans a1, a2;
			a1 = dp(n - 1, T, c, m);
			a2 = dp(n - 1, T - 3*c[n].depth, c, m);
			a2.nChests++;
			a2.maxGold += c[n].gold;
			if (a1.maxGold > a2.maxGold) {
				m[n][T] = a1;
			}
			else {
				m[n][T] = a2;
			}
		}
	}
	return m[n][T];
}

void rebuild(int i, int j, vector<info> &chests, vector<vector<ans>> &v) {
	if (i != 0 && j != 0) {
		if (v[i][j] == v[i - 1][j]) {
			rebuild(i - 1,j, chests, v);
		}
		else {
			rebuild(i - 1, j - 3*chests[i].depth, chests, v);
			cout << chests[i].depth << ' ' << chests[i].gold << '\n';
		}
	}
}

bool solve(){
	int T,N;
	cin >> T;
	if (!cin) return false;
	cin >> N;
	info aux;
	vector<info> v(N+1);
	for (int i = 0; i < N; ++i) {
		cin >> aux.depth >> aux.gold;
		v[i+1] = aux;
	}

	vector<vector<ans>> sol(N+1, vector<ans>(T+1,NONE));
	ans a = dp(N, T, v, sol);

	cout << a.maxGold << '\n';
	cout << a.nChests << '\n';
	rebuild(N, T, v,sol);
	cout << "----\n";

	return true;
}

int main() {
	while (solve());
}