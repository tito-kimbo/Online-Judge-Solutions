#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

//Similar a quicksort -> PIVOTE

bool comprobacion(std::vector<int> & v, int a, int medio, int b)
{
	bool always;
	int minA, midpoint, last;

	always = false;
	minA = a;
	midpoint = 0;
	last = b;

	while (minA < medio && last >= medio)
	{

	}

	return always;
}

//NOT DONE
bool ganaSiempre(std::vector<int> & v, int a, int b)
{
	int medio;
	bool siempre;

	medio = (a + b) / 2;
	siempre = true;

	if (b - a < 3)
	{}
	else
	{
		siempre = ganaSiempre(v, a, medio) && ganaSiempre(v, medio, b);
		siempre = siempre && comprobacion(v, a, medio, b);
	}

	return siempre;
}

void lecturaDatos(std::vector<int> & v, int n)
{
	int aux;

	v.clear();
	for (int i = 0; i < n; i++)
	{
		std::cin >> aux; 
		v.push_back(aux);
	}
}

bool resuelveCuadratico(std::vector<int> & v) {
	int currentMax, current;

	for (int i = 0; i < (int)v.size(); i++) {
		current = currentMax = v[i];
		for (int j = i+1; j < (int)v.size(); j++) {
			if (v[j] > currentMax) {
				currentMax = v[j];
			}
			else if (v[j] > current && v[j] < currentMax) {
				return false;
			}
		}
	}
	return true;
}

void comprueba(std::vector<int> & v) {
	if (resuelveCuadratico(v)) {
		std::cout << "GANA SIEMPRE\n";
	}
	else {
		std::cout << "ELEGIR OTRA\n";
	}
}

bool resuelveLineal(std::vector<int> & v) {
	std::stack<int> stack;
	bool okay = true, growing = true;
	int a, b, i; //Current interval / index
	int lastElement, aux;

	i = v.size()-2;
	lastElement = v[i + 1];
	stack.push(lastElement);
	a = b = 0;
	while (okay && i >= 0) {
		aux = v[i];

		if (a > aux && b > aux && a > b) {
			okay = false;
		}

		if(aux > lastElement){
			a = aux;
			while (!stack.empty() && aux > stack.top()) {
				if (stack.top() > b || b > a) {
					b = stack.top();
				}
				stack.pop();
			}
		}
		stack.push(aux);
		lastElement = aux;

		i--;
	}

	return okay;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	std::vector<int> v;

	
	
	std::cin >> n;
	while (std::cin)
	{
		lecturaDatos(v, n);

		//comprueba(v);
		//if (ganaSiempre(v, 0, v.size()))
		if(resuelveLineal(v))
		{
			std::cout << "SIEMPRE PREMIO\n";
		}
		else
		{
			std::cout << "ELEGIR OTRA\n";
		}

		std::cin >> n;
	}

	/*
	while (true) {
		std::cin >> n;
		if (n == -1) break;
		do {
			v.clear();
			for (int i = 0; i < n; i++) {
				v.push_back(rand() % (5*n) +1);
			}

		} while (resuelveCuadratico(v) == resuelveLineal(v));
		std::cout << resuelveCuadratico(v) << " != " << resuelveLineal(v) << '\n';
		std::cout << " - ";
		for (int i = 0; i < n; i++) {
			std::cout << v[i] << " - ";
		}
		std::cout << '\n';
	}*/
}