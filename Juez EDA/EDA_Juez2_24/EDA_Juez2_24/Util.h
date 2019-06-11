#ifndef UTIL_H
#define UTIL_H
#include <set>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
using namespace std;

typedef string libro;

struct datos_libro {
	libro titulo;
	int ultVenta;
	int ventas;
};

class venta_libros {
private:
	int tiempo = 0;
	unordered_map <libro, int> ejemplares;
	unordered_map<libro, datos_libro> data;

	struct custom_comp {
		bool operator()(datos_libro const& dl1, datos_libro const&dl2) const {
			return dl1.ventas > dl2.ventas || (dl1.ventas == dl2.ventas && dl1.ultVenta > dl2.ultVenta);
		}
	};
	set<datos_libro, custom_comp> listaOrdenada;

public:

	//O(logn)
	void nuevoLibro(const int &n, const libro &x) {
		if (!ejemplares.count(x) == 1) {
			datos_libro dl;
			dl.titulo = x;
			dl.ultVenta = -1;
			dl.ventas = 0;
			data[x] = dl;
		}

		ejemplares[x] += n;
	}

	//O(logn)
	void comprar(const libro &x) {
		if (!estaLibro(x)) {
			throw invalid_argument("Libro no existente");
		}
		else {
			if (ejemplares[x] == 0) {
				throw out_of_range("No hay ejemplares");
			}
			else {
				listaOrdenada.erase(data[x]);
				ejemplares[x]--;
				data[x].ultVenta = tiempo;
				data[x].ventas++;
				listaOrdenada.insert(data[x]);
				tiempo++;
			}
		}
	}

	//O(1)
	bool estaLibro(const libro &x) {
		return ejemplares.count(x) == 1;
	}

	//O(logn)
	void elimLibro(const libro &x) {
		ejemplares.erase(x);
		listaOrdenada.erase(data[x]);
		data.erase(x);
		//ELIMINAMOS DEL SET => O(logn)
	}

	//O(1)
	int numEjemplares(const libro &x) {
		if (!estaLibro(x)) {
			throw invalid_argument("Libro no existente");
		}
		else {
			return ejemplares[x];
		}
	}

	//O(1) 
	vector<libro> top10() {
		vector<libro> t10;

		int count = 0;
		for (auto it = listaOrdenada.begin(); it != listaOrdenada.end() && count<10; it++) {
			t10.push_back(it->titulo);
			count++;
		}

		return t10;
	}

};

#endif
