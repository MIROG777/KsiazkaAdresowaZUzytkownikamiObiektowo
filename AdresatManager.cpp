#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "AdresatManager.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;


void AdresatManager::wypiszWszystkichAdresatow()
{
    for(int i=0; i<adresaci.size(); i++)
    {
        cout << adresaci[i].pobierzId() <<endl;
        cout << adresaci[i].pobierzIdOdUzytkownika() <<endl;
        cout << adresaci[i].pobierzImie() <<endl;
        cout << adresaci[i].pobierzNazwisko() <<endl;
        cout << adresaci[i].pobierzAdres() <<endl;
        cout << adresaci[i].pobierzEmail() <<endl;
    }
}
void AdresatManager:: dodanieAdresata()
{
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << endl << "Adresat zostal dodany pomyslnie" << endl << endl;
    system("pause");

}

Adresat AdresatManager::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(pobierzIdNowegoAdresata());
    adresat.ustawIdOdUzytkownika(pobierzIdodUzytkownika());
    string imie;
    string nazwisko;
    string adres;
    string email;

    cout << "Podaj imie: ";
    cin >> imie;
    adresat.ustawImie(imie);
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    adresat.ustawNazwisko(nazwisko);
    cout << "Podaj adres: ";
    cin.clear();
    cin.sync();
    cin.ignore();
    getline(cin,adres);
    adresat.ustawAdres(adres);
    return adresat;
}



int AdresatManager::pobierzIdNowegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}
int AdresatManager::pobierzIdodUzytkownika()
{
    return uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}
string AdresatManager::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata="";
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdOdUzytkownika())+'|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId())+'|';
    liniaZDanymiAdresata += adresat.pobierzImie()+'|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko()+'|';
    liniaZDanymiAdresata += adresat.pobierzAdres()+'|';
    liniaZDanymiAdresata += adresat.pobierzEmail()+'|';

    return liniaZDanymiAdresata;
}
void AdresatManager::wczytajAdresatowZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZPliku();
    /*cout <<"Ilosc Adresatow: "<< uzytkownicy.size()<<"Wypisanie Adresatow w metodzie wczytajAdresatowZPliku w klasie AdresatManager"<<endl;
    for (int i=0; i<=uzytkownicy.size();i++)
    {
        cout<< "Id Adresata "<<i<<" : "<< uzytkownicy[i].pobierzId()<<endl;
        cout<< "Login Adresata "<<i<<" : "<< uzytkownicy[i].pobierzLogin()<<endl;
        cout<< "Haslo Adresata "<<i<<" : "<< uzytkownicy[i].pobierzHaslo()<<endl;
    }*/
}

