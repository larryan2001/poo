#include <iostream>
#include "fractie.h"
using namespace std;

void rezolvareSistem(Fractie a, Fractie b, Fractie c, Fractie d, Fractie e, Fractie f) {
	Fractie x, y;
	x = ((f*b) - (e*c)) / ((d*b) - (e*a));
	y = (c - (a*x)) / b;
	x.afisare();
	cout << endl;
	y.afisare();
}
int main()
{
	Fractie a(1, 2), b(1, 2),c(1,1),d(1,4),e(3,4),f(1,3),g(6,12);

	rezolvareSistem(a, b, c, d, e, f);
	a = a + b;
	a.afisare();
	b = b*c; 
	b.afisare();
	c = c / d;
	c.afisare();
	d = d - e;
	d.afisare();
	g.simplificare(2);
	g.afisare();
	g.simplificareFormaIreductibila();
	g.afisare();
	

	getchar();


}