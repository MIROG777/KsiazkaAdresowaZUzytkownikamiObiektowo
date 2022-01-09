#include "PlikZUzytkownikami.h"

using namespace std;


void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(vector <Uzytkownik> uzytkownicy)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    wyczyscPlik();
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);
    if (plikTekstowy.good()==true)
    {
        for(int i=0; i<uzytkownicy.size(); i++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownicy[i]);

            if(czyPlikJestPusty() == true)
            {
                plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy<<endl<<liniaZDanymiUzytkownika;
            }
        }
        plikTekstowy.close();
    }
    else
    {
        cout<< "Nie udalo sie otworzyc pliku "<<pobierzNazwePliku()<<" i zapisac w nim danych.";
    }
}
/*bool PlikZUzytkownikami::czyPlikTekstowyJestPusty(fstream &plikTekstowy)
{
    fstream plikTesktowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg()==0)
        return true;
    else
        return false;
}*/
string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{

    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika = MetodyPomocnicze::konwersjaIntNaString(uzytkownik.pobierzId())+'|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin()+'|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';
    return liniaZDanymiUzytkownika;

}
vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    fstream plikTekstowy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            /* cout << "Id uzytkiwnika przy wczytywaniu z pliku "<<uzytkownik.pobierzId()<<endl;
             cout << "Login uzytkiwnika przy wczytywaniu z pliku "<<uzytkownik.pobierzLogin()<<endl;
             cout << "Haslo uzytkiwnika przy wczytywaniu z pliku "<<uzytkownik.pobierzHaslo()<<endl;*/
            uzytkownicy.push_back(uzytkownik);
        }

    }
    plikTekstowy.close();
    return uzytkownicy;
}
Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                //cout << "Id uzytkownika przy pobieraniu danych uzytkownika "<< uzytkownik.pobierzId()<<endl;
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                //cout << "Login uzytkownika przy pobieraniu danych uzytkownika "<< uzytkownik.pobierzLogin()<<endl;
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                //cout << "haslo uzytkownika przy pobieraniu danych uzytkownika "<< uzytkownik.pobierzHaslo()<<endl;
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}
/*void PlikZUzytkownikami::wyczyscPlik()
{
    ofstream  plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::out | ios::trunc );
    plikTekstowy.close();

}*/


