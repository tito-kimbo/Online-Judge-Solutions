#include <iostream>
#include <deque>
#include <vector>
#include <queue>

void resolver(const int & n, const int & l) {
	std::queue<int> q;
	std::deque<int> max;
	std::vector<int> v;
	int aux;

	for (int i = 0; i < l; i++) {
		std::cin >> aux;
		q.push(aux);
		if (max.empty() || max.front() < aux) {
			max.clear();
			max.push_back(aux);
		}
		else if (!max.empty()) {
			while (max.back() < aux) {
				max.pop_back();
			}
			max.push_back(aux);
		}
	}
	v.push_back(max.front());

	for (int t = l; t < n; t++) {
		std::cin >> aux;
		q.push(aux);

		if (q.front() == max.front()) max.pop_front();
		q.pop();

		if (!max.empty()) {
			while (!max.empty() && max.back() < aux) {
				max.pop_back();
			}	
		}
		max.push_back(aux);
		v.push_back(max.front());
		
	}

	bool first = true;
	for (int i : v) {
		if (!first) {
			std::cout << " ";
		}
		else {
			first = false;
		}
		std::cout << i;
	}
	std::cout << '\n';
}

int main() {
	int n, l;

	std::cin >> n >> l;
	while (n != 0 && l != 0) {
		resolver(n, l);
		std::cin >> n >> l;
	}
}