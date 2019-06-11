#include <iostream>
#include "Util.h"

bool resolver() {
	string op;
	iPud ip;

	cin >> op;
	if (!cin) return false;

	while (op != "FIN") {
		try {
			if (op == "addSong") {
				string nombre, autor;
				int dur;

				cin >> nombre >> autor >> dur;
				ip.addSong(nombre, autor, dur);
			}
			else if (op == "addToPlaylist") {
				string nombre;

				cin >> nombre;
				ip.addToPlaylist(nombre);
			}
			else if (op == "current") {
				string actual = ip.current();
			}
			else if (op == "play") {
				try {
					string actual = ip.current();
					ip.play();
					cout << "Sonando " << actual << '\n';
				}
				catch (domain_error de) {
					cout << "No hay canciones en la lista" << '\n';
				}
			}
			else if (op == "totalTime") {
				cout << "Tiempo total " << ip.totalTime() << '\n';
			}
			else if (op == "recent") {
				int n;
				vector<cancion> v;

				cin >> n;
				v = ip.recent(n);

				if (v.size() == 0) {
					cout << "No hay canciones recientes\n";
				}
				else {
					cout << "Las " << v.size() << " mas recientes\n";
					for (int i = 0; i < v.size(); ++i) {
						cout << "    " << v[i] << '\n';
					}
				}
			}
			else if (op == "deleteSong") {
				string nombre;

				cin >> nombre;
				ip.deleteSong(nombre);
			}
		}
		catch (exception e) {
			cout << "ERROR " << op << '\n';
		}


		cin >> op;
	}
	cout << "----\n";

	return true;
}

int main() {
	while (resolver());
}