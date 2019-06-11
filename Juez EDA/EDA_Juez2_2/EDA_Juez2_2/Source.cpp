//Eduardo Rivero Rodríguez
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <algorithm>

//Reutilizamos el código del ejercicio anterior

//Excepción a lanzar
class ParameterException : public std::exception
{
public:

	virtual const char* what() const throw()
	{
		return "ERROR\n";
	}

} parexception;

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
			throw parexception;
		}
	}

	Hora operator+(const Hora & h1) const
	{
		int h, m, s;

		s = segundo + h1.segundo;
		m = minuto + h1.minuto + (s/MAX_MS);
		h = hora + h1.hora + (m/MAX_MS);

		if (h >= MAX_H)
		{
			throw parexception;
		}

		s -= MAX_MS*(s / MAX_MS);
		m -= MAX_MS*(m / MAX_MS);

		return{ h,m,s };
	}

	inline bool operator<(const Hora & h) const
	{
		return ((hora < h.hora) || (hora == h.hora && minuto < h.minuto) || (hora == h.hora && minuto == h.minuto
			&& segundo < h.segundo));
	}

	inline bool operator==(const Hora & h) const
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
	const static int MAX_H = 24, MAX_MS = 60;
};

//Convierte un entero a 2 dígitos
std::string to2Dig(const int & n)
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
std::ostream & operator<<(std::ostream & os, const Hora & h)
{
	os << to2Dig(h.getHora()) + ':' + to2Dig(h.getMinuto()) + ':' + to2Dig(h.getSegundo());
	return os;
}

//Extrae de un flujo de entrada de datos
std::istream & operator >> (std::istream & is, Hora & par)
{
	char aux;
	int h, m, s;

	is >> h >> aux >> m >> aux >> s;

	try
	{
		par = Hora(h, m, s);
	}
	catch (ParameterException)
	{
		is.clear();
		par = Hora();
		throw parexception;
	}

	return is;
}

//La clase película
class pelicula
{
	public:

		pelicula() {}
		pelicula(const Hora & ini, const Hora & dur, const std::string & n)
		{
			hInicio = ini;
			duracion = dur;
			nombre = n;
			hFin = hInicio + duracion;
		}

		Hora getFin() const
		{
			return hFin;
		}

		std::string getNombre() const
		{
			return nombre;
		}

		inline bool operator<(const pelicula & p) const
		{
			return ( (hFin < p.hFin) || (hFin == p.hFin && nombre < p.nombre));
		}

	private:
		Hora hInicio, duracion, hFin;
		std::string nombre;
};

//Inserción/Extracción
std::ostream & operator<<(std::ostream & os, const pelicula & p)
{
	os << p.getFin() << ' ' << p.getNombre();
	return os;
}

std::istream & operator >> (std::istream & is, pelicula & p)
{
	Hora h1, h2;
	std::string n;

	is >> h1 >> h2;
	std::getline(is, n, '\n');
	p = pelicula(h1, h2, n);

	return is;
}

//Complejidad O(nlogn) resp. del número de películas
//por ser la lectura de datos lineal y 'sort' un quicksort -> O(nlogn)
void resolver(int n)
{
	pelicula p;
	std::vector<pelicula> v;

	for (int i = 0; i < n; i++)
	{
		std::cin >> p;
		v.push_back(p);
	}

	std::sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i] << '\n';
	}
	std::cout << "---\n";
}

int main()
{
	int n;

	std::cin >> n;
	while (n != 0)
	{
		resolver(n);
		std::cin >> n;
	}
}