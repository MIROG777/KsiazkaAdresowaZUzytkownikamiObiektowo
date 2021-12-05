#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;
class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    //fstream plikTekstowy;


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
    bool dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogoeanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

private:
    bool czyPlikTekstowyJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami, int idZalogowanegoUzytkownika);

};
#endif
