#include "Util.h"
#include <iostream>

bool resolver() {
	int nOps;

	cin >> nOps;
	if (!cin) return false;

	venta_libros vl;
	string op;
	for (int i = 0; i < nOps; ++i) {
		cin >> op;

		if (op == "nuevoLibro") {
			libro x;
			int n;

			cin >> n;
			cin.get();
			getline(cin, x);
			vl.nuevoLibro(n, x);
		}
		else if (op == "comprar") {
			libro x;
			cin.get();
			getline(cin,x);

			try {
				vl.comprar(x);
			}
			catch (invalid_argument ia) {
				cout << "Libro no existente" << '\n';
				cout << "---\n";
			}
			catch (out_of_range oor) {
				cout << "No hay ejemplares" << '\n';
				cout << "---\n";
			}
		}
		else if (op == "numEjemplares") {
			libro x;
			cin.get();
			getline(cin, x);

			try {
				int n = vl.numEjemplares(x);

				cout << "Existen " << n << " ejemplares del libro " << x;
			}
			catch (invalid_argument ia) {
				cout << "No existe el libro " << x << " en el sistema";
			}
			cout << "\n---\n";

		}
		else if (op == "estaLibro") {
			libro x;
			cin.get();
			getline(cin,x);

			if (vl.estaLibro(x)) {
				cout << "El libro " << x << " esta en el sistema";
			}
			else {
				cout << "No existe el libro " << x << " en el sistema";
			}
			cout << "\n---\n";
		}
		else if (op == "elimLibro") {
			libro x;
			cin.get();
			getline(cin,x);
			vl.elimLibro(x);
		}
		else if (op == "top10") {
			vector<libro> v = vl.top10();

			for (int i = 0; i < (int)v.size(); ++i)
			{
				cout << v[i] << '\n';
			}
			cout << "---\n";
		}
	}

	cout << "------\n";
	return true;
}

int main() {
	while (resolver());
}