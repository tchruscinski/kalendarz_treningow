#ifndef _TRENER_H_
#define _TRENER_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "osoba.h"

using namespace std;

class Trener: public Osoba
{
protected:
	string specjalnosc;
public:
	Trener();
	Trener(string i, float wg, float wz, string s);
	~Trener();
	virtual void dodajTrening(const Trening& t);
	virtual void usunTrening(const Trening& t);
	virtual void zapisz();

friend void interfejs();
friend void testPolimorfizmu();	
friend ostream & operator<<(ostream& os, const Trener& t);
friend class Kalendarz;
};
#endif