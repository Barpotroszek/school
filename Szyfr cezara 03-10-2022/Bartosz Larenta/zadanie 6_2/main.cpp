#include <iostream>
#include <fstream>

using namespace std;
ofstream wynik;
ifstream dane;

string deszyfruj(string tekst, int klucz) {
    klucz %= 26;
    string odp="";
    for (int a = 0; a < tekst.length(); a++) {
        int temp = ((int)tekst[a])%65;
        temp -= klucz;
        if (temp < 0) temp += 26;
        temp %= 26;
        odp += (char)(temp + 65);
    }
    return odp;
}

int main()
{
    cout << "Otwieranie i tworzenie plików... ";

    dane.open("dane_6_2.txt");
    wynik.open("wynik_6_2.txt");
    if (!(dane.is_open() && wynik.is_open()))
    {
        cout << "Coœ posz³o nie tak...";
        return 1;
    }
    cout << " Pliki zostaly otwarte!\n Odczyt pliku\n";
    string tekst;
    int klucz;
    for (int i = 0; i < 2994; i++) {
        dane >> tekst >> klucz;
        wynik << deszyfruj(tekst, klucz) << '\n';
    }
    dane.close();
    wynik.close();
    cout << "\nProgram skonczyl prace\n";
    return 0;
}
