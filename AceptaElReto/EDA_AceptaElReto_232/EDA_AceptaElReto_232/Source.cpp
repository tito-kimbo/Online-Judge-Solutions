#include <iostream>

class Fecha
{
	int d, m, a;
	static const int DAYS[];

	public:
		Fecha() {}
		Fecha(bool trigger)
		{
			std::cin >> d >> m >> a;
		}
		
		bool isEmpty() { return d == 0 && m == 0 && a == 0; }
		int calculateTotal(const Fecha & f)
		{
			int total = 0, aux;

			if ( (d != f.getD()) || (m != f.getM()) )
			{
				//Primer año
				total += DAYS[m - 1] - d;
				for (int i = m; i < 12; i++)
				{
					total += DAYS[i];
				}
				//Años intermedios
				aux = f.getA() - a - 1;
				total += aux * 365;
				total -= aux;

				//Último año
				for (int i = 0; i < f.getM()-1; i++)
				{
					total += DAYS[i];
				}
				total += f.getD();

				if (m < f.getM() || (m == f.getM() && d <= f.getD())) { total--; }
			}

			

			return total;
		}

		int getD() const { return d; }
		int getM() const { return m; }
		int getA() const { return a; }


	private:
		

};

const int Fecha:: DAYS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//const int Fecha::DAYS[] = { 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30 };

int main()
{
	Fecha f1, f2;
	int r;

	f1 = Fecha(true);
	f2 = Fecha(true);
	while (!f1.isEmpty() && !f2.isEmpty())
	{
		r = f1.calculateTotal(f2);
		std::cout << r << '\n';

		f1 = Fecha(true);
		f2 = Fecha(true);
	}
}