#include <iostream>

#include "KsiazkaAdresowa.h"


using namespace std;




int main()
{
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}

