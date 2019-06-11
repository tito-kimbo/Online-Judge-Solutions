#include <iostream>
#include <algorithm>
#include <string>
#include <climits>


template <class T>
T resolver(const T currentMin, const T & delimiter) {
	int countEmpty;
	T val, min;

	std::cin >> val;
	if (val != delimiter) {
		min = std::min(currentMin, val);
		if (min == delimiter) min = val;
		for (int i = 0; i < 2; ++i) {
			min = resolver(min, delimiter);
		}
	}
	else {
		min = currentMin;
	}

	return min;
}

int main() {
	char what;
	std::string delim = "#";
	
	std::cin >> what;
	while (std::cin) {
		if (what == 'N') {
			std::cout << resolver(INT_MAX, -1) << '\n';
		}
		else {
			std::cout << resolver(delim, delim) << '\n';
		}
		std::cin >> what;
	}
}