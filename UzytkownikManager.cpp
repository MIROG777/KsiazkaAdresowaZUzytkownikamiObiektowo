#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "UzytkownikManager.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"

using namespace std;

void UzytkownikManager::wypiszWszystkichUzytkownikow()
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
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwersjaIntNaString(uzytkownik.pobierzId())+'|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin()+'|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo()+'|';

    return liniaZDanymiUzytkownika;
}
void UzytkownikManager::logowanieUzytkownika()
{
    string login = "", haslo = "";
    int iloscProb = 0;
    bool zmiennaInformujacaOZalogowaniu=0;


    while(iloscProb!=3 && zmiennaInformujacaOZalogowaniu==0)
    {
        cout << "Podaj Login: ";
        cin >> login;
        cout << "Podaj Haslo: ";
        cin >> haslo;
        for (int i = 0; i < uzytkownicy.size(); i++)
        {
            if (login == uzytkownicy[i].pobierzLogin() && haslo==uzytkownicy[i].pobierzHaslo())
            {

                ustawIdZalogowanegoUzytkownika(uzytkownicy[i].pobierzId());
                zmiennaInformujacaOZalogowaniu=1;
            }
        }
        if ( zmiennaInformujacaOZalogowaniu == 0)
        {
            iloscProb++;
            cout << "Bledne dane. Proba "<<iloscProb<< " z 3."<<endl;
        }

    }
    if (iloscProb==3)
    {
        cout << "Nie udalo sie zalogowac Uzytkownika"<<endl;
    }
}
void UzytkownikManager::zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika)
{
    string stareHaslo, noweHaslo, noweHasloPowtorzenie;
    int iloscProb=0,zmiennaPorzadkowZalogowanegoUzytkownika;
    bool zmiennaInformujacaOZmianieHasla=0;
    if (idZalogowanegoUzytkownika!=0)
    {
        for(int i=0; i<=uzytkownicy.size(); i++)
        {
            if (uzytkownicy[i].pobierzId()==idZalogowanegoUzytkownika)
            {
                zmiennaPorzadkowZalogowanegoUzytkownika=i;
                break;
            }
        }
        while(iloscProb!=3 || zmiennaInformujacaOZmianieHasla==0)
        {
            if (iloscProb==3)
            {
                break;
            }
            cout << "Podaj stare haslo: ";
            cin >> stareHaslo;
            cout << "Podaj nowe haslo: ";
            cin >> noweHaslo;
            cout << "Podaj ponownie nowe haslo: ";
            cin >> noweHasloPowtorzenie;

            if (uzytkownicy[zmiennaPorzadkowZalogowanegoUzytkownika].pobierzId()==idZalogowanegoUzytkownika)
            {
                if (stareHaslo==uzytkownicy[zmiennaPorzadkowZalogowanegoUzytkownika].pobierzHaslo())
                {
                    if(noweHaslo==noweHasloPowtorzenie)
                    {
                        uzytkownicy[zmiennaPorzadkowZalogowanegoUzytkownika].ustawHaslo(noweHaslo);
                        cout << "Haslo zostalo zmienione"<<endl;
                        plikZUzytkownikami.wyczyscPlik();
                        plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownicy);
                        zmiennaInformujacaOZmianieHasla=1;
                        break;

                    }
                    else
                    {
                        cout << "Hasla nie sa identyczne"<<endl;
                        iloscProb++;
                        cout << "Proba "<<iloscProb<<" z 3"<<endl;

                    }
                }
                else
                {
                    cout << "Podano zle haslo uzytkownika"<<endl;
                    iloscProb++;
                    cout << "Proba "<<iloscProb<<" z 3"<<endl;



                }
            }
        }
        if(iloscProb==3 &&zmiennaInformujacaOZmianieHasla==0)
        {
            cout << "Nie udalo sie zmienic hasla"<<endl;
        }
    }
    else
    {
        cout<<"Uzytkownik nie jest zalogowany!"<<endl;
    }



}
void UzytkownikManager::wylogowanieUzytkownika()
{
    char potwierdzenie;
    bool zmiennaZamykajacaWylogowanie=0;

    while (zmiennaZamykajacaWylogowanie==0)
    {
        cout << "Czy na pewno chcesz sie wylogowac?(t-tak, n - nie): ";
        cin >> potwierdzenie;
        if (potwierdzenie=='t')
        {
            idZalogowanegoUzytkownika=0;
            cout <<"Wylogowano uzytkownika"<<endl;
            zmiennaZamykajacaWylogowanie=1;
        }
        else if (potwierdzenie=='n')
        {
            cout << "Nie wylogowano uzytkownika"<<endl;
            break;
        }
        else
        {
            cout << "Nie wybrales t albo n"<<endl;
        }
    }
}

void UzytkownikManager::ustawIdZalogowanegoUzytkownika(int idUzytkownika)
{
    idZalogowanegoUzytkownika=idUzytkownika;
}
int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
bool czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}



