#include <iostream>

#include "KsiazkaAdresowa.h"


using namespace std;




int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    cout << "Wczytywanie menu"<<endl;
    system("PAUSE");
    ksiazkaAdresowa.wczytajMenu();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.dodanieAdresata();
    //ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}

