#include "PlikZAdresatami.h"

using namespace std;


bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);
    if (plikTekstowy.good()==true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if(czyPlikJestPusty())//czyPlikTekstowyJestPusty(plikTekstowy) == true
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy<<endl<<liniaZDanymiAdresata;
        }
        cout<< "Adresat dodany pomyslnie!"<<endl;
        plikTekstowy.close();
        return true;
    }
    else
    {
        return false;
    }
}
/*bool PlikZAdresatami::czyPlikTekstowyJestPusty(fstream &plikTekstowy)
{
    fstream plikTesktowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg()==0)
        return true;
    else
        return false;
}*/
string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata = MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId())+'|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdOdUzytkownika())+'|';
    liniaZDanymiAdresata += adresat.pobierzImie()+'|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    return liniaZDanymiAdresata;

}
vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami, idZalogowanegoUzytkownika );
            adresaci.push_back(adresat);
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
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdOdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

void PlikZAdresatami::zmienDaneAdresataWPliku(vector <Adresat>adresaci)
{
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    wyczyscPlik();
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);
    if (plikTekstowy.good()==true)
    {
        for(int i=0; i<adresaci.size(); i++)
        {
            liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresaci[i]);

                plikTekstowy << liniaZDanymiAdresata<<endl;

        }
        plikTekstowy.close();
    }
    else
    {
        cout<< "Nie udalo sie otworzyc pliku "<<pobierzNazwePliku()<<" i zapisac w nim danych.";
    }
}
/*void PlikZAdresatami::wyczyscPlik()
{
    ofstream  plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::trunc );
    plikTekstowy.close();

}*/


