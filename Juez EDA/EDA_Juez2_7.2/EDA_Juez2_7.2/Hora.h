#ifndef HORA_H
#define HORA_H
#include <exception>
#include <string>
#include <iostream>

//Excepción a lanzar
/*class ParameterException : public std::exception
{
public:

	virtual const char* what() const throw()
	{
		return "ERROR\n";
	}

} parexception;
*/

//TAD Principal
class Hora
{
public:
	Hora()
	{
		hora = 0;
		minuto = 0;
		segundo = 0;
	}

	Hora(int h, int m, int s)
	{
		if ((LIMI_H <= h && h <= LIMS_H) && (LIMI_MS <= m && m <= LIMS_MS) && (LIMI_MS <= s && s <= LIMS_MS))
		{
			hora = h;
			minuto = m;
			segundo = s;
		}
		else
		{
			//throw parexception;
		}
	}

	inline bool operator<(const Hora & h)
	{
		return ((hora < h.hora) || (hora == h.hora && minuto < h.minuto) || (hora == h.hora && minuto == h.minuto
			&& segundo < h.segundo));
	}

	inline bool operator==(const Hora & h)
	{
		return (hora == h.hora && minuto == h.minuto && segundo == h.segundo);
	}

	int getHora() const
	{
		return hora;
	}
	int getMinuto() const
	{
		return minuto;
	}
	int getSegundo() const
	{
		return segundo;
	}

private:
	int hora, minuto, segundo;
	const static int LIMS_H = 23, LIMI_H = 0, LIMS_MS = 59, LIMI_MS = 0;
};

//Convierte un entero a 2 dígitos
inline std::string to2Dig(const int & n)
{
	std::string aux;

	if (n < 10)
	{
		aux = "0" + std::to_string(n);
	}
	else
	{
		aux = std::to_string(n);
	}

	return aux;
}

//Da formato en un flujo de salida de datos
inline std::ostream & operator<<(std::ostream & os, const Hora & h)
{
	os << to2Dig(h.getHora()) + ':' + to2Dig(h.getMinuto()) + ':' + to2Dig(h.getSegundo());
	return os;
}

//Extrae de un flujo de entrada de datos
inline std::istream & operator >> (std::istream & is, Hora & par)
{
	char aux;
	int h, m, s;

	is >> h >> aux >> m >> aux >> s;

	par = Hora(h, m, s);

	return is;
}

#endif