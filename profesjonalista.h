#ifndef _PROFESJONALISTA_H_
#define _PROFESJONALISTA_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "zawodnik.h"

using namespace std;

class Profesjonalista: public Zawodnik
{
protected:
	string dyscyplina;
public:
	Profesjonalista();
	Profesjonalista(string i, float wg, float wz, string c, string d);
	~Profesjonalista();
	virtual void dodajTrening(const Trening& t);
	virtual void usunTrening(const Trening& t);
	virtual void zapisz();	

friend void interfejs();
friend void testPolimorfizmu();
friend ostream & operator<<(ostream& os, const Profesjonalista& p);
friend class Kalendarz;
};
#endif