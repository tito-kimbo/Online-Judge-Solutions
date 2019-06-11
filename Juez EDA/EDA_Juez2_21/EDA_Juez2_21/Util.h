#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <functional> //funcion hash para fecha
using namespace std;

typedef string medico;
typedef string paciente;

class fecha {
private:
	int dia, hora, minuto;

public:
	fecha(int d, int h, int m) {
		dia = d;
		hora = h;
		minuto = m;
	}

	int getDia() const {
		return dia;
	}

	int getHora() const {
		return hora;
	}

	int getMinuto() const{
		return minuto;
	}

	void imprimeHora() const {
		cout << setw(2) << setfill('0') << hora;
		cout << ':';
		cout << setw(2) << setfill('0') << minuto;
	}


};

bool operator<(fecha & f1, fecha &f2) {
	return	f1.getDia() < f2.getDia() ||
				f1.getDia() == f2.getDia() && f1.getHora() < f2.getHora() ||
				f1.getDia() == f2.getDia() && f1.getHora() == f2.getHora() &&
				f1.getMinuto() < f2.getMinuto();
}

bool operator==(const fecha & f1, const fecha & f2) {
	return f1.getDia() == f2.getDia() &&
				f1.getHora() == f2.getHora() &&
				f1.getMinuto() == f2.getMinuto();
}

namespace std {
	template <>
	struct hash<fecha> {
		size_t operator()(const fecha &f) const {
			return hash<int>()(f.getDia()) 
					^ hash<int>()(f.getHora())
					^ hash<int>()(f.getMinuto());
		}
	};
}

class consultorio {
private:
	unordered_map<medico, unordered_map<fecha, paciente>> medicos;
	unordered_map<medico, deque<fecha>> consultas;

public:

	//Coste constante O(1)
	void nuevoMedico(const medico & m) {
		medicos[m];
	}

	//Coste lineal O(f) respecto al numero de fechas asociadas a m
	void pideConsulta(paciente & p, medico & m, fecha & f){
		if (medicos.count(m) == 0) {
			throw invalid_argument("Medico no existente");
		}
		else if (medicos[m].count(f) == 1) {
			throw invalid_argument("Fecha ocupada");
		} else {
			stack<fecha> aux;
			medicos[m][f] = p;
			while (!consultas[m].empty() && f < consultas[m].back()) {
				aux.push(consultas[m].back());
				consultas[m].pop_back();
			}
			consultas[m].push_back(f);
			while (!aux.empty()) {
				consultas[m].push_back(aux.top());
				aux.pop();
			}
		}
	}

	//Coste constante O(1)
	void atiendeConsulta(medico & m) {
		if (medicos.count(m) == 0) {
			throw invalid_argument("Medico no existente");
		}
		else if (medicos[m].size() == 0) {
			throw invalid_argument("No hay pacientes");
		}else{
			medicos[m].erase(consultas[m].front());
			consultas[m].pop_front();
		}
	}

	//Coste constante O(1);
	paciente siguientePaciente(medico &m) {
		paciente p = "";
		if (medicos.count(m) == 0) {
			throw invalid_argument("Medico no existente");
		} else if(medicos[m].size() == 0) {
			throw invalid_argument("No hay pacientes");
		} else {
			p = medicos[m][consultas[m].front()];
		}
		return p;
	}

	/*	Coste O(nPacientes) asociados al medico m */
	vector<pair<paciente,fecha>> listaPacientes(medico & m, int & dia) {
		vector<pair<paciente, fecha>> v;
		if (medicos.count(m) == 0) {
			throw invalid_argument("Medico no existente");
		}
		else {
			//Vector construido a partir de iteradores
			vector<fecha> f =
				vector<fecha>(consultas[m].begin(), consultas[m].end());
			for (int i = 0; i < f.size(); ++i) {
				pair<paciente, fecha> p =
					pair<paciente, fecha>(medicos[m][f[i]], f[i]);
				if (f[i].getDia() == dia) v.push_back(p);
			}
		}
		
		return v;
	}
};

#endif