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
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->wyszukajAdresatowPoImieniu(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->wyszukajAdresatowPoNazwisku(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::usunWybranegoAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->usunWybranegoAdresata(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::edytujDaneAdresata()
{
    int idAdresataDoZmiany, liczbaPorzadkowaDoZmianyDanychAdresata=0;
    char wybor;
    cout<<"Podaj Id Adresata, ktorego dane chcesz zmienic"<<endl;
    idAdresataDoZmiany=stoi(metodyPomocnicze.wczytajLinie());
    //adresatManager.pobierzNumerPorzadkowyAdresataZWektora(idAdresataDoZmiany);

    while (true)
    {


        system("cls");
        cout<<"<<<<<<ZMIANA DANYCH ADRESATA>>>>>>>"<<endl;
        cout<<"1. Zmiana imienia " <<endl;
        cout<<"2. Zmiana nazwiska " <<endl;
        cout<<"3. Zmiana Emaila " <<endl;
        cout<<"4. Zmiana adresu " <<endl;
        cout<<"9. Wyjdz"<<endl;
        cout<< "Wybierz opcje: ";
        wybor = wybierzOpcjeZMenuGlownego();

        switch (wybor)
        {
        case '1':
            adresatManager->zmienImie(idAdresataDoZmiany);
            break;
        case '2':
            adresatManager->zmienNazwisko(idAdresataDoZmiany);
            break;
        case '3':
            adresatManager->zmienEmail(idAdresataDoZmiany);
            break;
        case '4':
            adresatManager->zmienAdres(idAdresataDoZmiany);
            break;
        case '9':
            wczytajMenu();
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }

}
void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikManager.zmianaHaslaUzytkownika(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
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
            cout<<"3. Wyszukaj adresatow po imieniu"<<endl;
            cout<<"4. Wyszukaj adresatow po nazwisku"<<endl;
            cout<<"5. Usun adresata"<<endl;
            cout<<"6. Edytuj dane adresata"<<endl;
            cout<<"7. Zmien haslo zalogowanego uzytkownika"<<endl;
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
            case '3':
                wyszukajAdresatowPoImieniu();
                break;
            case '4':
                wyszukajAdresatowPoNazwisku();
                break;
            case '5':
                usunWybranegoAdresata();
                break;
            case '6':
                edytujDaneAdresata();
                break;
            case '7':
                zmianaHaslaUzytkownika();
                break;
            case '9':
                uzytkownikManager.ustawIdZalogowanegoUzytkownika(0);
                break;
            }
        }
    }
}



