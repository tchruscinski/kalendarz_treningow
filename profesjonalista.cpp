#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "profesjonalista.h"

using namespace std;

Profesjonalista::Profesjonalista(): Zawodnik("", 0, 0, ""), dyscyplina(""){}

Profesjonalista::Profesjonalista(string i, float wg, float wz, string c, string d): Zawodnik(i, wg, wz, c), dyscyplina(d){}

Profesjonalista::~Profesjonalista(){}

void Profesjonalista::dodajTrening(const Trening& t)
{
	treningi.push_back(t);
}

void Profesjonalista::usunTrening(const Trening& t)
{
	for(int i = 0; i < treningi.size(); i++)
	{
		if((treningi[i].nazwa == t.nazwa)&&(treningi[i].dzien_tygodnia == t.dzien_tygodnia)&&(treningi[i].godzina_rozpoczecia == t.godzina_rozpoczecia)&&(treningi[i].dlugosc == t.dlugosc)){
			treningi.erase(treningi.begin()+i);
		}
	}	
}

void Profesjonalista::zapisz()
{
	fstream plik;
	plik.open("profesjonalisci.txt", ios::out | ios::app);

	plik<<imie<<endl;
	plik<<waga<<endl;
	plik<<wzrost<<endl;
	plik<<cel<<endl;
	plik<<dyscyplina<<endl;
	plik<<treningi.size()<<endl; //zapisuje ilosc treningow zawodnika
	for(int i = 0; i < treningi.size(); i++)
	{
		plik<<treningi[i].nazwa<<endl<<treningi[i].dzien_tygodnia<<endl<<treningi[i].godzina_rozpoczecia<<endl<<treningi[i].dlugosc<<endl<<treningi[i].poziom_zaawansowany<<endl;
	}

	plik.close();
}

ostream & operator<<(ostream& os, const Profesjonalista& p)
{
	os<<p.imie<<":"<<endl;
	os<<"- waga: "<<p.waga<<"kg"<<endl;
	os<<"- wzrost: "<<p.wzrost<<"cm"<<endl;
	os<<"- cel: "<<p.cel<<endl;
	os<<"- dyscyplina: "<<p.dyscyplina<<endl;
	os<<"- uczestniczy w nastepujacych treningach: "<<endl;

	for(int i = 0; i < p.treningi.size(); i++)
	{
		os<<"  * "<<p.treningi[i];
	}

	return os;
}