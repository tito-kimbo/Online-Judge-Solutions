//TAMBIEN SOLUCIONA EL 59
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <fstream>
using namespace std;

const int INF = 100000000;

struct bar {
	int length, cost;
};

istream &operator >> (istream &in, bar &b) {
	in >> b.length >> b.cost;
	return in;
}

struct info {
	bool possible;
	unsigned long long int ways;
	int minN, minC;
};

bool operator==(const info &i1,const info &i2) {
	return i1.possible == i2.possible && i1.ways == i2.ways && i1.minN == i2.minN &&
		i1.minC == i2.minC;
}

const info AUX = { false,0,INF,INF };

//Probably needs iterative DP
info compose(bar &b, info &i1, info &i2) {
	return { i1.possible || i2.possible, i1.ways + i2.ways, min(i1.minN,i2.minN + 1), min(i1.minC, i2.minC+b.cost)};
}

info iterDP(int n, int L, vector<bar> &v) {
	//Fill DP table in adequate order
	vector<info> table(L+1,AUX);
	info aux1, aux2;

	table[0] = { true, 1,0,0 };
	if(v[0].length <= L) table[v[0].length] = { true, 1, 1, v[0].cost };

	for (int i1 = 1; i1 < n; ++i1) {
		for (int i2 = L; i2 >=0; --i2) {
			if (i2 == 0) table[i2] = { true, 1,0,0 };
			else if (v[i1].length <= i2) table[i2] = compose(v[i1], table[i2], table[i2 - v[i1].length]);
		}
	}

	return table[L];
}

//Recursive DP
info dp(int i, int used, int cost, int L, vector<bar> &v, vector<vector<info>> &table) {
	//Base cases: (i,0,v),(v.length(), L, v)
	if (!(table[i][L] == AUX)) return table[i][L];
	info ret;

	if (L == 0) ret =  {true, 1, used, cost};
	else if (i == v.size()) ret = { false,0,INF,INF };
	else {
		info i1, i2;
		if(v[i].length <= L) i1 = dp(i+1, used+1, cost+v[i].cost, L-v[i].length,v,table);
		else i1 = { false, 0, INF, INF };
		i2 = dp(i + 1, used, cost, L, v,table);
		ret = { i1.possible || i2.possible, i1.ways + i2.ways, min(i1.minN,i2.minN), min(i1.minC,i2.minC) };
	}
	table[i][L] = ret;
	return ret;
}

bool solve() {
	int N, L;
	cin >> N >> L;
	if (!cin) return false;
	vector<bar> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	//Para aplicar DP con memoization nos hace falta una tabla en la que almacenar valores
	//vector<vector<info>> memo(N+1, vector<info>(L+1, AUX));
	//info result = dp(0, 0, 0, L, v, memo);
	info result = iterDP(N,L,v);

	if (result.possible) {
		cout << "SI " << result.ways << ' ' << result.minN << ' ' << result.minC << '\n';
	}
	else cout << "NO\n";

	return true;
}

int main() {
	//ifstream in("data.txt");
	//cin.rdbuf(in.rdbuf());

	while (solve());
	//system("pause");
}