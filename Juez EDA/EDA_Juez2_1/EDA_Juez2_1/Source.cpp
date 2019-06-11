//Eduardo Rivero Rodríguez
#include <iostream>
#include <exception>
#include <string>
#include <vector>

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

		inline bool operator<(const Hora & h)
		{
			return ( (hora < h.hora) || (hora == h.hora && minuto < h.minuto) 	|| (hora == h.hora && minuto == h.minuto 
				&& segundo < h.segundo) );
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
std::istream & operator>>(std::istream & is, Hora & par)
{
	char aux;
	int h, m, s;

	is >> h >> aux >> m >> aux >> s;

	try
	{
		par = Hora(h,m,s);
	}
	catch (ParameterException)
	{
		is.clear();
		par = Hora();
		throw parexception;
	}

	return is;
}

//Supondremos v ordenado creciente. Observemos que, aunque h es una referencia, no se modifica 
//[se mantiene para poder utilizar el comparador definido anteriormente]

//Aplicando un esquema divide y vencerás, encuentra la mejor aproximación mayor o igual que el elemento dado o, en caso de no existir,
//devuelve la última posición del vector.
int buscaBin(const std::vector<Hora> & v, Hora & h, int a, int b)
{
	int medio, ret;

	medio = (a + b) / 2;

	if (b - a == 1)
	{
		ret = a;
	}
	else
	{
		if (h < v[medio])
		{
			if (h < v[medio - 1]) //Obs: medio > 0 SIEMPRE en este punto. Asegura que no haya una mejor aproximación
			{
				ret = buscaBin(v, h, a, medio);
			}
			else if (h == v[medio - 1])
			{
				ret = medio - 1;
			}
			else
			{
				ret = medio;
			}
		}
		else if (h == v[medio])
		{
			ret = medio;
		}
		else //h > v[medio]
		{
			ret = buscaBin(v, h, medio, b);
		}
	}

	return ret;
}

//Complejidad -> O(t+n+n*logt) contando lectura. O(n*logt) sin contar lectura
//t es el número de trenes y n el número de consultas
void resolver(int t, int n)
{
	std::vector<Hora> v;
	Hora aux;
	int ind;

	for (int i = 0; i < t; i++)
	{
		std::cin >> aux;
		v.push_back(aux);
	}

	for (int j = 0; j < n; j++)
	{
		try
		{
			std::cin >> aux; //Hora de consulta

			//APLICAMOS DyV --- v.size() equiv t
			ind = buscaBin(v, aux, 0, v.size()); 

			if (aux < v[ind] || aux == v[ind])
			{
				std::cout << v[ind] << '\n';
			}
			else //ind = t-1 y no hay elementos en el vector mayores o iguales que la hora
			{
				std::cout << "NO\n";
			}
		}
		catch (ParameterException p)
		{
			std::cout << p.what();
		}
	}
	std::cout << "---\n";
}

int main()
{
	int t, n;

	std::cin >> t >> n;
	while (t != 0 && n != 0)
	{
		resolver(t, n);
		std::cin >> t >> n;
	}
}