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
