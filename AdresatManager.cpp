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


void AdresatManager::wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika)

{
    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdOdUzytkownika()==idZalogowanegoUzytkownika)
        {
            cout << adresaci[i].pobierzIdOdUzytkownika() <<endl;
            cout << adresaci[i].pobierzId() <<endl;
            cout << adresaci[i].pobierzImie() <<endl;
            cout << adresaci[i].pobierzNazwisko() <<endl;
            cout << adresaci[i].pobierzAdres() <<endl;
            cout << adresaci[i].pobierzEmail() <<endl;
            cout << "Wyswietlono adresatow"<< endl;
            system("PAUSE");
        }
    }
}
void AdresatManager:: dodanieAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    //system("cls");
    cout << "<<<<<<<<<<<<DODAWANIE NOWEGO ADRESATA>>>>>>>>>>>>>"<<endl<<endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);
    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
    {
        cout <<" Nowy adresat zostal dodany"<<endl;
    }
    else
        {
        cout <<"Blad! Nie udalo sie dodac nowego adresata do pliku!"<<endl;
    system("PAUSE");
        }


}

Adresat AdresatManager::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
string imie, nazwisko,numerTelefonu,email,adres;
    adresat.ustawId(pobierzIdNowegoAdresata());
    cout<<"Nadano id adresatowi: "<<adresat.pobierzId()<<endl;
    adresat.ustawIdOdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout<<"Nadano id od uzytownika adresatowi: "<<adresat.pobierzIdOdUzytkownika()<<endl;

    cout << "Podaj imie: ";
    imie=metodyPomocnicze.wczytajLinie();
    imie=metodyPomocnicze.zamienPierwszaLitereNaWielkaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);
    cout << "Podaj nazwisko: ";
    nazwisko=metodyPomocnicze.wczytajLinie();
    nazwisko=metodyPomocnicze.zamienPierwszaLitereNaWielkaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);
    cout << "Podaj numer Telefonu: ";
    numerTelefonu=metodyPomocnicze.wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);
    cout << "Podaj email: ";
     email=metodyPomocnicze.wczytajLinie();
    adresat.ustawEmail(email);
    cout << "Podaj adres: ";
     adres=metodyPomocnicze.wczytajLinie();
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
/*void AdresatManager::wczytajAdresatowZPliku(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZPliku("Adresaci.txt", idZalogowanegoUzytkownika);
    /*cout <<"Ilosc Adresatow: "<< uzytkownicy.size()<<"Wypisanie Adresatow w metodzie wczytajAdresatowZPliku w klasie AdresatManager"<<endl;
    for (int i=0; i<=uzytkownicy.size();i++)
    {
        cout<< "Id Adresata "<<i<<" : "<< uzytkownicy[i].pobierzId()<<endl;
        cout<< "Login Adresata "<<i<<" : "<< uzytkownicy[i].pobierzLogin()<<endl;
        cout<< "Haslo Adresata "<<i<<" : "<< uzytkownicy[i].pobierzHaslo()<<endl;
    }*/


