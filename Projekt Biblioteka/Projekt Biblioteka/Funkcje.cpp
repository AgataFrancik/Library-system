#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Klasy.h"

using namespace std;


//Konstruktory:

Fantastyka::Fantastyka(string t, string a, int r, int i, bool w, string ro)
{
	tytul = t;
	autor = a;
	rokWyd = r;
	id = i;
	wolna = w;
	rodzaj = ro;
}

Popularnonaukowe::Popularnonaukowe(string t, string a, int r, int i, bool w, string k)
{
	tytul = t;
	autor = a;
	rokWyd = r;
	id = i;
	wolna = w;
	kategoria = k;
}

Ksiazka::Ksiazka(): autor("nieznany"), tytul("brak"), rokWyd(1000), id(00), wolna(0), nrKsiazki(1)
{}

Fantastyka::Fantastyka(): rodzaj("Fantasy")
{}

Popularnonaukowe::Popularnonaukowe(): kategoria("Historyczne")
{}
//Funkcje

//Zapis

void Fantastyka::zapisz()
{
	fstream plik;
	plik.open("Fantastyka.txt", ios::app);
	plik << this->tytul << endl;
	plik << this->autor << endl;
	plik << this->rokWyd << endl;
	plik << this->id << endl;
	plik << this->wolna << endl;
	plik << this->rodzaj << endl;
	plik.close();
}

void Popularnonaukowe::zapisz()
{
	fstream plik;
	plik.open("Popularnonaukowe.txt", ios::app);
	plik << this->tytul << endl;
	plik << this->autor << endl;
	plik << this->rokWyd << endl;
	plik << this->id << endl;
	plik << this->wolna << endl;
	plik << this->kategoria << endl;
	plik.close();
}

//Wczytywanie
// ALERT! SPROBUJ POTEM ZROBIC TAK ZEBY TO BYLO NA JEDNEJ FUNKCJI KTORA BEDZIE PRZYJMOWALA NAZWE PLIKU!
void Fantastyka::wczytaj()
{
	fstream plik;
	plik.open("Fantastyka.txt", ios::in);
	if (plik.good())
	{
		string linia;
		int nrLinii = (nrKsiazki - 1) * 6 + 1;
		int licznik = 1;
		while (getline(plik, linia))
		{
			if (licznik == nrLinii)
			{
				tytul = linia;
			}
			if (licznik == nrLinii + 1)
			{
				autor = linia;
			}
			if (licznik == nrLinii + 2)
			{
				stringstream geek(linia);
				geek >> rokWyd;
			}
			if (licznik == nrLinii + 3)
			{
				stringstream geek(linia);
				geek >> id;
			}
			if (licznik == nrLinii + 4)
			{
				istringstream(linia) >> wolna;
			}
			if (licznik == nrLinii + 5)
			{
				rodzaj = linia;
			}
			licznik++;
		}
	}
	else
	{
		cout << "Blad otwierania pliku!";
		exit(1);
	}
	plik.close();
}
void Popularnonaukowe::wczytaj()
{
	fstream plik;
	plik.open("Popularnonaukowe.txt", ios::in);
	if (plik.good())
	{
		string linia;
		int nrLinii = (nrKsiazki - 1) * 6 + 1;
		int licznik = 1;
		while (getline(plik, linia))
		{
			if (licznik == nrLinii)
			{
				tytul = linia;
			}
			if (licznik == nrLinii + 1)
			{
				autor = linia;
			}
			if (licznik == nrLinii + 2)
			{
				stringstream geek(linia);
				geek >> rokWyd;
			}
			if (licznik == nrLinii + 3)
			{
				stringstream geek(linia);
				geek >> id;
			}
			if (licznik == nrLinii + 4)
			{
				istringstream(linia) >> wolna;
			}
			if (licznik == nrLinii + 5)
			{
				kategoria = linia;
			}
			licznik++;
		}
	}
	else
	{
		throw logic_error("Blad otwierania pliku!");
		exit(1);
	}
	plik.close();
}

//Wyswietlanie

void Fantastyka::wypisz() const
{
	cout << tytul << ", " << autor << ", " << rokWyd << ", " << id << ", " << rodzaj;
	if (wolna)
	{
		cout << ", ksiazka jest dostepna."<< endl;
	}
	else
	{
		cout << ", Ksiazke ktos wypozyczyl" << endl;
	}
}

