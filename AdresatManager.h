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
    UzytkownikManager uzytkownikManager;
public:
    AdresatManager (string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
    void dodanieAdresata();
    Adresat podajDaneNowegoAdresata();
    void wypiszWszystkichAdresatow();
    void wczytajAdresatowZPliku();
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami (Adresat adresat);
private:

    int pobierzIdNowegoAdresata();
    int pobierzIdodUzytkownika();

};
#endif


