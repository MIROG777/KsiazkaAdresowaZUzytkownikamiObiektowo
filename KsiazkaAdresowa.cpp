#include "KsiazkaAdresowa.h"
#include "UzytkownikManager.h"

using namespace std;


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
  uzytkownikManager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

