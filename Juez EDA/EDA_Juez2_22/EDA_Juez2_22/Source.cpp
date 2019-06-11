#include <iostream>
#include "Util.h"

bool resolver() {
	autoescuela ae;
	string op;

	cin >> op;
	if (!cin) return false;

	while (op != "FIN") {
		try {
			if (op == "alta") {
				alumno a;
				profesor p;

				cin >> a >> p;
				ae.alta(a, p);
			}
			else if (op == "es_alumno") {
				alumno a;
				profesor p;

				cin >> a >> p;
				cout << a;
				if (ae.es_alumno(a, p)) {
					cout << " es alumno de ";
				}
				else {
					cout<< " no es alumno de ";
				}
				cout << p << '\n';
			}
			else if (op == "puntuacion") {
				alumno a;
				int p;

				cin >> a;
				p = ae.puntuacion(a);
				cout << "Puntuacion de " << a << ": " << p << '\n';
			}
			else if (op == "actualizar") {
				alumno a;
				int n;

				cin >> a >> n;
				ae.actualizar(a, n);
			}
			else if (op == "examen") {
				vector<alumno> v;
				profesor p;
				int puntos;

				cin >> p >> puntos;
				v = ae.examen(p, puntos);
				cout << "Alumnos de " << p << " a examen:\n";
				for (int i = 0; i < v.size(); ++i) {
					cout << v[i] << '\n';
				}
			}
			else if (op == "aprobar") {
				alumno a;
				cin >> a;
				ae.aprobar(a);
			}
		}
		catch (invalid_argument ia) {
			cout << "ERROR\n";
		}
		

		cin >> op;
	}
	cout << "------\n";
	return true;
}

int main() {
	while (resolver());
}