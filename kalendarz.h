#ifndef _KALENDARZ_H_
#define _KALENDARZ_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "osoba.h"
#include "trener.h"
#include "zawodnik.h"
#include "profesjonalista.h"

using namespace std;

class Kalendarz
{
protected:
	vector <Trener> trenerzy;
	vector <Zawodnik> zawodnicy;
	vector <Trening> treningi;
	vector <Profesjonalista> profesjonalisci;
public:
	Kalendarz();
	~Kalendarz();
	void wczytaj();

friend void interfejs();
friend void testPolimorfizmu();
friend class Trener;
friend class Zawodnik;
friend class Profesjonalista;
friend ostream & operator<<(ostream& os, const Kalendarz& k);
};
#endif