#ifndef _TRENING_H_
#define _TRENING_H_
#include <iostream>
#include <string>

using namespace std;

enum dzien {
	poniedzialek, wtorek, sroda, czwartek, piatek, sobota, niedziela
};

const string typyDni[] =
{
    "poniedzialek",
    "wtorek",
    "sroda",
    "czwartek",
    "piatek",
    "sobota",
    "niedziela"
};

class Trening
{	
protected:	
	string nazwa;
	float godzina_rozpoczecia;
	dzien dzien_tygodnia;
	float dlugosc;
	bool poziom_zaawansowany;
public:
	Trening();
	Trening(string n, dzien dz, float g, float d, bool pz);
	~Trening();

friend ostream & operator<<(ostream& os, const Trening& t);
friend void interfejs();
friend void testPolimorfizmu();
friend class Trener;
friend class Zawodnik;
friend class Osoba;
friend class Kalendarz;
friend class Profesjonalista;
};
#endif