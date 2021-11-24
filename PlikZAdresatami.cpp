#include "PlikZAdresatami.h"

using namespace std;


void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::app);
    if (plikTekstowy.good()==true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if(czyPlikTekstowyJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy<<endl<<liniaZDanymiAdresata;
        }
        plikTekstowy.close();
    }
    else
    {
        cout<< "Nie udalo sie otworzyc pliku "<<nazwaPlikuZAdresatami<<" i zapisac w nim danych.";
    }
}
bool PlikZAdresatami::czyPlikTekstowyJestPusty(fstream &plikTekstowy)
{
    fstream plikTesktowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg()==0)
        return true;
    else
        return false;
}
string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{

    string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata = MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdOdUzytkownika())+'|';
    liniaZDanymiAdresata = MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId())+'|';
    liniaZDanymiAdresata += adresat.pobierzImie()+'|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    return liniaZDanymiAdresata;

}
vector <Adresat> PlikZAdresatami::wczytajAdresatowZPliku(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";

    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami, idZalogowanegoUzytkownika );
            if (adresat.pobierzIdOdUzytkownika()==idZalogowanegoUzytkownika)
            {
                adresaci.push_back(adresat);
            }
        }

    }
    plikTekstowy.close();
    return adresaci;
}
Adresat PlikZAdresatami::pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami, int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIdOdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


