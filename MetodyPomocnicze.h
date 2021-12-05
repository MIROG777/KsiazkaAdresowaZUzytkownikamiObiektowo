#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

#include "UZytkownik.h"

using namespace std;
class MetodyPomocnicze
{

public:
    string wczytajLinie();
    static string konwersjaIntNaString(int liczba);
    string zamienPierwszaLitereNaWielkaAPozostaleNaMale(string tekst);
};
#endif
