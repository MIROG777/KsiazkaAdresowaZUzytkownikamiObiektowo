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


void AdresatManager::wypiszWszystkichAdresatow(int idZalogowanegoUzytkownika)
{
    for(int i=0; i<adresaci.size(); i++)
    {
            cout << adresaci[i].pobierzIdOdUzytkownika() <<endl;
            cout << adresaci[i].pobierzId() <<endl;
            cout << adresaci[i].pobierzImie() <<endl;
            cout << adresaci[i].pobierzNazwisko() <<endl;
            cout << adresaci[i].pobierzAdres() <<endl;
            cout << adresaci[i].pobierzEmail() <<endl;
    }
}
void AdresatManager:: dodanieAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    system("pause");

}

Adresat AdresatManager::podajDaneNowegoAdresata( int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.ustawId(pobierzIdNowegoAdresata());
    adresat.ustawIdOdUzytkownika(idZalogowanegoUzytkownika);
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
    cin >> email;
    adresat.ustawEmail(email);
    return adresat;
}



int AdresatManager::pobierzIdNowegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
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
void AdresatManager::wczytajAdresatowZPliku(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZPliku("Adresaci", idZalogowanegoUzytkownika);
    /*cout <<"Ilosc Adresatow: "<< uzytkownicy.size()<<"Wypisanie Adresatow w metodzie wczytajAdresatowZPliku w klasie AdresatManager"<<endl;
    for (int i=0; i<=uzytkownicy.size();i++)
    {
        cout<< "Id Adresata "<<i<<" : "<< uzytkownicy[i].pobierzId()<<endl;
        cout<< "Login Adresata "<<i<<" : "<< uzytkownicy[i].pobierzLogin()<<endl;
        cout<< "Haslo Adresata "<<i<<" : "<< uzytkownicy[i].pobierzHaslo()<<endl;
    }*/
}