void Popularnonaukowe::wypisz() const
{
	cout << tytul << ", " << autor << ", " << rokWyd << ", " << id << ", " << kategoria;
	if (wolna)
	{
		cout << ", ksiazka jest dostepna." << endl;
	}
	else
	{
		cout << ", Ksiazke ktos wypozyczyl." << endl;
	}
}

//GetNr

int Fantastyka::getNr(int i)
{
	return nrKsiazki = i;
}
int Popularnonaukowe::getNr(int i)
{
	return nrKsiazki = i;
}

//Szukanie

bool Fantastyka::szukaj(string szukana)
{
	if (szukana == this->tytul || szukana == this->autor || szukana == this->rodzaj)
		return 1;
	else
		return 0;
}
bool Fantastyka::lszukaj(string szukana)
{
	int zmienna;
	if (zmienna = atoi(szukana.c_str()))
	{
		if (zmienna == this->id || zmienna == this->rokWyd)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
		return 0;
}
bool Popularnonaukowe::lszukaj(string szukana)
{
	int zmienna;
	if (zmienna = atoi(szukana.c_str()))
	{
		if (zmienna == this->id || zmienna == this->rokWyd)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
		return 0;
}

bool Popularnonaukowe::szukaj(string szukana)
{
	if (szukana == this->tytul || szukana == this->autor || szukana == this->kategoria)
		return 1;
	else
		return 0;
}

//Zmiana statusu ksiazki

void zmienP(int jak, int idSzuk)
{
	ifstream plik, plik1;
	int ilosc;
	string linia;
	string idSz = to_string(idSzuk);
	plik.open("Popularnonaukowe.txt");
	plik1.open("PopularnonaukoweIlosc.txt");
	plik1 >> ilosc;
	plik1.close();
	string* ktab = new string[ilosc * 6];
	for (int i = 0; i < ilosc * 6; i++)
		getline(plik, ktab[i]);
	/*for (int i = 0; i < ilosc*6; i++)
	{
		cout << ktab[i] << endl;
	}*/
	plik.close();
	ofstream plik2;
	plik2.open("Popularnonaukowe.txt");
	int i;
	for (i = 0; i < ilosc * 6; i++)
	{
		if (ktab[i] == idSz)
		{
			break;
		}
	}
	if (jak == 1)
	{
		if (ktab[i + 1] == "1")
			ktab[i + 1] = "0";
		else
		{
			cout << "Ta ksiazka juz jest wypozyczona!";
			//exit(1);
		}

	}
	else
	{
		if (ktab[i + 1] == "0")
			ktab[i + 1] = "1";
		else
		{
			cout << "Ta ksiazka juz jest dostepna. Moze pomylilas id?";
			//exit(1);
		}
	}
	for (int b = 0; b < ilosc * 6; b++)
	{
		plik2 << ktab[b] << endl;
	}
	cout << " Gotowe!";
	plik2.close();
	plik2.clear();
	delete[] ktab;
}

void zmienF(int jak, int idSzuk)
{
	ifstream plik, plik1;
	int ilosc;
	string linia;
	string idSz = to_string(idSzuk);
	plik.open("Fantastyka.txt");
	plik1.open("FantastykaIlosc.txt");
	plik1 >> ilosc;
	plik1.close();
	string* ktab = new string[ilosc * 6];
	for (int i = 0; i < ilosc * 6; i++)
		getline(plik, ktab[i]);
	/*for (int i = 0; i < ilosc*6; i++)
	{
		cout << ktab[i] << endl;
	}*/
	plik.close();
	ofstream plik2;
	plik2.open("Fantastyka.txt");
	int i;
	for (i = 0; i < ilosc * 6; i++)
	{
		if (ktab[i] == idSz)
		{
			break;
		}
	}
	if (jak == 1)
	{
		if (ktab[i + 1] == "1")
			ktab[i + 1] = "0";
		else
		{
			cout << "Ta ksiazka juz jest wypozyczona!";
			exit(1);
		}

	}
	else
	{
		if (ktab[i + 1] == "0")
			ktab[i + 1] = "1";
		else
		{
			cout << "Ta ksiazka juz jest dostepna. Moze pomylilas id?";
			exit(1);
		}
	}
	for (int b = 0; b < ilosc * 6; b++)
	{
		plik2 << ktab[b] << endl;
	}
	cout << " Gotowe!";
	plik2.close();
	plik2.clear();
	delete[] ktab;
}

