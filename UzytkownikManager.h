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
    AdresatManager adresatManager;
public:
    UzytkownikManager (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    void wylogowanieUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wypiszWszystkichAdresatow();
    void dodanieAdresata();
    void wczytajAdresatowZPliku();
    void wczytajUzytkownikowZPliku();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami (Uzytkownik uzytkownik);
private:

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin (string login);
    int pobierzIdZalogowanegoUzytkownika();

};
#endif


