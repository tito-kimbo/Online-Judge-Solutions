#include "operable_queue.h"
#include "Hora.h"

void solve(int n) {
	Hora aux;
	operable_queue<Hora> v;

	for (int i = 0; i < n; i++) {
		std::cin >> aux;
		v.push(aux);
	}
	v.removeEven();

	std::cout << v << '\n';
}

int main() {
	int n;

	std::cin >> n;
	while (n > 0) {
		solve(n);
		std::cin >> n;
	}
}