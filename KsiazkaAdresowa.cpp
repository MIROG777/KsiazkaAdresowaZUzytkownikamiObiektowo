#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"

using namespace std;


KsiazkaAdresowa::KsiazkaAdresowa()
{
    UzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
  UzytkownikManager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    UzytkownikManager.wypiszWszystkichUzytkownikow;
}

