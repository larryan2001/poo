#ifndef FRACTIE_H_INCLUDED
#define FRACTIE_H_INCLUDED

class Fractie {
private:
	int numarator;
	int numitor;

public:

	Fractie(int, int);

	Fractie();

	Fractie(Fractie&);


	Fractie operator+(const Fractie&);



	Fractie operator-(const Fractie&);


	Fractie operator/(const Fractie&);


	Fractie operator*(const Fractie&);


	Fractie operator*(int);

	friend Fractie operator*(int, Fractie&);

	int getNumitor();


	int getNumarator();


	void setNumitor(int);


	void setNumarator(int);



	void afisare();

	void simplificareFormaIreductibila();


	void simplificare(int);


};

#endif // FRACTIE_H_INCLUDED