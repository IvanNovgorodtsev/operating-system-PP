#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string>
#include <iostream>
#include <math.h>



class Tab_Fat {
public:
	std::string nazwa = "";						// nazwa
	bool status;					// status
	bool zapisany;					// Czy plik zapisany				
	int jap1;						// numer pierwszego jap
	int rozmiar;						// rozmiar pliku

};

class Disc {

public:



	static const  int FFFF = -1;
	int rozmiarDysku = 512; // rozmiar dysku
	char dysk[512];				//dysk
	int fat[64];					//tablica fat 64 bity
	Tab_Fat atrybuty[64];		//wpis do katlogu glownego
	int spacefree = rozmiarDysku;						//wlne miejsce`


	Disc();
	void wys();
	void tworzeniaPliku(std::string nazwa);
	void wpisywanieDoPliku(std::string nazwa, std::string data);
	int file_jap(std::string nazwa);
	int wolneMiejsceDysk();
	void usuwaniePliku(std::string nazwa);
	void wyswietlaPliki();
	void iloscWolnegoMiejsca();

	void drukujDysk(std::string nazwa);
	void www();
	void dopiszDoPliku(std::string nazwa, std::string data);
	int wolnyJap(int nr_jap);
	int ktory_katalog(std::string nazwa);
	int wolnyKatalog();
	bool nazwaIstnieje(std::string nazwa);
	int szukanieWolnegoJap();
	void zmianaNazwy(std::string nazwa, std::string newname);
};