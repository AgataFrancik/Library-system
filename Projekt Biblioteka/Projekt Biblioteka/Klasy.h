#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Ksiazka
{
	protected:
	string autor;
	string tytul;
	int id;
	int rokWyd;
	bool wolna;
	int nrKsiazki; //zmienna do wczytywania
public:
	Ksiazka();
	virtual void zapisz() = 0;
	virtual void wczytaj() = 0;
	virtual void wypisz() const = 0;
};
class Fantastyka: public Ksiazka
{
public:
	string rodzaj;
	Fantastyka(string, string, int, int, bool, string);
	Fantastyka();
	virtual void zapisz();
	virtual void wczytaj();
	virtual void wypisz() const;
	int getNr(int i);
	bool szukaj(string);
	bool lszukaj(string);
	void zmien(int, int);
};
class Popularnonaukowe : public Ksiazka
{
public:
	string kategoria;
	Popularnonaukowe(string, string, int, int, bool, string);
	Popularnonaukowe();
	virtual void zapisz();
	virtual void wczytaj();
	virtual void wypisz() const;
	int getNr(int i);
	bool szukaj(string);
	bool lszukaj(string);
	void zmien(int,int);
};
class Osoba
{
protected:
	string imie;
	string nazwisko;
	int id;
	//bool zadluzony;
	int nrOsoby;
public:
	virtual void wczytaj() = 0;
	virtual void wypisz() const = 0;
	Osoba();
};
class Dluznik : public Osoba
{
public:
	virtual void wczytaj();
	virtual void wypisz() const;
	bool szukaj(int);
	int getNr(int i);
	Dluznik();
};
class Wolny : public Osoba
{
public:
	bool szukaj(int);
	virtual void wczytaj();
	virtual void wypisz() const;
	int getNr(int i);
	Wolny();
	//bool nowy; //Zmienna mówi czy dana osoba wczeœniej ju¿ coœ pozyczala, czy jeszcze nigdy
};

//Funckje:

void zmienP(int jak, int idSzuk);

void zmienF(int jak, int idSzuk);

void przepiszWD(int);

void przepiszDW(int);