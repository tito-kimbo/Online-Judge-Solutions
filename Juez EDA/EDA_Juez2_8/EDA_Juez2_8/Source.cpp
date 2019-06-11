#include <iostream>
#include <string>
#include "persona.h"
#include "filtered_list.h"

//Crea una estructura función (podría ser una clase)
struct criterio {
	int min, max;

	bool operator()(const persona & p) {
		return (min <= p.getEdad() && max >= p.getEdad());
	}
};

void resolver(const int & n, const int & min, const int & max) {
	filtered_list<persona> l;
	criterio c;
	char a;
	std::string nombre;
	int edad;
	persona aux;

	c.min = min;
	c.max = max;
	for (int i = 0; i < n; i++) {
		std::cin >> edad;
		std::cin.get(a);
		std::getline(std::cin, nombre);
		aux = persona(nombre, edad);
		l.push_back(aux);
	}
	//Filtramos por los criterios creados
	l.remove_if(c);

	for (int i = 0; i < (int)l.size(); i++) {
		std::cout << l.at(i) << '\n';
	}
	std::cout << "---\n";
}

int main() {
	int nPers, minEdad, maxEdad;

	std::cin >> nPers >> minEdad >> maxEdad;
	while (nPers != 0 || minEdad != 0 || maxEdad != 0) {
		resolver(nPers, minEdad, maxEdad);
		std::cin >> nPers >> minEdad >> maxEdad;
	}
}