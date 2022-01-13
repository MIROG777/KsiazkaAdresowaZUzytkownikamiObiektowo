#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Adresat.h"
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
            cout << "Id od Uzytkownika: "<<adresaci[i].pobierzIdOdUzytkownika() <<endl;
            cout << "Id: "<<adresaci[i].pobierzId() <<endl;
            cout << "Imie: "<<adresaci[i].pobierzImie() <<endl;
            cout << "Nazwisko: "<<adresaci[i].pobierzNazwisko() <<endl;
            cout << "Numer Telefonu: "<<adresaci[i].pobierzNumerTelefonu() <<endl;
            cout << "Adres: "<<adresaci[i].pobierzAdres() <<endl;
            cout << "Email: "<<adresaci[i].pobierzEmail() <<endl;

        }
    }
    cout << "Wyswietlono adresatow"<< endl;
    system("PAUSE");
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
    adresat.ustawIdOdUzytkownika(idZalogowanegoUzytkownika);
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
    {
        cout << "Nie ma zapisanych adresatow"<<endl;
        system ("PAUSE");
        return 1;
    }
    else
    {
        cout << "Id ostatniego adresata w wektorze: "<<adresaci[adresaci.size()-1].pobierzId()<<endl;
        system("PAUSE");
        return adresaci[adresaci.size()-1].pobierzId() + 1;
    }
}
string AdresatManager::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata="";
    liniaZDanymiAdresata = MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId())+'|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdOdUzytkownika())+'|';
    liniaZDanymiAdresata += adresat.pobierzImie()+'|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko()+'|';
    liniaZDanymiAdresata += adresat.pobierzAdres()+'|';
    liniaZDanymiAdresata += adresat.pobierzEmail()+'|';

    return liniaZDanymiAdresata;
}
void AdresatManager::wyszukajAdresatowPoImieniu(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    string imie;
    cout<<"Podaj imie adresatow ktorych chcesz wyszukac: ";
    imie=metodyPomocnicze.wczytajLinie();
    imie =metodyPomocnicze.zamienPierwszaLitereNaWielkaAPozostaleNaMale(imie);
    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzImie()==imie && adresaci[i].pobierzIdOdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            cout<<endl<<endl<<"Id: "<<adresaci[i].pobierzId()<<endl;
            cout<<"Id Uzytkownika: "<<adresaci[i].pobierzIdOdUzytkownika()<<endl;
            cout<<"Imie: "<<adresaci[i].pobierzImie()<<endl;
            cout<<"Nazwisko: "<<adresaci[i].pobierzNazwisko()<<endl;
            cout<<"Numer Telefonu: "<<adresaci[i].pobierzNumerTelefonu()<<endl;
            cout<<"Email: "<<adresaci[i].pobierzEmail()<<endl;
            cout<<"Adres: "<<adresaci[i].pobierzAdres()<<endl;

        }
    }
    system("PAUSE");
}
void AdresatManager::wyszukajAdresatowPoNazwisku(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    string nazwisko;
    cout<<"Podaj nazwisko adresatow ktorych chcesz wyszukac: ";
    nazwisko=metodyPomocnicze.wczytajLinie();
    nazwisko = metodyPomocnicze.zamienPierwszaLitereNaWielkaAPozostaleNaMale(nazwisko);
    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzNazwisko()==nazwisko && adresaci[i].pobierzIdOdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            cout<<endl<<endl<<"Id: "<<adresaci[i].pobierzId()<<endl;
            cout<<"Id Uzytkownika: "<<adresaci[i].pobierzIdOdUzytkownika()<<endl;
            cout<<"Imie: "<<adresaci[i].pobierzImie()<<endl;
            cout<<"Nazwisko: "<<adresaci[i].pobierzNazwisko()<<endl;
            cout<<"Numer Telefonu: "<<adresaci[i].pobierzNumerTelefonu()<<endl;
            cout<<"Email: "<<adresaci[i].pobierzEmail()<<endl;
            cout<<"Adres: "<<adresaci[i].pobierzAdres()<<endl;

        }
    }
    system("PAUSE");
}
void AdresatManager::usunWybranegoAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    int idDoUsunieciaAdresata, liczbaPorzadkowaDlaUsunieciaAdresata=0;
    char potwierdzenie;
    cout<< "Podaj numer ID Adresata do usuniecia: ";
    //idDoUsunieciaAdresata = atoi(wczytajLinie()); << nie dziala
    cin >> idDoUsunieciaAdresata;
    cout <<"Czy na pewno chcesz usunac adresata?('t' na tak, 'n' na nie): ";
    cin >> potwierdzenie;
    if (potwierdzenie=='t')
    {
        if (adresaci.size()==1)
        {
            adresaci.clear();
            plikZAdresatami.zmienDaneAdresataWPliku(adresaci);
        }
        else if(adresaci.size()>1)
            for(int i=0; i<=adresaci.size(); i++)
            {
                if(adresaci[i].pobierzIdOdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA && adresaci[i].pobierzId()==idDoUsunieciaAdresata)

                {

                    liczbaPorzadkowaDlaUsunieciaAdresata=i;
                    adresaci.erase(adresaci.begin()+liczbaPorzadkowaDlaUsunieciaAdresata);
                    plikZAdresatami.zmienDaneAdresataWPliku(adresaci);
                }
            }


        // sort(adresaci.id.begin(), adresaci.id.end());
    }
}
void  AdresatManager::zmienImie(int idDoZmainyDanychAdresata)
{
    int liczbaPorzadkowaDoZmianyDanychAdresata=0;
    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId()==idDoZmainyDanychAdresata)
        {
            liczbaPorzadkowaDoZmianyDanychAdresata=i;
        }
    }

    cout << "Podaj nowe imie: ";
    adresaci[liczbaPorzadkowaDoZmianyDanychAdresata].ustawImie(metodyPomocnicze.zamienPierwszaLitereNaWielkaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));
    plikZAdresatami.zmienDaneAdresataWPliku(adresaci);
}
void  AdresatManager::zmienNazwisko(int idDoZmainyDanychAdresata)
{
    int liczbaPorzadkowaDoZmianyDanychAdresata=0;

    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId()==idDoZmainyDanychAdresata)
        {
            liczbaPorzadkowaDoZmianyDanychAdresata=i;
        }
    }

    cout << "Podaj nowe nazwisko: ";
    adresaci[liczbaPorzadkowaDoZmianyDanychAdresata].ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaWielkaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));
    plikZAdresatami.zmienDaneAdresataWPliku(adresaci);
}
void  AdresatManager::zmienEmail(int idDoZmainyDanychAdresata)
{
    int liczbaPorzadkowaDoZmianyDanychAdresata=0;

    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId()==idDoZmainyDanychAdresata)
        {
            liczbaPorzadkowaDoZmianyDanychAdresata=i;
        }
    }

    cout << "Podaj nowy email: ";
    adresaci[liczbaPorzadkowaDoZmianyDanychAdresata].ustawEmail(metodyPomocnicze.wczytajLinie());
    plikZAdresatami.zmienDaneAdresataWPliku(adresaci);
}
void  AdresatManager::zmienAdres(int idDoZmainyDanychAdresata)
{
    int liczbaPorzadkowaDoZmianyDanychAdresata=0;

    for(int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId()==idDoZmainyDanychAdresata)
        {
            liczbaPorzadkowaDoZmianyDanychAdresata=i;
        }
    }

    cout << "Podaj nowy adres: ";
    adresaci[liczbaPorzadkowaDoZmianyDanychAdresata].ustawAdres(metodyPomocnicze.wczytajLinie());
    plikZAdresatami.zmienDaneAdresataWPliku(adresaci);
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


