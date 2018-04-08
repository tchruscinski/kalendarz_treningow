#ifndef _ZAWODNIK_H_
#define _ZAWODNIK_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "osoba.h"


using namespace std;

class Zawodnik: public Osoba
{
protected:
	string cel;
public:
	Zawodnik();
	Zawodnik(string i, float wg, float wz, string c);
	~Zawodnik();
	virtual void dodajTrening(const Trening& t);
	virtual void usunTrening(const Trening& t);
	virtual void zapisz();	

friend void interfejs();
friend void testPolimorfizmu();
friend ostream & operator<<(ostream& os, const Zawodnik& z);
friend class Kalendarz;
};
#endif