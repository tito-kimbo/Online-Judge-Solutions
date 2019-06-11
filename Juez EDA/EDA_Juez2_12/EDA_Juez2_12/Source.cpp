#include <iostream>
#include <vector>

bool resolver(std::vector<int> & front){
	int countEmpty, elem;

	std::cin >> elem;
	countEmpty = 0;
	if (elem == -1) return true;
	for (int i = 0; i < 2; ++i) {
		if (resolver(front)) {
			countEmpty++;
		}
	}
	if (countEmpty == 2) {
		front.push_back(elem);
	}
	return false;
}

int main() {
	std::vector<int> front;
	bool first;
	int n;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		resolver(front);

		first = true;
		for (int j = 0; j < front.size(); ++j) {
			if (!first) std::cout << ' ';
			std::cout << front[j];
			first = false;
		}
		std::cout << '\n';

		front.clear();
	}
}