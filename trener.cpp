#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "trener.h"

using namespace std;

Trener::Trener(): Osoba("", 0, 0), specjalnosc(""){}

Trener::Trener(string i, float wg, float wz, string s): Osoba(i, wg, wz), specjalnosc(s)
{
	vector <Trening> treningi;
}

Trener::~Trener(){}

void Trener::dodajTrening(const Trening& t)
{
	treningi.push_back(t);
}

void Trener::usunTrening(const Trening& t)
{
	for(int i = 0; i < treningi.size(); i++){
		if((treningi[i].nazwa == t.nazwa)&&(treningi[i].dzien_tygodnia == t.dzien_tygodnia)&&(treningi[i].godzina_rozpoczecia == t.godzina_rozpoczecia)&&(treningi[i].dlugosc == t.dlugosc)){
			treningi.erase(treningi.begin()+i);
		}
	}	
}

void Trener::zapisz()
{
	fstream plik;
	plik.open("trenerzy.txt", ios::out | ios::app);

	plik<<imie<<endl;
	plik<<waga<<endl;
	plik<<wzrost<<endl;
	plik<<specjalnosc<<endl;
	plik<<treningi.size()<<endl; //zapisuje ilosc treningow trenera
	for(int i = 0; i < treningi.size(); i++)
	{
		plik<<treningi[i].nazwa<<endl<<treningi[i].dzien_tygodnia<<endl<<treningi[i].godzina_rozpoczecia<<endl<<treningi[i].dlugosc<<endl<<treningi[i].poziom_zaawansowany<<endl;
	}

	plik.close();

}

ostream & operator<<(ostream& os, const Trener& t)
{
	os<<t.imie<<":"<<endl;
	os<<"- waga: "<<t.waga<<"kg"<<endl;
	os<<"- wzrost: "<<t.wzrost<<"cm"<<endl;
	os<<"- specjalnosc: "<<t.specjalnosc<<endl;
	os<<"- prowadzi nastepujace treningi: "<<endl;

	for(int i = 0; i < t.treningi.size(); i++)
	{
		os<<"  * "<<t.treningi[i];
	}

	return os;
}