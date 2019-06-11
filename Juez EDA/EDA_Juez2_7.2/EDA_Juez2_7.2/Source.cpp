#include "Hora.h"
#include "operable_queue.h"

void solve(int n) {
	Hora h;
	operable_queue<Hora> q;

	for (int i = 0; i < n; i++) {
		std::cin >> h;
		q.push(h);
	}
	q.removeLower();

	std::cout << q << '\n';
}

int main() {
	int n;

	std::cin >> n;
	while (n > 0) {
		solve(n);
		std::cin >> n;
	}
}