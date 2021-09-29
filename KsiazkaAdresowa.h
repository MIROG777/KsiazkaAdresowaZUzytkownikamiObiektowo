#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikManager.h"

using namespace std;
class KsiazkaAdresowa
{
    uzytkownikManager uzytkownikManager;


public:
   void rejestracjaUzytkownika();
   void wypiszWszystkichUzytkownikow();

};
#endif
