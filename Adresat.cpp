#include "Adresat.h"

void Adresat::ustawId(int noweId)
{
    if(noweId >=0)
    {
        id=noweId;
    }
}
void Adresat::ustawIdOdUzytkownika(int noweIdOdUzytkownika)
{
    if(noweIdOdUzytkownika >=0)
    {
        id=noweIdOdUzytkownika;
    }
}
void Adresat::ustawImie (string noweImie)
{
    imie=noweImie;
}
void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko=noweNazwisko;
}
void Adresat::ustawNumerTelefonu (string nowyNumerTelefonu)
{
    numerTelefonu=nowyNumerTelefonu;
}
void Adresat::ustawAdres(string nowyAdres)
{
    adres=nowyAdres;
}
void Adresat::ustawEmail(string nowyEmail)
{
    email=nowyEmail;
}

int Adresat::pobierzId()
{
    return id;
}
int Adresat::pobierzIdOdUzytkownika()
{
    return idOdUzytkownika;
}
string Adresat::pobierzImie()
{
    return imie;
}
string Adresat::pobierzNazwisko()
{
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu()
{
    return numerTelefonu;
}
string Adresat::pobierzAdres()
{
    return adres;
}
string Adresat::pobierzEmail()
{
    return email;
}
