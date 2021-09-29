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

using namespace std;

class UzytkownikManager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
public:
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku(vector <Uzytkownik> uzytkownicy);
private:

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin (string login);
    PlikZUzytkownikami plikZUzytkownikami;
};
#endif


