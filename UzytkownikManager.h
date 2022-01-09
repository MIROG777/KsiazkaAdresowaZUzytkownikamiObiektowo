#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include "AdresatManager.h"
#include "PlikZAdresatami.h"

using namespace std;

class UzytkownikManager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
public:
    UzytkownikManager (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika=0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaUzytkownika(int idZalogowanegoUzytkownika);
    void wylogowanieUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami (Uzytkownik uzytkownik);
    void ustawIdZalogowanegoUzytkownika(int idUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();

private:

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin (string login);

};
#endif


