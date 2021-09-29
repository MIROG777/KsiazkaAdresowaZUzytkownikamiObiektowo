#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "UzytkownikManager.h"

using namespace std;

void UzytkoiwnikMabager::wypiszWszystkichUzytkownikow()
{
for(int i=0; i<uzytkownicy.size(); i++)
{
    cout << uzytkownicy[i].pobierzId() <<endl;
    cout << uzytkownicy[i].pobierzLogin() <<endl;
    cout << uzytkownicy[i].pobierzHaslo() <<endl;
}
}
void UzytkownikManager:: rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}
bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for(int i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        return false;
    }
}
Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    {
        string haslo;
        cout << "Podaj haslo: ";
        cin >> haslo;
        uzytkownik.ustawHaslo(haslo);

        return uzytkownik;
    }
}
int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}



string UzytkownikManager::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika="";
    liniaZDanymiUzytkownika += zamienIntNaString(uzytkownik.pobierzId()+'|');
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin()+'|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo()+'|';

    return liniaZDanymiUzytkownika;
}
void UzytkownikManager::wczytajUzytkownikowZPliku()
{
PlikZUzytkownikami.wczytajUzytkownikowZPliku(uzytkownicy);
}


