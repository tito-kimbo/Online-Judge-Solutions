#include <iostream>
#include <iomanip>
using namespace std;

void solve() {
	int hIni, mIni, sIni;
	int hFin, mFin, sFin;
	int n, c;

	cin >> hIni;
	cin.get();
	cin >> mIni;
	cin.get();
	cin >> sIni;

	cin >> hFin;
	cin.get();
	cin >> mFin;
	cin.get();
	cin >> sFin;
	
	cin >> n >> c;

	long long int ini, fin, intervalo, camp;

	if (hFin < hIni || (hFin == hIni && mFin < mIni) || (hFin == hIni && mFin == mIni && sFin <= sIni)) {
		hFin += 24;
	}

	fin = 3600 * hFin + 60 * mFin + sFin;
	ini = 3600 * hIni + 60 * mIni + sIni;
	intervalo = (fin - ini) / (n-1);

	int hC, mC, sC;
	hC = mC = sC = 0;
	camp = ini + (c-1)*intervalo;
	while (camp >= 3600) {
		camp -= 3600;
		hC++;
	}
	while (camp >= 60) {
		camp -= 60;
		mC++;
	}
	hC = hC % 24;

	sC = camp;
	cout << setw(2) << setfill('0') << hC;
	cout << ':';
	cout << setw(2) << setfill('0') << mC;
	cout << ':';
	cout << setw(2) << setfill('0') << sC;
	cout << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
}