#include "polynomial.h"
#include "parser.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	parser p;
	string pol1 = "-2x^2y^5";
	string pol2 = "2x^2y^5+2";
	polynomial x1, x2;

	p.try_parse(pol1, x1);
	p.try_parse(pol2, x2);

    cout << "F(x, y, z) = " << x1.get_polinomial() << endl;
	cout << "G(x, y ,z) = " << x2.get_polinomial() << endl;
	cout << "F(x, y, z) + G(x, y, z) = " << (x1 + x2).get_polinomial() << endl;
	cout << "F(x, y, z) - G(x, y, z) = " << (x1 - x2).get_polinomial() << endl;
	cout << "F(x, y, z) * G(x, y, z) = " << (x1*x2).get_polinomial() << endl;
	return 0;
}