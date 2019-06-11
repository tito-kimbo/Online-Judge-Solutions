//Eduardo Rivero Rodríguez
#include <iostream>
#include <string>
#include <stdexcept>

const int INT_LIM = -1;
const std::string STR_LIM = "FIN";

template <class T>
class set //ORDENADO!
{
	public:
		set(size_t tam = TAM_INICIAL); // constructor
		set(set<T> const& other); // constructor por copia
		set<T> & operator=(set<T> const& other); // operador de asignación
		~set(); // destructor
		void insert(T e); //La inserción debe hacerse ordenando
		bool contains(T e) const;
		void erase(T e);
		bool empty() const;
		size_t size() const;
		T checkLowest() const;
		void removeLowest();
	private:
		const static size_t TAM_INICIAL = 8;
		size_t contador;
		size_t capacidad;
		T * datos;
		void amplia();
		void libera();
		void copia(set<T> const& other);
};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() 
{
	libera();
}

template <class T>
void set<T>::libera() 
{
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) 
{
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) 
{
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) 
{
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) //Insertamos teniendo en cuenta el orden
{
	int i;

	if (!contains(e)) 
	{
		++contador;
		if (contador >= capacidad)
			amplia();

		i = 0;
		while (i < (int)contador - 1 && e > datos[i])
		{
			++i;
		}

		for (int j = contador - 1; j > i; j--)
		{
			datos[j] = datos[j - 1];
		}
		datos[i] = e;

		datos[contador] = e;
	}
}

template <class T>
bool set<T>::contains(T e) const 
{
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}

template <class T>
void set<T>::amplia() 
{
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) 
{
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const 
{
	return contador == 0;
}

template <class T>
size_t set<T>::size() const 
{
	return contador;
}

//O(1)
template <class T>
T set<T>::checkLowest() const
{
	if (datos != nullptr)
	{
		return datos[0];
	}
	else
	{
		return NULL;
	}
}

//O(n)
template <class T>
void set<T>::removeLowest()
{
	if (datos != nullptr)
	{
		contador--;
		for(int i = 0; i < (int)contador; i++)
		{
			datos[i] = datos[i + 1];
		}
	}
	//else -> pass
}

//Complejidad O(n^2) -> Por inserción ordenada y eliminación del elemento más bajo lineal 
template <class T>
void resolver(int n, const T & delimiter)
{
	set<T> s;
	T aux;

	std::cin >> aux;
	while (aux != delimiter)
	{
		if ((int)s.size() == n && s.checkLowest() < aux)
		{
			if (!s.contains(aux))
			{
				s.removeLowest();
			}
			s.insert(aux);
		}
		else if((int)s.size() < n)
		{
			s.insert(aux);
		}

		std::cin >> aux;
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << s.checkLowest();
		if (i != n - 1)
		{
			std::cout << ' ';
		}
		s.removeLowest();
	}
	std::cout << '\n';
}

int main()
{
	int n;
	char c;

	std::cin >> c;
	while (std::cin)
	{
		std::cin >> n;
		
		switch (c)
		{
			case 'N':
			{
				resolver<int>(n, INT_LIM);
			}break;
			case 'P':
			{
				resolver<std::string>(n, STR_LIM);
			}break;
			default: {}
		}

		std::cin >> c;
	}
}