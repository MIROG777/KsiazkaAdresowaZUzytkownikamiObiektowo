#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;
class PlikZAdresatami : public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;
    fstream plikTekstowy;


public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    bool dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void zmienDaneAdresataWPliku(vector <Adresat>adresaci);
    //void wyczyscPlik();

private:
    //bool czyPlikTekstowyJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami, int idZalogowanegoUzytkownika);


};
#endif
