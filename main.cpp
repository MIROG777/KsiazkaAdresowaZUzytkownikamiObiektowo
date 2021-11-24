#include <iostream>

#include "KsiazkaAdresowa.h"


using namespace std;




int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
        ksiazkaAdresowa.wczytajAdresatowZPliku();
    ksiazkaAdresowa.dodanieAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.zmianaHaslaUzytkownika();
    ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}

