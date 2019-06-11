#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <unordered_map>
using namespace std;

typedef string profesor;
typedef string alumno;


class autoescuela {
private:
	
	unordered_map <alumno, profesor> alumnos;
	unordered_map < profesor, set<alumno>> profesores;
	unordered_map <alumno, int> puntuaciones;

public: 

	//Complejidad O(logn)
	void alta(alumno a, profesor p) {
		if (alumnos.count(a) == 1) {
			profesores[alumnos[a]].erase(a);
		} else {
			puntuaciones[a] = 0;
		}
		alumnos[a] = p;
		profesores[p].insert(a);
	}

	//O(logn)
	bool es_alumno(alumno a, profesor p) {
		return profesores[p].count(a) == 1;
	}

	//O(1)
	int puntuacion(alumno a) {
		if (alumnos.count(a) == 0) {
			throw invalid_argument("El alumno " + a + " no esta matriculado");
		}
		return puntuaciones[a];
	}

	//O(1)
	void actualizar(alumno a, int n) {
		if (alumnos.count(a) == 0) {
			throw invalid_argument("El alumno " + a + " no esta matriculado");
		}
		puntuaciones[a] += n;
	}

	//O(n) respecto al numero de alumnos asociados a p
	vector<alumno> examen(profesor p, int threshold) {
		vector<alumno> aux;
		for (auto it = profesores[p].begin(); it != profesores[p].end(); it++) {
			if (puntuaciones[*it] >= threshold) {
				aux.push_back(*it);
			}
		}

		return aux;
	}

	//O(logn)
	void aprobar(alumno a) {
		if (alumnos.count(a) == 0) {
			throw invalid_argument("El alumno " + a + " no esta matriculado");
		}
		profesores[alumnos[a]].erase(a);
		alumnos.erase(a);
		puntuaciones.erase(a);
	}

};

#endif
