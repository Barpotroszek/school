#include <iostream>

using namespace std;

struct osoba {
    string imie;
    string nazwisko;
};

struct szpital{
    osoba lekarz;
    string spec;
    osoba pacjenci[3];
};

int main()
{
    szpital pnowak;
    pnowak.lekarz.imie = "Piotr";
    pnowak.lekarz.nazwisko = "Nowak";
    pnowak.spec = "Neurologia";

    osoba JKowalski;
    JKowalski.imie = "Jan";
    JKowalski.nazwisko = "Kowalski";

    osoba Piotrowski;
    Piotrowski.imie = "Grzegorz";
    Piotrowski.nazwisko = "Piotrowski";

    osoba Kasztelan;
    Kasztelan.imie = "Ryszard";
    Kasztelan.nazwisko = "Kasztelan";

    osoba lista_pacjentow[3] = {JKowalski, Piotrowski, Kasztelan};
    for(int i=0; i<3; i++) pnowak.pacjenci[i] = lista_pacjentow[i];

    cout << "Doktor " << pnowak.lekarz.imie << " " << pnowak.lekarz.nazwisko<< "; jego specjalizacja: " << pnowak.spec << "; Jego pacjenci:";
    for(int i=0; i<3; i++) cout << "\n -"<< pnowak.pacjenci[i].imie << " " << pnowak.pacjenci[i].nazwisko;
}
