#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;
class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager adresatManager;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami)
    {
        uzytkownikManager.wczytajUzytkownikowZPliku();
    };
    void wczytajAdresatowZPliku();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    void wylogowanieUzytkownika();
    void dodanieAdresata();
    void wypiszWszystkichAdresatow();


};
#endif
