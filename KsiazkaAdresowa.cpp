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
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager = new AdresatManager (NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
    //adresatManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku("Adresaci", uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    adresatManager->wyswietlWszystkichAdresatow(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}
/*void KsiazkaAdresowa::zmianaHaslaUzytkownika(vector <Uzytkownik> uzytkownicy, int idZalogowanegoUzytkownika)
{
    uzytkownikManager.zmianaHaslaUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
}*/
void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager;
    adresatManager = NULL;
}
 void KsiazkaAdresowa::dodanieAdresata(int idZalogowanegoUzytkownika)
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->dodanieAdresata(idZalogowanegoUzytkownika);
    }
    else
        {
        cout << "Aby dodac Adresata nalezy sie zalogowac"<<endl;
    system("PAUSE");
        }
}
char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;
    cin >> wybor;
    return wybor;
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->wyswietlWszystkichAdresatow(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::wczytajMenu()
{
    vector <Uzytkownik> uzytkownicy;
    char wybor;
    system("cls");
    while (true)
    {
        if (uzytkownikManager.czyUzytkownikJestZalogowany()==0)
        {
             system("cls");
            cout<<"<<<<<<MENU UZYTKOWNIKOW>>>>>>>"<<endl;
            cout<<"1. Rejestracja Uzytkownika " <<endl;
            cout<<"2. Logowanie Uzytkownika " <<endl;
            cout<<"9. Wyjdz"<<endl;
            cout<< "Wybierz opcje: ";
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            cout<<"<<<<<<MENU ADRESATOW>>>>>>>"<<endl;
            cout<<"1. Dodaj Adresata " <<endl;
            cout<<"2. Wyswietl wszystkich adresatow"<<endl;
            cout<<"9. Wyjdz"<<endl;
            cout<< "Wybierz opcje: ";
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                dodanieAdresata(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
                break;
            case '2':
                wyswietlWszystkichAdresatow();
                break;
            case '9':
                uzytkownikManager.ustawIdZalogowanegoUzytkownika(0);
                break;
            }
        }
    }
}


