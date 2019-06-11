#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct user {
	int id, period, next;
};

bool operator<(const user & u1, const user & u2) {
	return (u1.next > u2.next) || (u1.next == u2.next && u1.id > u2.id);
}

istream & operator >> (istream & in, user &u) {
	in >> u.id >> u.period;
	u.next = u.period;
	return in;
}

ostream & operator << (ostream & out, user &u) {
	out << u.id;
	return out;
}

void resolver(int n) {
	int nQueries;
	priority_queue<user> pq;
	user aux;

	for (int i = 0; i < n; ++i) {
		std::cin >> aux;
		pq.push(aux);
	}
	std::cin >> nQueries;

	bool first = true;
	for (int i = 0; i < nQueries; ++i) {
		aux = pq.top();
		pq.pop();
		aux.next += aux.period;
		cout << aux.id << '\n';

		//std::cout << "UPDATE: " << aux.id << " -- PERIOD: " << aux.period << " -- NEXT: " << aux.next << '\n';
		pq.push(aux);
	}
	cout << "----\n";
}

int main() {
	int n;

	std::cin >> n;
	while (n != 0) {
		resolver(n);
		std::cin >> n;
	}
}