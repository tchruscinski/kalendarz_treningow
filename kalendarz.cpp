#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "trening.h"
#include "osoba.h"
#include "trener.h"
#include "zawodnik.h"
#include "kalendarz.h"
#include "profesjonalista.h"

using namespace std;

Kalendarz::Kalendarz()
{
	vector <Trener> trenerzy;
	vector <Zawodnik> zawodnicy;
	vector <Trening> treningi;
	vector <Profesjonalista> profesjonalisci;
}

Kalendarz::~Kalendarz(){}

void Kalendarz::wczytaj()
{
	//wczytujemy trenerow
	fstream plik;
	plik.open("trenerzy.txt", ios::in);

	if(plik.good() == false)
	{
		cout<<"Plik nie istnieje!"<<endl;
		exit(0);
	}

	string linia, im, sp, nazwa, cel, dysc;
	float wg = 0, wz = 0 , godzina_rozpoczecia = 0, dlugosc = 0;
	dzien dzien_tygodnia;
	bool poziom_zaawansowany; 
	int nr_linii = 1, wczytanych = 0, ile_treningow = 0, t = 1, dt = 0, iterator = 0;

	while(getline(plik, linia))
	{
		switch(nr_linii)
		{
			case 1:
					im = linia;
				break;
			case 2:
					wg = atoi(linia.c_str());
				break;
			case 3:
					wz = atoi(linia.c_str());
				break;
			case 4:
					sp = linia;
					trenerzy.push_back(Trener(im, wg, wz, sp));
				break;
			case 5:
					ile_treningow = atoi(linia.c_str());
				break;
			case 6:
					
					while(iterator < ile_treningow*5)
					{
						if(iterator != 0){
						getline(plik,linia);
						}
						switch(t)
						{
							case 1:
									nazwa = linia;
								break;
							case 2:
									dt = atoi(linia.c_str());
									dzien_tygodnia = (dzien)dt;
								break;
							case 3:
									godzina_rozpoczecia = atof(linia.c_str());
								break;
							case 4:
									dlugosc = atof(linia.c_str());
								break;
							case 5:
									poziom_zaawansowany = atoi(linia.c_str());
									trenerzy[wczytanych].treningi.push_back(Trening(nazwa, dzien_tygodnia, godzina_rozpoczecia, dlugosc, poziom_zaawansowany));
									t = 0;
								break;
						}
						t++;
						iterator++;
					}
					wczytanych++;
					nr_linii = 0;
					iterator = 0;
					t = 1;
				break;

		}
		nr_linii++;

	}
	plik.close();



	//wczytujemy zawodnikow
	plik.open("zawodnicy.txt", ios::in);

	if(plik.good() == false)
	{
		cout<<"Plik nie istnieje!"<<endl;
		exit(0);
	}

	nr_linii = 1;
	wczytanych = 0;
	ile_treningow = 0;
	t = 1;
	dt = 0;
	iterator = 0;

	while(getline(plik, linia))
	{
		switch(nr_linii)
		{
			case 1:
					im = linia;
				break;
			case 2:
					wg = atoi(linia.c_str());
				break;
			case 3:
					wz = atoi(linia.c_str());
				break;
			case 4:
					cel = linia;
					zawodnicy.push_back(Zawodnik(im, wg, wz, cel));
				break;
			case 5:
					ile_treningow = atoi(linia.c_str());
				break;
			case 6:
					while(iterator < ile_treningow*5)
					{
						if(iterator != 0){
						getline(plik,linia);
						}

						switch(t)
						{
							case 1:
									nazwa = linia;
								break;
							case 2:
									dt = atoi(linia.c_str());
									dzien_tygodnia = (dzien)dt;
								break;
							case 3:
									godzina_rozpoczecia = atof(linia.c_str());
								break;
							case 4:
									dlugosc = atof(linia.c_str());
								break;
							case 5:
									poziom_zaawansowany = atoi(linia.c_str());
									zawodnicy[wczytanych].treningi.push_back(Trening(nazwa, dzien_tygodnia, godzina_rozpoczecia, dlugosc, poziom_zaawansowany));
									t = 0;
								break;
						}
						t++;
						iterator++;
					}
					wczytanych++;
					nr_linii = 0;
					iterator = 0;
					t = 1;
				break;

		}
		nr_linii++;

	}
	plik.close();


	//wczytujemy profesjonalistow
	plik.open("profesjonalisci.txt", ios::in);

	if(plik.good() == false)
	{
		cout<<"Plik nie istnieje!"<<endl;
		exit(0);
	}

	nr_linii = 1;
	wczytanych = 0;
	ile_treningow = 0;
	t = 1;
	dt = 0;
	iterator = 0;

	while(getline(plik, linia))
	{
		switch(nr_linii)
		{
			case 1:
					im = linia;
				break;
			case 2:
					wg = atoi(linia.c_str());
				break;
			case 3:
					wz = atoi(linia.c_str());
				break;
			case 4:
					cel = linia;
				break;
			case 5:
					dysc = linia;
					profesjonalisci.push_back(Profesjonalista(im, wg, wz, cel, dysc));
				break;
			case 6:
					ile_treningow = atoi(linia.c_str());
				break;
			case 7:
					while(iterator < ile_treningow*5)
					{
						if(iterator != 0){
						getline(plik,linia);
						}

						switch(t)
						{
							case 1:
									nazwa = linia;
								break;
							case 2:
									dt = atoi(linia.c_str());
									dzien_tygodnia = (dzien)dt;
								break;
							case 3:
									godzina_rozpoczecia = atof(linia.c_str());
								break;
							case 4:
									dlugosc = atof(linia.c_str());
								break;
							case 5:
									poziom_zaawansowany = atoi(linia.c_str());
									profesjonalisci[wczytanych].treningi.push_back(Trening(nazwa, dzien_tygodnia, godzina_rozpoczecia, dlugosc, poziom_zaawansowany));
									t = 0;
								break;
						}
						t++;
						iterator++;
					}
					wczytanych++;
					nr_linii = 0;
					iterator = 0;
					t = 1;
				break;

		}
		nr_linii++;

	}
	plik.close();
}

ostream & operator<<(ostream& os, const Kalendarz& k)
{
	os<<"==================================================="<<endl;
	os<<"|| Kalendarz Trenerów ||"<<endl;
	for(int i = 0; i < k.trenerzy.size(); i++)
	{
		os<<k.trenerzy[i];
	}

	os<<endl<<"|| Kalendarz Amatorow ||"<<endl;
	for(int i = 0; i < k.zawodnicy.size(); i++)
	{
		os<<k.zawodnicy[i];
	}

	os<<endl<<"|| Kalendarz Profesjonalistow ||"<<endl;
	for(int i = 0; i < k.profesjonalisci.size(); i++)
	{
		os<<k.profesjonalisci[i];
	}

	return os;
}