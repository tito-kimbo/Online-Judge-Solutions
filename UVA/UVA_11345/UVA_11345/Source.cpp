#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

void solucionHorrible(int i) {
	int M, lowX, lowY, highX, highY;
	cin >> M;
	cin >> lowX >> lowY >> highX >> highY;
	for (int i = 1; i < M; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lowX = max(lowX, x1);
		lowY = max(lowY, y1);
		highX = min(highX, x2);
		highY = min(highY, y2);
	}

	cout << "Case " << i << ": ";
	if (lowX < highX && lowY < highY) {
		cout << (highX - lowX)*(highY - lowY) << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}

int main() {
	//ifstream in("in.txt");
	//streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	//cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	//ofstream out("out.txt");
	//streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	//cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; ++i) {
		//solve(i);
		solucionHorrible(i);
	}

	//cout.rdbuf(coutbuf);

}