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
    return uzytkownikManager.logowanieUzytkownika();
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
    uzytkownikManager.dodanieAdresata();
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    uzytkownikManager.wypiszWszystkichAdresatow();
}
void KsiazkaAdresowa::wczytajAdresatowZPliku()
{
    uzytkownikManager.wczytajAdresatowZPliku();
}

