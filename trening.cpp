#include <iostream>
#include <string>
#include "trening.h"

using namespace std;

Trening::Trening(): nazwa(""), dzien_tygodnia(poniedzialek), godzina_rozpoczecia(0), dlugosc(0), poziom_zaawansowany(0){}

Trening::Trening(string n, dzien dz, float g, float d, bool pz): nazwa(n), dzien_tygodnia(dz), godzina_rozpoczecia(g), dlugosc(d), poziom_zaawansowany(pz){} 

Trening::~Trening(){}

ostream & operator<<(ostream& os, const Trening& t)
{
	if(t.poziom_zaawansowany == true){
		os<<t.nazwa<<" w "<<typyDni[t.dzien_tygodnia]<<", zaczyna sie o "<<t.godzina_rozpoczecia<<", trwa "<<t.dlugosc<<" godziny - poziom zaawansowany"<<endl;
	}else
		{
		os<<t.nazwa<<" w "<<typyDni[t.dzien_tygodnia]<<", zaczyna sie o "<<t.godzina_rozpoczecia<<", trwa "<<t.dlugosc<<" godziny - poziom podstawowy"<<endl;
		}
	return os;
}