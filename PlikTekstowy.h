#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {

    const string NAZWA_PLIKU;


public:

    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {};
    string pobierzNazwePliku();
    bool czyPlikJestPusty();
    void wyczyscPlik();

};
#endif
