#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "UzytkownikManager.h"

using namespace std;

class AdresatManager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;


    void wyswietlDaneAdresata(Adresat adresat);
public:
    AdresatManager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodanieAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void wyswietlWszystkichAdresatow(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
private:

    int pobierzIdNowegoAdresata();
    string wczytajLinie();
};
#endif


