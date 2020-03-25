#include "fractie.h"
#include <cmath>
#include <iostream>
using namespace std;
Fractie::Fractie(int numarator, int numitor)  {
	this->numarator = numarator;
	if (numitor != 0)
		this->numitor = numitor;
	else throw exception("Numitorul nu poate fi 0");
	}

Fractie::Fractie() {
	this->numarator = 1;
	this->numitor = 1;
}

Fractie::Fractie(Fractie& f) {
	this->numitor = f.numitor;
	this->numarator = f.numarator;
}

Fractie Fractie::operator+(const Fractie &f) {
	int a, b, cmmmc;
	a = abs(this->numitor);
	b = abs(f.numitor);
	while (a != b)
		if (a>b)
			a = a - b;
		else b = b - a;
	cmmmc = (this->numitor*f.numitor) / a;
	Fractie c((this->numarator*(cmmmc / this->numitor)) + (f.numarator*(cmmmc / f.numitor)), cmmmc);
	return c;

}

Fractie Fractie::operator-(const Fractie &f) {
	int a, b, cmmmc;
	a = abs(this->numitor);
	b = abs(f.numitor);
	while (a != b)
		if (a>b)
			a = a - b;
		else b = b - a;
		cmmmc = (this->numitor*f.numitor) / a;
		Fractie c((this->numarator*(cmmmc / this->numitor)) - (f.numarator*(cmmmc / f.numitor)), cmmmc);
		return c;
		}

Fractie Fractie::operator/(const Fractie &f) {
	if (f.numarator != 0) {
		Fractie c(this->numarator*f.numitor, this->numitor*f.numarator);
		return c;
		}
	else throw exception("Nu se poate face impartirea la 0");
}

Fractie Fractie::operator*(const Fractie &f) {
	Fractie c(this->numarator*f.numarator, this->numitor*f.numitor);
	return c;
}

Fractie Fractie::operator*(int f) {
	Fractie c(this->numarator*f, this->numitor);
	return c;
}

Fractie operator*(int i,  Fractie& f){
	Fractie c(f.numarator*i, f.numitor);
	return c;
	}

int Fractie::getNumarator() {
	return this->numarator;
}


int Fractie::getNumitor() {
	return this->numitor;
}

void Fractie::setNumarator(int numarator) {
	this->numarator = numarator;
}

void Fractie::setNumitor(int numitor) {
	if(numitor!=0)
		this->numitor = numitor;
	else throw exception("Numitorul nu poate fi setat 0");
}

void Fractie::afisare() {
	if (numitor == 0)
		cout << "Nu se poate";
	else if (numarator == 0)
		cout << 0 << endl;
	else if (numitor*numarator < 0) {
		if (abs(numitor*numarator) == abs(numarator))
			cout << -abs(numarator) << endl;  
		else
			cout << -abs(numarator) << "/" << abs(numitor) << endl;
	}
	else if (numitor*numarator > 0) {
		if (abs(numitor*numarator) == abs(numarator))
			cout << abs(numarator) << endl;
		else
			cout << abs(numarator) << "/" << abs(numitor) << endl;
	}
}

	void Fractie::simplificareFormaIreductibila() {
		int a, b;
		a = abs(numitor);
		b = abs(numarator);

		while (a != b)
			if (a>b)
				a = a - b;
			else b = b - a;

			if (a == 1)
				cout << "Fractia este deja ireductibila" << endl;
			else {
				numitor = numitor / a;
				numarator = numarator / a;
			}
	}

	void Fractie::simplificare(int a) {
		if (numitor%a == 0 && numarator%a == 0) {
			numitor = numitor / a;
			numarator = numarator / a;
		}
		else
			cout << "Fractia nu se poate simplifica prin " << a << endl;

	}