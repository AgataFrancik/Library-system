#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include "Klasy.h"

using namespace std;

// konstruktory

Osoba::Osoba() : nazwisko("X"), imie("Y"), id(0), nrOsoby(1)
{}

Dluznik::Dluznik()
{}

Wolny::Wolny()
{}
// Wczytywanie

void Wolny::wczytaj()
{
	fstream plik;
	plik.open("Wolny.txt", ios::in);
	if (plik.good())
	{
		string linia;
		int nrLinii = (nrOsoby - 1) * 3 + 1;
		int licznik = 1;
		while (getline(plik, linia))
		{
			if (licznik == nrLinii)
			{
				nazwisko = linia;
				
			}
			if (licznik == nrLinii + 1)
			{
				imie = linia;
				
			}
			if (licznik == nrLinii + 2)
			{
				
				stringstream geek(linia);
				geek >> id;
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

void Dluznik::wczytaj()
{
	fstream plik;
	plik.open("Dluznik.txt", ios::in);
	if (plik.good())
	{
		string linia;
		int nrLinii = (nrOsoby - 1) * 3 + 1;
		int licznik = 1;
		while (getline(plik, linia))
		{
			if (licznik == nrLinii)
			{
				nazwisko = linia;
			}
			if (licznik == nrLinii + 1)
			{
				imie = linia;
			}
			if (licznik == nrLinii + 2)
			{
				stringstream geek(linia);
				geek >> id;
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

//Wyswietlanie

void Wolny::wypisz() const
{
	cout << imie << " " << nazwisko << ", id: " << id << ". Ta osoba nie ma wypozyczonych ksiazek.";
	
}

void Dluznik::wypisz() const
{
	cout << imie << " " << nazwisko << ", id: " << id << ". Ta osoba wypozyczyla jakies ksiazki.";
}

//Wyszukiwanie

bool Wolny::szukaj(int szukana)
{
		if (szukana == this->id)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}

bool Dluznik::szukaj(int szukana)
{
	if (szukana == this->id)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Pobieranie numeru:

int Wolny::getNr(int i)
{
	return nrOsoby = i;
}

int Dluznik::getNr(int i)
{
	return nrOsoby = i;
}

//Funckje przepisuj¹ce

void przepiszWD(int idSzuk)
{
	list<string> listaW;
	list<string> listaD;
	ifstream plikW;
	fstream plikD;
	string linia;
	string imie, nazwisko;
	plikW.open("Wolny.txt");
	plikD.open("Dluznik.txt", ios::out | ios::app);
	int nrOsoby = 1;
	//int nrLinii;
	int i = 1, szuk;
	int licznik = 1;
	while (plikW>>nazwisko>>imie>>szuk)
	{
			if (szuk == idSzuk)
			{
				//id = to_string(szuk);
				listaD.push_back(nazwisko);
				listaD.push_back(imie);
				listaD.push_back(to_string(szuk));
			}
			else
			{
				//id = to_string(szuk);
				listaW.push_back(nazwisko);
				listaW.push_back(imie);
				listaW.push_back(to_string(szuk));
			}
			//}
			licznik++;
	}
		plikW.close();
		//Wpisywanie do plików
		ofstream plikW2;
		plikW2.open("Wolny.txt");
		string zmienna;
		for (list<string>::iterator it = listaW.begin(); it != listaW.end(); it++)
		{
			zmienna = *it;
			plikW2 <<endl << zmienna;
			plikW2.flush();
		}
		for (list<string>::iterator it = listaD.begin(); it != listaD.end(); it++)
		{
			zmienna = *it;
			plikD << zmienna<< endl;
			plikD.flush();
		}
		fstream plik1, plik2;
		int z1, z2;
		plik1.open("WolnyIlosc.txt", ios::out);
		plik1 >> z1;
		z1--;
		plik1 << z1;
		plik1.flush();
		plik1.close();
		plik2.open("DluznikIlosc.txt", ios::out);
		plik2 >> z2;
		z2++;
		plik2 << z2;
		plik2.flush();
		plik2.close();
		plikW2.close();
		plikD.close();
}
void przepiszDW(int idSzuk)
{
	list<string> listaW;
	list<string> listaD;
	fstream plikW;
	ifstream plikD;
	string linia;
	string imie, nazwisko;
	plikD.open("Dluznik.txt");
	plikW.open("Wolny.txt", ios::out | ios::app);
	int nrOsoby = 1;
	//int nrLinii;
	int i = 1, szuk;
	int licznik = 1;
	while (plikD >> nazwisko >> imie >> szuk)
	{
		if (szuk == idSzuk)
		{
			//id = to_string(szuk);
			listaW.push_back(nazwisko);
			listaW.push_back(imie);
			listaW.push_back(to_string(szuk));
		}
		else
		{
			//id = to_string(szuk);
			listaD.push_back(nazwisko);
			listaD.push_back(imie);
			listaD.push_back(to_string(szuk));
		}
		//}
		licznik++;
	}
	plikD.close();
	//Wpisywanie do plików
	ofstream plikD2;
	plikD2.open("Dluznik.txt");
	string zmienna;
	for (list<string>::iterator it = listaW.begin(); it != listaW.end(); it++)
	{
		zmienna = *it;
		plikW << zmienna << endl;
		plikW.flush();
	}
	for (list<string>::iterator it = listaD.begin(); it != listaD.end(); it++)
	{
		zmienna = *it;
		plikD2 << endl << zmienna;
		plikD2.flush();
	}
	fstream plik1, plik2;
	int z1, z2;
	plik1.open("WolnyIlosc.txt", ios::out);
	plik1 >> z1;
	z1++;
	plik1 << z1;
	plik1.flush();
	plik1.close();
	plik2.open("DluznikIlosc.txt", ios::out);
	plik2 >> z2;
	z2--;
	plik2 << z2;
	plik2.flush();
	plik2.close();
	plikW.close();
	plikD2.close();
}