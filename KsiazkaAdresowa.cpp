#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}
int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
}
void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikManager.zmianaHaslaUzytkownika();
}
void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
}
void KsiazkaAdresowa::dodanieAdresata()
{
    adresatManager.dodanieAdresata(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatManager.wypiszWszystkichAdresatow(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}
void KsiazkaAdresowa::wczytajAdresatowZPliku()
{
    adresatManager.wczytajAdresatowZPliku("Adresaci", uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}

