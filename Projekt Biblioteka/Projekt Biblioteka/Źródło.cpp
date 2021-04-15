#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
//#include <vld.h>
#include <regex>
#include "Klasy.h"
using namespace std;



int main()
{
	Ksiazka* wskaznik;
	cout << " Witamy w systemia bibliotecznym" << endl;
	cout << "Co chcesz zrobic?" << endl;
	cout << "=============================================" << endl;
	cout << "1. Wyszukac ksiazke" << endl;
	cout << "2. Wypozyczyc ksiazke" << endl;
	cout << "3. Oddac ksiazke" << endl;
	cout << "4. Wyszukac czytelnika" << endl;
	cout << "5. Wprowadzic ksiazke do systemu" << endl;
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		int wybor2;
		cout << "Jak chcesz szukac ksiazki?" << endl;
		cout << "1. Po parametrze" << endl;
		cout << "2. Po rodzaju" << endl;
		cout << "3. Wyswietl wszystkie dostepne" << endl;
		cin >> wybor2;
		switch (wybor2)
		{
		case 1:
		{
			string parametr;
			cout << "Podaj parametr" << endl;
			cin.ignore();
			getline(cin, parametr);
			// Dla fantastyki
			fstream plik;
			int ilosc;
			try
			{
				plik.open("FantastykaIlosc.txt", ios::in);
				if (!plik.good())
				{
					throw "Nie udalo sie otworzyc pliku!";
				}
			}
			catch (const char* msg)
			{
				cout << msg;
			}
			plik >> ilosc;
			Fantastyka* ktab = new Fantastyka[ilosc];
			int l = 1;
			for (int i = 0; i < ilosc; i++)
			{
				try {
					ktab[i].wczytaj();
				}
				catch(logic_error &logic)
				{
					cout << logic.what();
				}
				if (ktab[i].szukaj(parametr))
				{
					cout << "Ksiazka nr: " << l << endl;
					l++;
					wskaznik = &ktab[i];
					wskaznik->wypisz();
				}
				if (ktab[i].lszukaj(parametr))
				{
					cout << "Ksiazka nr: " << l << endl;
					l++;
					wskaznik = &ktab[i];
					wskaznik->wypisz();
				}

				ktab[i + 1].getNr(i + 2);
			}
			delete[] ktab;

			//Dla popularnonaukowych

			fstream plik1;
			int ilosc1;
			plik1.open("PopularnonaukoweIlosc.txt", ios::in);
			plik1 >> ilosc1;
			Popularnonaukowe* ptab = new Popularnonaukowe[ilosc1];
			int l1 = 1;
			for (int i = 0; i < ilosc1; i++)
			{
				ptab[i].wczytaj();
				if (ptab[i].szukaj(parametr))
				{
					cout << "Ksiazka nr: " << l1 << endl;
					l1++;
					wskaznik = &ptab[i];
					wskaznik->wypisz();
				}
				if (ptab[i].lszukaj(parametr))
				{
					cout << "Ksiazka nr: " << l << endl;
					l++;
					wskaznik = &ptab[i];
					wskaznik->wypisz();
				}
				ptab[i + 1].getNr(i + 2);
			}
			delete[] ptab;
			plik.close();
			plik1.close();
			break;
		}
		case 2:
		{
			int wybor3;
			cout << "Jaki ma byc rodzaj?" << endl;
			cout << "1. Fantastyka" << endl;
			cout << "2.Popularnonaukowa" << endl;
			cin >> wybor3;
			switch (wybor3)
			{
			case 1:
			{
				int ilosc;
				cout << "FANTASTYKA:" << endl;
				fstream plik;
				plik.open("FantastykaIlosc.txt", ios::in);
				if (plik.good())
				{
					plik >> ilosc;
					Fantastyka* ktab = new Fantastyka[ilosc];
					for (int i = 0; i < ilosc; i++)
					{
						ktab[i].wczytaj();
						cout << "Ksiazka nr " << i + 1 << endl;
						ktab[i].wypisz();
						ktab[i + 1].getNr(i + 2);
					}
					delete[] ktab;
					plik.close();
				}
				break;
			}
			case 2:
			{
				int ilosc1;
				cout << "POPULARNONAUKOWE:" << endl;
				fstream plik2;
				plik2.open("PopularnonaukoweIlosc.txt", ios::in);
				if (plik2.good())
				{
					plik2 >> ilosc1;
					Popularnonaukowe* ktab = new Popularnonaukowe[ilosc1];
					for (int i = 0; i < ilosc1; i++)
					{
						ktab[i].wczytaj();
						cout << "Ksiazka nr " << i + 1 << endl;
						ktab[i].wypisz();
						ktab[i + 1].getNr(i + 2);
					}
					delete[] ktab;
					plik2.close();
					break;
				}
			}
			break;
			}
		case 3:
		{
			cout << "Lista ksiazek: " << endl;
			int ilosc, ilosc1;
			cout << "FANTASTYKA:" << endl;
			fstream plik;
			plik.open("FantastykaIlosc.txt", ios::in);
			if (plik.good())
			{
				plik >> ilosc;
				Fantastyka* ktab = new Fantastyka[ilosc];
				for (int i = 0; i < ilosc; i++)
				{
					ktab[i].wczytaj();
					cout << "Ksiazka nr " << i + 1 << endl;
					ktab[i].wypisz();
					ktab[i + 1].getNr(i + 2);
				}
				delete[] ktab;
				plik.close();
			}
			cout << "POPULARNONAUKOWE:" << endl;
			fstream plik2;
			plik2.open("PopularnonaukoweIlosc.txt", ios::in);
			if (plik2.good())
			{
				plik2 >> ilosc1;
				Popularnonaukowe* ktab = new Popularnonaukowe[ilosc1];
				for (int i = 0; i < ilosc1; i++)
				{
					ktab[i].wczytaj();
					cout << "Ksiazka nr " << i + 1 << endl;
					ktab[i].wypisz();
					ktab[i + 1].getNr(i + 2);
				}
				delete[] ktab;
				plik2.close();
				break;
			}
			break;
			/*default:
			{
				cout << "Nie ma opcji o takim numerze";
				break;
			}*/
			break;
		}
		break;
		}
		break;
		}
		break;
	case 2:
	{
		int idOs;
		int idSzuk;
		int co;
		cout << "Jaka ksiazke chcesz wypozyczyc? 1. Fantastyka 2.Popularnonaukowe" << endl;
		cin >> co;
		cout << "Podaj id ksiazki." << endl;
		cin >> idSzuk;
		cout << "Podaj id osoby wypozyczajacej." << endl;
		cin>>idOs;
		if (co == 2)
		{
			zmienP(1, idSzuk);
		}
		else
			zmienF(1, idSzuk);
		przepiszWD(idOs);
		break;
	}
	case 3:
	{
		int idSzuk, idOs;
		int co;
		cout << "Jaka ksiazke chcesz oddac? 1.Fantastyka 2.Popularnonaukowe" << endl;
		cin >> co;
		cout << "Wpisz jej id." << endl;
		cin >> idSzuk;
		cout << "Podaj id osoby oddajacej." << endl;
		cin >> idOs;
		if (co == 2)
		{
			zmienP(0, idSzuk);
		}
		else
			zmienF(0, idSzuk);
		przepiszDW(idOs);
		break;
	}
	case 4:
	{
		Wolny* wskaznikW;
		Dluznik* wskaznikD;
		int idSzuk;
		cout << "Jakiego czytelnika chcesz wyszukac" << endl;
		cout << "Podaj jego id" << endl;
		cin >> idSzuk;
		ifstream plik;
		int ilosc;
		plik.open("WolnyIlosc.txt");
		plik >> ilosc;
		Wolny* ktab = new Wolny[ilosc];
		for (int i = 0; i < ilosc; i++)
		{
			ktab[i].wczytaj();
			if (ktab[i].szukaj(idSzuk))
			{
				cout << " Szukana osoba: " << endl;
				wskaznikW = &ktab[i];
				wskaznikW->wypisz();
			}
			ktab[i + 1].getNr(i + 2);
		}
		ifstream plik2;
		int ilosc2;
		plik2.open("DluznikIlosc.txt");
		plik2 >> ilosc2;
		Dluznik* dtab = new Dluznik[ilosc2];
		for (int i = 0; i < ilosc2; i++)
		{
			dtab[i].wczytaj();
			if (dtab[i].szukaj(idSzuk))
			{
				cout << " Szukana osoba: " << endl;
				wskaznikD = &dtab[i];
				wskaznikD->wypisz();
			}
			dtab[i + 1].getNr(i + 2);
		}
		break;
	}
	case 5:
	{
		regex rAutor("[A-Z]{1}[a-z]*\\s{1}[a-zA-Z]*");
		regex rId("\\d+");
		regex rRok("\\d{4}");
		string tytul, autor;
		int rokWyd, id, rodzaj;
		bool wolna;
		cout << "To ksiazka fantastyczna czy popularno naukowa?" << endl;
		cout << "1.Fantastyka" << endl << "2.Popularnonaukowa" << endl;
		cin >> rodzaj;
		cout << "Podaj wszystike parametry " << endl;
		cout << "Tytul: " << endl;
		cin.ignore();
		getline(cin, tytul);
		cout << "Autor: " << endl;
		cin.ignore();
		getline(cin, autor);
		if (!regex_match(autor, rAutor))
		{
			cout << "Cos napisales zle, autor sklada siê z imienia i nazwiska, z duzej litery, oddzielony spacja!";
			exit(0);
		}
		cout << "Rok wydania: " << endl;
		cin >> rokWyd;
		if (!regex_match(to_string(rokWyd), rRok))
		{
			cout << "Cos napisales zle, rok wydania musi byc cyfra. Zakadam tez ze ksiazka zostala wydana w tym, badz poprzadnim tysiacleciu.";
			exit(0);
		}
		cout << "Identyfikator( musi byc unikatowy) :" << endl;
		cin >> id;
		if (!regex_match(to_string(id), rId))
		{
			cout << "Cos napisales zle, id musi byc cyfra, jedna lub wiecej!";
			exit(0);
		}
		cout << "Czy ten tytul jest wolny? 1- wolny, 0 zajety" << endl;
		cin >> wolna;
		string typ;
		if (rodzaj == 1)
		{
			cout << "Jaki to jest rodzaj fantastyki?";
			cin >> typ;
			Fantastyka f(tytul, autor, rokWyd, id, wolna, typ);
			wskaznik = &f;
			wskaznik->zapisz();
			fstream plik3;
			plik3.open("FantastykaIlosc.txt", ios::in);
			int zmienna;
			if (plik3.good())
			{
				plik3 >> zmienna;
				zmienna++;
				plik3.close();
			}
			else
			{
				cout << "Blad otwierania pliku!";
				plik3.close();
				exit(1);
			}
			plik3.open("FantastykaIlosc.txt", ios::out);
			plik3 << zmienna;
			plik3.close();
		}
		if (rodzaj == 2)
		{
			cout << "Jaka jest kategoria tej ksiazki?";
			cin >> typ;
			Popularnonaukowe p(tytul, autor, rokWyd, id, wolna, typ);
			wskaznik = &p;
			wskaznik->zapisz();
			fstream plik3;
			plik3.open("PopularnonaukoweIlosc.txt", ios::in);
			int zmienna;
			if (plik3.good())
			{
				plik3 >> zmienna;
				zmienna++;
				plik3.close();
			}
			else
			{
				cout << "Blad otwierania pliku!";
				plik3.close();
				exit(1);
			}
			plik3.open("PopularnonaukoweIlosc.txt", ios::out);
			plik3 << zmienna;
			plik3.close();
		}
		break;
	}
	/*default:
	{
		cout << "Opcji o takim numerze nie ma" << endl;
		break;
	}*/
	}
	}
	return 0;
}