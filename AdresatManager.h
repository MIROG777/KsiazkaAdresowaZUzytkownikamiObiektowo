#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "UzytkownikManager.h"

using namespace std;

class AdresatManager
{
    int idWybranegoAdresata;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
public:
    void dodanieAdresata(int idZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZPliku(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami (Adresat adresat);
private:

    int pobierzIdNowegoAdresata();
};
#endif


