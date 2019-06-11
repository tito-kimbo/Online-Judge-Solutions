#include <iostream>
#include <string>
using namespace std;

struct weekly_data {
	float max, min;
	int diaMax, diaMin;
	bool repetidoMax, repetidoMin;
};

string intToDay(int d) {
	switch (d) {
	case 0: return "MARTES";
	case 1: return "MIERCOLES";
	case 2: return "JUEVES";
	case 3: return "VIERNES";
	case 4: return "SABADO";
	case 5: return "DOMINGO";
	}
}

void resolver(float & aux) {
	weekly_data d;
	float sum;

	d.max = d.min = aux;
	d.diaMax = d.diaMin = 0;
	d.repetidoMax = d.repetidoMin = false;
	sum = aux;

	//READ AND UPDATE
	for (int i = 1; i < 6; ++i) {
		std::cin >> aux;

		if (aux > d.max) {
			d.max = aux;
			d.diaMax = i;
			d.repetidoMax = false;
		}
		else if (aux == d.max) {
			d.repetidoMax = true;
		}

		if (aux < d.min) {
			d.min = aux;
			d.diaMin = i;
			d.repetidoMin = false;
		}
		else if (aux == d.min) {
			d.repetidoMin = true;
		}

		sum += aux;
	}

	cout << intToDay(d.diaMax) << ' ' << intToDay(d.diaMin) << ' ';
	if (aux > (sum / 6.0f)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	float first;

	std::cin >> first;
	while ((int)first != -1) {
		resolver(first);
		std::cin >> first;
	}
}