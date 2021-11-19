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
    adresatManager.dodanieAdresata();
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatManager.wypiszWszystkichAdresatow();
}
void KsiazkaAdresowa::wczytajAdresatowZPliku()
{
    adresatManager.wczytajAdresatowZPliku();
}

