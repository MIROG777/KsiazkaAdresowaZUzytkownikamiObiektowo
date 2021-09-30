#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "UZytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;
class PlikZUzytkownikami
{
    const string nazwaPlikuZUzytkownikami;
    //fstream plikTekstowy;


public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami("Uzytkownicy.txt"){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    vector wczytajUzytkownikowZPliku();

private:
    bool czyPlikTekstowyJestPusty();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

};
#endif
