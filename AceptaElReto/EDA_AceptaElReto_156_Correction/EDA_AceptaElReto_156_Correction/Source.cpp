#include <iostream>
#include <cstdio>

int main() {
	int n, ini, end;

	scanf("%d", &ini);
	while (ini >= 0) {	

		n = 0;
		scanf("%d", &end);
		while (end != -1) {

			if (ini > end) {
				n += ini - end;
			}
			else {
				n += end - ini;
			}

			ini = end;
			scanf("%d", &end);
		}
		printf("%d\n", n);
		//std::cout << n << '\n';

		scanf("%d", &ini);
	}
}