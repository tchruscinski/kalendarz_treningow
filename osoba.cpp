#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trening.h"
#include "osoba.h"

using namespace std;

Osoba::Osoba():  imie(""), waga(0), wzrost(0) {}

Osoba::Osoba(string i, float wg, float wz):  imie(i), waga(wg), wzrost(wz) {}

Osoba::~Osoba(){}

// ostream & operator<<(ostream& os, const Osoba& o)
// {
// 	os<<o.imie<<":"<<endl;
// 	os<<"- waga: "<<o.waga<<"kg"<<endl;
// 	os<<"- wzrost: "<<o.wzrost<<"cm"<<endl;
// 	os<<"- treningi: "<<endl;

// 	for(int i = 0; i < o.treningi.size(); i++)
// 	{
// 		os<<"  * "<<o.treningi[i];
// 	}

// 	return os;
// }