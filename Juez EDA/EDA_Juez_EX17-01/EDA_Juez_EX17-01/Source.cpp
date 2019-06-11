//Eduardo Rivero Rodríguez
#include <iostream>
#include <vector>

/*
ESPECIFICACIÓN
Supondremos un vector de tamaño n. Primero definimos dos predicados auxiliares:

esCrecP(v,n,d) = \forall i : (#j : (1<=j<=n y v[j]=i) : j) <= d
esDDivert(v,n,d) =  \forall i,j : 0<=i<=j<=n y j=i+1 : 0<=(v[j]-v[i])<= d

{v != null y n,d >= 1}
def esCrecPYDDiv(v:vector de ent, n,d: ent) dev b:bool
{b = i=n y esCrecP(v,i,d) y esDDivert(v,i,d)}

INVARIANTE: (0<=i<=d y esCrecP(v,i,d) y esDDivert(v,i,d))
COTA: n-i
*/

bool esCrecPYDDiv(std::vector<int> & v, int n, int d)
{
	bool esCrecP, esDDiv;
	int i = 0, aux, count;

	esCrecP = true;
	esDDiv = true;
	count = 1;

	while (i < n-1)
	{
		if (esCrecP)
		{
			aux = v[i + 1] - v[i];
			esCrecP = (0 <= aux) && (aux <= 1);
		}

		if (esDDiv)
		{
			if (v[i + 1] == v[i])
			{
				count++;
				esDDiv = count <= d;
			}
			else
			{
				count = 1;
			}
		}

		i++;
	}

	return esCrecP && esDDiv;
}

int main()
{
	bool resp;
	int nCasos, d, n, aux;
	std::vector<int> v;

	std::cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
	{
		std::cin >> d >> n;

		v.clear();
		for (int j = 0; j < n; j++)
		{
			std::cin >> aux;
			v.push_back(aux);
		}

		resp = esCrecPYDDiv(v, n, d);

		if (resp)
		{
			std::cout << "SI\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}
}