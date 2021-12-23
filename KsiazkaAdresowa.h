#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;
class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;


public:
    KsiazkaAdresowa(string NazwaPlikuZUzytkownikami, string NazwaPlikuZAdresatami) : uzytkownikManager(NazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(NazwaPlikuZAdresatami)
    {
        adresatManager = NULL;
//wczytajUzytkownikowZPliku();
    };
    ~KsiazkaAdresowa()
    {
        delete adresatManager;
        adresatManager = NULL;
    }
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    void wylogowanieUzytkownika();
    void dodanieAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void wczytajMenu();
    char wybierzOpcjeZMenuGlownego();


};
#endif
