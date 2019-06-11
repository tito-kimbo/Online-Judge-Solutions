#include <iostream>
#include <vector>
#include <map>

bool resolver() {
	int n, k, copies, detected, aux;
	std::vector<int> v;
	std::map<int, int> m;

	std::cin >> n >> k;
	if (!std::cin) return false;

	for (int i = 0; i < n; ++i) {
		std::cin >> aux;
		v.push_back(aux);
	}
	
	copies = 0;
	//NOW COUNT REAL COPIES
	for (int i = 0; i < n; ++i) {
		m[v[i]]++;
		if (m[v[i]] > 1) copies++;
	}

	detected = 0;
	//NOW COUNT DETECTED COPIES
	m.clear();
	aux = 0;
	for (int i = 0; i < k+1 && i < n; ++i) {
		m[v[i]]++;
		if (m[v[i]] > 1) detected++;
	}
	for (int i = k+1; i < n; ++i) {
		m[v[aux]]--;
		m[v[i]]++;
		if (m[v[i]] > 1) detected++;
		++aux;
	}

	std::cout << copies << ' ' << detected << '\n';

	return true;
}

int main() {
	while (resolver());
}