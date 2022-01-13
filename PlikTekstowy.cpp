#include "PlikTekstowy.h"


//using namespace std;


string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy::czyPlikJestPusty()
{
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}
void PlikTekstowy::wyczyscPlik()
{
    ofstream  plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::out | ios::trunc );
    plikTekstowy.close();

}
