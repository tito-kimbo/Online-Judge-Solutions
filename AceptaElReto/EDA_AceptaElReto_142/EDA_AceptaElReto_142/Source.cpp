#include <iostream>
#include <queue>
//#pragma warning(disable:4996)


int main() {
	std::queue<int> q;
	int ninos, salto;
	int count;

	scanf("%i%i", &ninos, &salto);
	//std::cin >> ninos >> salto;
	while (ninos != 0) {
		count = 0;
		++salto;
		for (int i = 0; i < ninos; ++i) {
			q.push(i + 1);
		}

		while (q.size()>1) {
			count++;
			if (count % salto != 0) {
				q.push(q.front());
			}
			else {
				count = 0;
			}
			q.pop();

		}
		//std::cout << q.front() << '\n';
		printf("%i\n", q.front());
		q.pop();

		//std::cin >> ninos >> salto;
		scanf("%i%i", &ninos, &salto);
	}
}