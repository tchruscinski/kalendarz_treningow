#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <unistd.h>
#include "trening.h"
#include "osoba.h"
#include "trener.h"
#include "zawodnik.h"
#include "profesjonalista.h"
#include "kalendarz.h"
#include "wyjatek.h"

using namespace std;

void interfejs();

void testPolimorfizmu();

int main()
{
	try{
	interfejs();
	
	}catch(blankField& b)
 	{
  		cerr<<b.what()<<endl;
  	}
 	catch(exception& e)
  	{
    	cout<<"Wystapil wyjatek:  "<<e.what()<<endl;
    }


   	//testPolimorfizmu();

	return 0;
}

void interfejs()
{
	Kalendarz k;
	int w, w2, w3, dzientyg, poziom, ktory;
	dzien dzienp;
	float godzina, dlugosc, waga, wzrost;
	string imie, nazwa, specjalnosc, cel, dyscyplina;

	cout<<"============================"<<endl;
	cout<<"  KALENDARZ TRENINGOW v2.0 |          ~Tomasz Chruscinski"<<endl;
	cout<<"============================"<<endl;

	cout<<"Czy chcesz wczytac poprzedni stan programu?"<<endl;
	cout<<"1) TAK                2) NIE"<<endl;
	cin.clear();
	cin.sync();
	

	//Tu jest przedyskutowany kawalek kodu, ktory zaleznie od systemu działa poprawnie
	while(!(cin>>w))
	{
  	cout<<"Wybierz poprawna opcje!"<<endl;
  	cin.clear();
  	cin.sync();
	}
	
	if(w == 1)
	{ 
		k.wczytaj();
	}

 	while(w != 11)
 	{

 		cout<<endl<<"[1] Dodaj Trenera"<<endl;
 		cout<<"[2] Dodaj Amatora"<<endl;
 		cout<<"[3] Dodaj Profesjonaliste"<<endl;
 		cout<<"[4] Dodaj Trening"<<endl;
 		cout<<"[5] Usun Trening"<<endl;
 		cout<<"[6] Wyswietl Caly Kalendarz Treningow"<<endl;
 		cout<<"[7] Wyswietl Kalendarz Trenerow"<<endl;
 		cout<<"[8] Wyswietl Kalendarz Amatorow"<<endl;
 		cout<<"[9] Wyswietl Kalendarz Profesjonalistow"<<endl;
 		cout<<"[10] Zapisz"<<endl;
 		cout<<"[11] Wyjdz"<<endl;

 		while(!(cin>>w))
		{
	  	cout<<"Wybierz poprawna opcje!"<<endl;
	  	cin.clear();
	  	cin.sync();
		}
 		

 	 		 switch(w)
 		 {
 		case 1:
 			 		cout<<"Podaj imie Trenera: ";
 			 		cin.ignore();
 			 		getline(cin, imie);
 			 		cin.clear();
 					cin.sync();
 			 		cout<<"Podaj wage Trenera: ";
 			 		cin>>waga;
 			 		cin.clear();
 					cin.sync();
 			 		cout<<"Podaj wzrost Trenera: ";
 			 		cin>>wzrost;
 			 		cin.clear();
 					cin.sync();
 			 		cout<<"Podaj specjalnosc Trenera: ";
 			 		cin.ignore();
 			 		getline(cin, specjalnosc);
		 			cin.clear();
					cin.sync();
		 			cout<<endl;
		 			
		 			if(imie.empty() || specjalnosc.empty()) 
		 				throw blankField();

		 			k.trenerzy.push_back(Trener(imie, waga, wzrost, specjalnosc));
		 	break;
		case 2:
				cout<<"Podaj imie Amatora: ";
		 		cin.ignore();
		 		getline(cin, imie);
		 		cin.clear();
				cin.sync();
		 		cout<<"Podaj wage Amatora: ";
		 		cin>>waga;
		 		cin.clear();
				cin.sync();
		 		cout<<"Podaj wzrost Amatora: ";
 		 		cin>>wzrost;
 		 		cin.clear();
 				cin.sync();
 		 		cout<<"Podaj cel Amatora: ";
 		 		cin.ignore();
 		 		getline(cin, cel);
 		 		cin.clear();
 				cin.sync();
 		 		cout<<endl;

 		 		if(imie.empty() || cel.empty()) 
		 			throw blankField();

 			 	k.zawodnicy.push_back(Zawodnik(imie, waga, wzrost, cel));
 			break;
 		case 3:
 			 		cout<<"Podaj imie Profesjonalisty: ";
 			 		cin.ignore();
 			 		getline(cin, imie);
 			 		cin.clear();
 					cin.sync();
 			 		cout<<"Podaj wage Profesjonalisty: ";
 			 		cin>>waga;
 			 		cin.clear();
 					cin.sync();
 			 		cout<<"Podaj wzrost Profesjonalisty: ";
 			 		cin>>wzrost;
			 		cin.clear();
					cin.sync();
			 		cout<<"Podaj cel Profesjonalisty: ";
 			 		cin.ignore();
 			 		getline(cin, cel);
 			 		cin.clear();
 					cin.sync();
 			 		cout<<"Podaj dyscypline w jakiej startuje Profesjonalista: ";
 			 		cin.ignore();
		 			getline(cin, dyscyplina);
 			 		cin.clear();
 					cin.sync();
 			 		cout<<endl;

 			 		if(imie.empty() || dyscyplina.empty() || cel.empty()) 
		 				throw blankField();

			 		k.profesjonalisci.push_back(Profesjonalista(imie, waga, wzrost, cel, dyscyplina));
			break;
		case 4:
			 		cout<<"Komu chcesz dodac trening?"<<endl;
			 		cout<<"1) Trenerowi"<<endl;
			 		cout<<"2) Amatorowi"<<endl;
			 		cout<<"3) Profesjonaliscie"<<endl;

					while(!(cin>>w2))
					{
					  	cout<<"Wybierz poprawna opcje!"<<endl;
					  	cin.clear();
					  	cin.sync();
					}

			 		switch(w2)
			 		{
			 			case 1:
			 					for(int i = 0; i < k.trenerzy.size(); i++)
			 					{
			 						cout<<i+1<<") "<<k.trenerzy[i].imie<<endl;
			 					}

			 					cout<<"Ktoremu Trenerowi chcesz dodac trening?";
			 					while(!(cin>>ktory))
								{
								  	cout<<"Wybierz poprawna opcje!"<<endl;
								  	cin.clear();
								  	cin.sync();
								}
			 					cout<<"Podaj nazwe treningu: ";
			 					cin.ignore();
			 					getline(cin, nazwa);
			 			 		cin.clear();
								cin.sync();
			 					cout<<endl;
			 					cout<<"Jakiego dnia odbywa sie trening ( 1 - poniedzialek, 2 - wtorek, ..., 7 - niedziela ) ";
			 					cin>>dzientyg;
			 			 		cin.clear();
								cin.sync();
			 					dzienp = (dzien)dzientyg;
			 					cout<<"Podaj godzine rozpoczecia treningu: ";
			 					cin>>godzina;
			 			 		cin.clear();
								cin.sync();
			 					cout<<endl;
			 					cout<<"Podaj dlugosc treningu: ";
			 					cin>>dlugosc;
			 			 		cin.clear();
								cin.sync();
			 					cout<<"Czy trening jest dla zaawansowanych ( 1 - TAK, 0 - NIE )";
			 					cin>>poziom;
			 			 		cin.clear();
								cin.sync();

								if(nazwa.empty()) 
		 							throw blankField();

								k.trenerzy[ktory-1].treningi.push_back(Trening(nazwa, dzienp, godzina, dlugosc, poziom));
								cout<<"Zapisano trening."<<endl;

			 				break;
			 			case 2:
			 					for(int i = 0; i < k.zawodnicy.size(); i++)
			 					{
			 						cout<<i+1<<") "<<k.zawodnicy[i].imie<<endl;
			 					}

			 					cout<<"Ktoremu Amatorowi chcesz dodac trening?";
								while(!(cin>>ktory))
								{
								  	cout<<"Wybierz poprawna opcje!"<<endl;
								  	cin.clear();
								  	cin.sync();
								}
			 					cout<<endl;

			 					cout<<"Podaj nazwe treningu: ";
			 					cin.ignore();
			 					getline(cin, nazwa);
			 			 		cin.clear();
								cin.sync();
			 					cout<<"Jakiego dnia odbywa sie trening ( 1 - poniedzialek, 2 - wtorek, ..., 7 - niedziela ) ";
			 					cin>>dzientyg;
			 			 		cin.clear();
								cin.sync();
			 					dzienp = (dzien)dzientyg;
			 					cout<<"Podaj godzine rozpoczecia treningu: ";
			 					cin>>godzina;
			 			 		cin.clear();
								cin.sync();
			 					cout<<endl;
			 					cout<<"Podaj dlugosc treningu: ";
			 					cin>>dlugosc;
			 			 		cin.clear();
								cin.sync();
			 					cout<<"Czy trening jest dla zaawansowanych ( 1 - TAK, 0 - NIE )";
			 					cin>>poziom;
			 			 		cin.clear();
								cin.sync();

								if(nazwa.empty()) 
		 							throw blankField();

								k.zawodnicy[ktory-1].treningi.push_back(Trening(nazwa, dzienp, godzina, dlugosc, poziom));
								cout<<"Zapisano trening."<<endl;
			 				break;
			 			case 3:
			 					for(int i = 0; i < k.profesjonalisci.size(); i++)
			 					{
			 						cout<<i+1<<") "<<k.profesjonalisci[i].imie<<endl;
			 					}

			 					cout<<"Ktoremu Profesjonaliscie chcesz dodac trening?";
								while(!(cin>>ktory))
								{
								  	cout<<"Wybierz poprawna opcje!"<<endl;
								  	cin.clear();
								  	cin.sync();
								}
			 					cout<<endl;

			 					cout<<"Podaj nazwe treningu: ";
			 					cin.ignore();
			 					getline(cin, nazwa);
			 			 		cin.clear();
								cin.sync();
			 					cout<<endl;
			 					cout<<"Jakiego dnia odbywa sie trening ( 1 - poniedzialek, 2 - wtorek, ..., 7 - niedziela ) ";
			 					cin>>dzientyg;
			 			 		cin.clear();
								cin.sync();
			 					dzienp = (dzien)dzientyg;
			 					cout<<"Podaj godzine rozpoczecia treningu: ";
			 					cin>>godzina;
			 			 		cin.clear();
								cin.sync();
			 					cout<<endl;
			 					cout<<"Podaj dlugosc treningu: ";
			 					cin>>dlugosc;
			 			 		cin.clear();
								cin.sync();
			 					cout<<"Czy trening jest dla zaawansowanych ( 1 - TAK, 0 - NIE )";
			 					cin>>poziom;
			 			 		cin.clear();
								cin.sync();

								if(nazwa.empty()) 
		 							throw blankField();

								k.profesjonalisci[ktory-1].treningi.push_back(Trening(nazwa, dzienp, godzina, dlugosc, poziom));
								cout<<"Zapisano trening."<<endl;
			 				break;
			 		}
			break;
		case 5:
			 			cout<<"Komu chcesz usunac trening?"<<endl;
			 			cout<<"1) Trenerowi"<<endl;
			 			cout<<"2) Amatorowi"<<endl;
			 			cout<<"3) Profesjonaliscie"<<endl;

						while(!(cin>>w2))
						{
						  	cout<<"Wybierz poprawna opcje!"<<endl;
						  	cin.clear();
						  	cin.sync();
						}
						cout<<endl;
						switch(w2)
						{
							case 1:
									for(int i = 0 ; i < k.trenerzy.size(); i++)
									{
										cout<<i+1<<") "<<k.trenerzy[i].imie<<endl;
									}
									
									cout<<"Ktoremu Trenerowi chcesz usunac trening?";
									while(!(cin>>w3))
									{
									  	cout<<"Wybierz poprawna opcje!"<<endl;
									  	cin.clear();
									  	cin.sync();
									}
				 					cout<<endl;

				 					cout<<"Treningi: "<<endl;
				 					for(int i = 0 ; i < k.trenerzy[w3-1].treningi.size(); i++)
									{
										cout<<i+1<<") "<<k.trenerzy[w3-1].treningi[i]<<endl;
									}
									
									cout<<"Ktory trening chcesz usunac?"<<endl;
									while(!(cin>>ktory))
									{
									  	cout<<"Wybierz poprawna opcje!"<<endl;
									  	cin.clear();
									  	cin.sync();
									}

									k.trenerzy[w3-1].usunTrening(k.trenerzy[w3-1].treningi[ktory-1]);
									cout<<"Trening usuniety."<<endl;
								break;
							case 2:
									for(int i = 0 ; i < k.zawodnicy.size(); i++)
									{
										cout<<i+1<<") "<<k.zawodnicy[i].imie<<endl;
									}
									
									cout<<"Ktoremu Amatorowi chcesz usunac trening?";
				 					while(!(cin>>w3))
									{
									  	cout<<"Wybierz poprawna opcje!"<<endl;
									  	cin.clear();
									  	cin.sync();
									}
				 					cout<<endl;

				 					cout<<"Treningi: "<<endl;
				 					for(int i = 0 ; i < k.zawodnicy[w3-1].treningi.size(); i++)
									{
										cout<<i+1<<") "<<k.zawodnicy[w3-1].treningi[i]<<endl;
									}
									
									cout<<"Ktory trening chcesz usunac?"<<endl;
									while(!(cin>>ktory))
									{
									  	cout<<"Wybierz poprawna opcje!"<<endl;
									  	cin.clear();
									  	cin.sync();
									}

									k.zawodnicy[w3-1].usunTrening(k.zawodnicy[w3-1].treningi[ktory-1]);
									cout<<"Trening usuniety."<<endl;
								break;
							case 3:
									for(int i = 0 ; i < k.profesjonalisci.size(); i++)
									{
										cout<<i+1<<") "<<k.profesjonalisci[i].imie<<endl;
									}
									
									cout<<"Ktoremu Profesjonaliscie chcesz usunac trening?";
				 					while(!(cin>>w3))
									{
									  	cout<<"Wybierz poprawna opcje!"<<endl;
									  	cin.clear();
									  	cin.sync();
									}
				 					cout<<endl;

				 					cout<<"Treningi: "<<endl;
				 					for(int i = 0 ; i < k.profesjonalisci[w3-1].treningi.size(); i++)
									{
										cout<<i+1<<") "<<k.profesjonalisci[w3-1].treningi[i]<<endl;
									}
									
									cout<<"Ktory trening chcesz usunac?"<<endl;
									while(!(cin>>ktory))
									{
									  	cout<<"Wybierz poprawna opcje!"<<endl;
									  	cin.clear();
									  	cin.sync();
									}

									k.profesjonalisci[w3-1].usunTrening(k.profesjonalisci[w3-1].treningi[ktory-1]);
									cout<<"Trening usuniety."<<endl;
								break;

						}
			break;
		case 6:
				cout<<k;
			break;
		case 7:
				cout<<"|| Kalendarz Trenerow ||"<<endl;
				for(int i = 0; i < k.trenerzy.size(); i++)
				{
					cout<<k.trenerzy[i];
				}
			break;
		case 8:
				cout<<"|| Kalendarz Amatorow ||"<<endl;
				for(int i = 0; i < k.zawodnicy.size(); i++)
				{
					cout<<k.zawodnicy[i];
				}
			break;
		case 9:
				cout<<"|| Kalendarz Profesjonalistow ||"<<endl;
				for(int i = 0; i < k.profesjonalisci.size(); i++)
				{
					cout<<k.profesjonalisci[i];
				}
			break;
		case 10:
				for(int i = 0; i < k.trenerzy.size(); i++)
				{
					k.trenerzy[i].zapisz();
				}
				for(int i = 0; i < k.zawodnicy.size(); i++)
				{
					k.zawodnicy[i].zapisz();
				}
				for(int i = 0; i < k.profesjonalisci.size(); i++)
				{
					k.profesjonalisci[i].zapisz();
				}
				cout<<"Zapisano."<<endl;
			break;
		 }
		//WSTRZYMUJE PROGRAM NA OKRESLONA LICZBE MIKROSEKUND
		usleep(1000000);
	}

}

void testPolimorfizmu()
{
	Osoba *grupa[3];
	Zawodnik a("Amator", 80, 180, "masa");
	Profesjonalista p("Profesjonalista", 85, 180, "mistrzostwo Polski", "wioslarstwo");
	Trener t("Nawalka", 185, 78, "pilka nozna");

	Trening silka("Silownia", (dzien)2, 18.5, 2, 0);

	grupa[0] = &a;
	grupa[1] = &p;
	grupa[2] = &t;

	for(int i = 0; i < 3; i++)
    {
        grupa[i] -> dodajTrening(silka);
    }

    // ZA WYPISYWANIE ODPOWIADA OPERATOR << A NIE METODA, WIEC WYSWIETLĘ W TEN SPOSOB, ZEBY POKAZAC, ZE ODPOWIEDNIE WCZESNIEJ UZYTE METODY ZADZIAŁAŁY
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<t<<endl;

    cout<<"==============="<<endl;

	for(int i = 0; i < 3; i++)
    {
        grupa[i] -> usunTrening(silka);
    }

    cout<<a<<endl;
    cout<<p<<endl;
    cout<<t<<endl;

}