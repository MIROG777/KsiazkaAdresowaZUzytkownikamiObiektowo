#include <iostream>
#include <fstream>
#include <vector>


#include "MetodyPomocnicze.h"

using namespace std;

string MetodyPomocnicze::konwersjaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
string MetodyPomocnicze::wczytajLinie()
{
    cin.clear();
    cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
string MetodyPomocnicze::zamienPierwszaLitereNaWielkaAPozostaleNaMale(string tekst)
{
    for(int i=0; i<=tekst.length()-1; i++)
    {

        if(i==0)
        {
            if(tekst[i]>=97)
            {
                tekst[i]=tekst[i]-(97-65);
            }
        }
        else if(i>0)
        {
            if(tekst[i]<97)
            {
                tekst[i]=tekst[i]+(97-65);
            }
        }
    }
    return tekst;

}
