#include <iostream>
#include <fstream>
#include <vector>


#include "MetodyPomocnicze.h"

using namespace std;

string MetodyPomocnicze::zamienIntNaString(int liczba)
{
   ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
