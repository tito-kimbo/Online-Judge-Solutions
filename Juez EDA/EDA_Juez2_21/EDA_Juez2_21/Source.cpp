#include <iostream>
#include "Util.h"

bool resolver() {
	int nOps;

	cin >> nOps;
	if (!cin) return false;

	consultorio c;
	string op;

	for (int i = 0; i < nOps; i++) {
		cin >> op;
		try {
			if (op == "nuevoMedico") {
				medico med;
				cin >> med;

				c.nuevoMedico(med);
			}
			else if (op == "pideConsulta") {
				medico med;
				paciente pac;
				int d, h, m;

				cin >> pac >> med >> d >> h >> m;
				fecha f = fecha(d, h, m);

				c.pideConsulta(pac, med, f);
			}
			else if (op == "atiendeConsulta") {
				medico med;
				cin >> med;
				c.atiendeConsulta(med);
			}else if (op == "siguientePaciente") {
				paciente p;
				medico med;
				cin >> med;

				p = c.siguientePaciente(med);
				cout << "Siguiente paciente doctor " << med << '\n';
				cout << p << '\n';
				cout << "---\n";
			}
			else if (op == "listaPacientes") {
				vector<pair<paciente, fecha>> lista;
				medico med;
				int d;

				cin >> med >> d;
				lista = c.listaPacientes(med, d);

				cout << "Doctor " << med << " dia " << d << '\n';
				for (int i = 0; i < lista.size(); ++i) {
					cout << lista[i].first << ' ';
					lista[i].second.imprimeHora();
					cout << '\n';
				}
				cout << "---\n";
			}
		}
		catch (invalid_argument ia) {
			cout << ia.what() << '\n';
			cout << "---\n";
		}
	}
	cout << "------\n";
	

	return true;
}

int main() {
	while (resolver());
}