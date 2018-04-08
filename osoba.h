#ifndef _OSOBA_H_
#define _OSOBA_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"

using namespace std;

class Osoba
{
protected:	
	string imie;
	float waga;
	float wzrost;
	vector <Trening> treningi;
public:
	Osoba();
	Osoba(string i, float wg, float wz);
	~Osoba();
	virtual void dodajTrening(const Trening& t) = 0;
	virtual void usunTrening(const Trening& t) = 0;
	virtual void zapisz() = 0;

friend void testPolimorfizmu();
//friend ostream & operator<<(ostream& os, const Osoba& o);
};
#endif
