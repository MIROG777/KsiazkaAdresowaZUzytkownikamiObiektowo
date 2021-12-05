#ifndef ADRESAT_H
#define ADRESAT_H


#include <iostream>
#include <fstream>

using namespace std;

class Adresat
{
    int id;
    int idOdUzytkownika;
    string imie;
    string nazwisko;
    string adres;
    string email;
    string numerTelefonu;

public:
    void ustawId(int noweId);
    void ustawIdOdUzytkownika(int noweIdOdUzytkownika);
    void ustawImie (string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawAdres (string nowyAdres);
    void ustawEmail (string nowyEmail);


    int pobierzId();
    int pobierzIdOdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzAdres();
    string pobierzEmail();
    string pobierzNumerTelefonu();
};
#endif
