#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct paciente {
	string nombre;
	int gravedad, index;

	paciente(string _nombre, int _gravedad, int _ind) : nombre(_nombre), gravedad(_gravedad), index(_ind) {}
};

bool operator<(paciente const &p1, paciente const&p2) {
	return p1.gravedad < p2.gravedad || (p1.gravedad == p2.gravedad && p1.index > p2.index);
}

bool solve() {
	int n;
	cin >> n;
	if (n == 0) return false;
	priority_queue<paciente> pq;
	char op;

	string nombre;
	int grav;
	for (int i = 0; i < n; ++i) {
		cin >> op;
		if (op == 'A') {
			cout << pq.top().nombre << '\n';
			pq.pop();
		}
		else { //op = 'I'
			cin >> nombre >> grav;
			cin.get();
			pq.push(paciente(nombre, grav, i));
		}
	}
	cout << "----\n";

	return true;
}

int main() {
	while (solve());
}