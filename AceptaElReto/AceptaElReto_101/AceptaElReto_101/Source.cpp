#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int sumMainDiag(const VVI &m) {
	int sum = 0;
	for (int i = 0; i < m.size(); ++i) {
		sum += m[i][i];
	}
	return sum;
}

int sumInvDiag(const VVI &m){
	int sum = 0;
	for (int i = 0; i < m.size(); ++i) {
		sum += m[i][m.size()- 1 - i];
	}
	return sum;
}

//MC is magical constant (Supposes m magical)
bool isDiabolical(const VVI &m, const int & MC) {
	return sumMainDiag(m) == MC && sumInvDiag(m) == MC;
}

//Supposes diabolical
bool isEsoteric(const VVI &m, const int & MC) {
	int MC2 = 4 * MC / m.size();
	int sum;
	vector<int> v;

	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m.size(); ++j) {
			v.push_back(m[i][j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m.size()*m.size(); ++i) {
		if (v[i] != i + 1) return false;
	}

	sum = m[0][0] + m[0].back() +m.back()[0] + m.back().back();
	if (sum != MC2) return false;

	//IMPAR
	if (m.size() % 2 != 0) {

		if (4 * m[m.size() / 2][m.size() / 2] != MC2) return false;

		sum = m[0][m.size() / 2] + m[m.size() / 2][0] + m[m.size() / 2].back() + m.back()[m.size() / 2];
		if (sum != MC2) return false;

	} //PAR
	else {
		sum = m[m.size() / 2][m.size() / 2] + m[m.size() / 2][m.size() / 2 - 1]
			+ m[m.size() / 2 - 1][m.size() / 2] + m[m.size() / 2 - 1][m.size() / 2 - 1];
		if (sum != MC2) return false;

		sum = m[0][m.size() / 2] + m[0][m.size() / 2 - 1]
			+ m[m.size() / 2][0] + m[m.size() / 2 - 1][0]
			+ m[m.size() / 2].back() + m[m.size() / 2 - 1].back()
			+ m.back()[m.size() / 2] + m.back()[m.size() / 2 - 1];

		if (sum != 2 * MC2) return false;
				
	}

	return true;
}

void solve(int n) {
	VVI matrix;
	int num, MC;

	for (int i = 0; i < n; ++i) {
		VI aux;
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			cin >> num;
			sum += num;
			aux.push_back(num);
		}
		MC = sum;
		matrix.push_back(aux);
	}

	if (isDiabolical(matrix, MC)) {
		if (isEsoteric(matrix, MC)) {
			cout << "ESOTERICO\n";
		}
		else {
			cout << "DIABOLICO\n";
		}
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		solve(n);
		cin >> n;
	}
}