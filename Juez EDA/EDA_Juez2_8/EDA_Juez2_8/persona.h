#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class persona {
	public:

		persona() {}
		persona(const std::string & n, int e) {
			nombre = n;
			edad = e;
		}

		std::string getNombre() const {
			return nombre;
		}

		int getEdad() const {
			return edad;
		}

	private:
		std::string nombre;
		int edad;
};

std::ostream & operator<<(std::ostream & out, const persona & p) {
	out << p.getNombre();
	return out;
}

#endif
