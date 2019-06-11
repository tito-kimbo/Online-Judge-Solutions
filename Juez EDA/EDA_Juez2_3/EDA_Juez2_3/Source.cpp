//Eduardo Rivero Rodríguez
#include <iostream>
#include <cmath>
#include <string>

const float LIMIT = 2.0f;

class complejo
{
	public:

		complejo(float r, float i)
		{
			pReal = r;
			pImag = i;
		}

		complejo operator+(const complejo & c2) const
		{
			complejo aux = complejo(pReal + c2.pReal, pImag + c2.pImag);

			return aux;
		}

		complejo operator*(const complejo & c2) const
		{
			complejo aux = complejo(pReal*c2.pReal - pImag*c2.pImag, pReal*c2.pImag + pImag*c2.pReal);

			return aux;
		}

		float module() const
		{
			float i = sqrt(pReal*pReal + pImag*pImag);

			return i;
		}

	private:
		
		float pReal, pImag;
};

//Complejidad O(n) con respecto al número de iteraciones. [Las operaciones tienen coste O(1)]
void resolver(const float & f1, const float & f2, const int & it)
{
	int contador = 0;
	complejo c = complejo(f1, f2);
	complejo r = complejo(0, 0);
	float mod = r.module();

	while (contador < it && mod <= LIMIT)
	{
		r = r*r;
		r = r+c;
		mod = r.module();
		contador++;
	}

	if (mod > LIMIT)
	{
		std::cout << "NO\n";
	}
	else
	{
		std::cout << "SI\n";
	}
}

int main()
{
	int nCasos, it;
	float v1, v2;

	std::cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
	{
		std::cin >> v1 >> v2 >> it;
		resolver(v1, v2, it);
	}
}