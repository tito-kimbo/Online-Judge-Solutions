//Eduardo Rivero Rodríguez
#include <iostream>
#include <algorithm>
#include <vector>

//IMPLEMENTACIÓN DE BACKTRACKING SIMILAR AL PROBLEMA DE LA MOCHILA

struct cancion
{
	int duracion;
	int puntuacion;
	float ratioValiosidad;
};

bool operator< (const cancion & c1, const cancion & c2)
{
	return c1.ratioValiosidad > c2.ratioValiosidad;
}

//Estima la puntuación para realizar una poda
int estimarPuntuacion(std::vector<cancion> & v, int & d, int & n, int duracionAcumulada, int puntuacionAcumulada, int indice)
{
	int estim = puntuacionAcumulada, dur = duracionAcumulada;

	while (indice < n && dur+v[indice].duracion <= 2*d)
	{
		dur += v[indice].duracion;
		estim += v[indice].puntuacion;
		indice++;
	}
	
	if (indice < n)
	{
		estim += (2*d - duracionAcumulada)*v[indice].ratioValiosidad;
	}

	return estim;
}

//Resolución del problema
void resolver(std::vector<cancion> & v, int & d, int & n, int objActual, int duracionAcumulada1, int duracionAcumulada2, int & cotaInferior1,
	int & cotaInferior2, int & valorAcumulado1, int & valorAcumulado2)
{
	int duracion, estimacion;

	//La canción a la primera cara
	duracion = duracionAcumulada1 + v[objActual].duracion;
	valorAcumulado1 += v[objActual].puntuacion;

	if (duracion <= d)
	{
		if (objActual == n - 1)
		{
			if (valorAcumulado1 + valorAcumulado2 > cotaInferior1 + cotaInferior2)
			{
				cotaInferior1 = valorAcumulado1;
				cotaInferior2 = valorAcumulado2;
			}
		}
		else //objActual < n
		{
			resolver(v, d, n, objActual + 1, duracion, duracionAcumulada2, cotaInferior1, cotaInferior2, valorAcumulado1, valorAcumulado2);
		}
	}
	valorAcumulado1 -= v[objActual].puntuacion;

	//La canción a la segunda cara
	duracion = duracionAcumulada2 + v[objActual].duracion;
	valorAcumulado2 += v[objActual].puntuacion;

	if (duracion <= d)
	{
		if (objActual == n - 1)
		{
			if (valorAcumulado1 + valorAcumulado2 > cotaInferior1 + cotaInferior2)
			{
				cotaInferior1 = valorAcumulado1;
				cotaInferior2 = valorAcumulado2;
			}
		}
		else
		{
			resolver(v, d, n, objActual + 1, duracionAcumulada1, duracion, cotaInferior1, cotaInferior2, valorAcumulado1, valorAcumulado2);
		}
	}
	valorAcumulado2 -= v[objActual].puntuacion;

	//No se escoge la canción
	estimacion = estimarPuntuacion(v, d, n, duracionAcumulada1+duracionAcumulada2, valorAcumulado1+valorAcumulado2, objActual+1);

	if (estimacion > cotaInferior1+cotaInferior2)
	{
		if (objActual == n-1)
		{
			if (valorAcumulado1 + valorAcumulado2 > cotaInferior1 + cotaInferior2)
			{
				cotaInferior1 = valorAcumulado1;
				cotaInferior2 = valorAcumulado2;
			}
		}
		else
		{
			resolver(v, d, n, objActual + 1, duracionAcumulada1, duracionAcumulada2, cotaInferior1, cotaInferior2, valorAcumulado1, valorAcumulado2);
		}
	}
}

void lecturaDatos(std::vector<cancion> & v, int & d, int n)
{
	cancion aux;
	float f;

	v.clear();

	std::cin >> d;
	for (int i = 0; i < n; i++)
	{
		std::cin >> aux.duracion >> aux.puntuacion;
		
		f = aux.puntuacion/(float)aux.duracion;
		aux.ratioValiosidad = f;

		v.push_back(aux);
	}
}

int main()
{
	int nCanciones, duracionCinta, solCara1, solCara2, dAcum1, dAcum2, vAcum1, vAcum2;
	std::vector<cancion> v;

	std::cin >> nCanciones;
	while (nCanciones != 0)
	{
		lecturaDatos(v, duracionCinta, nCanciones);
		std::sort(v.begin(), v.end());
		dAcum1 = 0;
		dAcum2 = 0;
		vAcum1 = 0;
		vAcum2 = 0;
		solCara1 = 0;
		solCara2 = 0;

		//RESOLUCION
		resolver(v, duracionCinta, nCanciones, 0, dAcum1, dAcum2, solCara1, solCara2, vAcum1, vAcum2);
		std::cout << solCara1 + solCara2 << '\n';

		std::cin >> nCanciones;
	}
}