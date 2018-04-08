#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "zawodnik.h"

using namespace std;

Zawodnik::Zawodnik(): Osoba("", 0, 0), cel(""){}

Zawodnik::Zawodnik(string i, float wg, float wz, string c): Osoba(i, wg, wz), cel(c)
{
	vector <Trening> treningi;
}

Zawodnik::~Zawodnik(){}

void Zawodnik::dodajTrening(const Trening& t)
{
	treningi.push_back(t);
}

void Zawodnik::usunTrening(const Trening& t)
{
	for(int i = 0; i < treningi.size(); i++){
		if((treningi[i].nazwa == t.nazwa)&&(treningi[i].dzien_tygodnia == t.dzien_tygodnia)&&(treningi[i].godzina_rozpoczecia == t.godzina_rozpoczecia)&&(treningi[i].dlugosc == t.dlugosc)){
			treningi.erase(treningi.begin()+i);
		}
	}	
}

void Zawodnik::zapisz()
{
	fstream plik;
	plik.open("zawodnicy.txt", ios::out | ios::app);

	plik<<imie<<endl;
	plik<<waga<<endl;
	plik<<wzrost<<endl;
	plik<<cel<<endl;
	plik<<treningi.size()<<endl; //zapisuje ilosc treningow zawodnika
	for(int i = 0; i < treningi.size(); i++)
	{
		plik<<treningi[i].nazwa<<endl<<treningi[i].dzien_tygodnia<<endl<<treningi[i].godzina_rozpoczecia<<endl<<treningi[i].dlugosc<<endl<<treningi[i].poziom_zaawansowany<<endl;
	}

	plik.close();

}

ostream & operator<<(ostream& os, const Zawodnik& z)
{
	os<<z.imie<<":"<<endl;
	os<<"- waga: "<<z.waga<<"kg"<<endl;
	os<<"- wzrost: "<<z.wzrost<<"cm"<<endl;
	os<<"- cel: "<<z.cel<<endl;
	os<<"- uczestniczy w nastepujacych treningach: "<<endl;

	for(int i = 0; i < z.treningi.size(); i++)
	{
		os<<"  * "<<z.treningi[i];
	}

	return os;
}